
/****************************************************************************************
*	
*	纯滞后系统的大林控制算法
*
*		早在1968年，美国IBM公司的大林（Dahlin）就提出了一种不同于常规PID控制规律
*	的新型算法，即大林算法。该算法的最大特点是将期望的闭环响应设计成一阶惯性加纯
*	延迟，然后反过来得到满足这种闭环响应的控制器。
*
*	注：因算法本身的复杂度问题，该程序未整定完全，具体参数和计算方式请根据实际情况定义！
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define	 Kp		1.0
#define  Ki		0.50
#define	 Kd		0.10

#define  ts 	0.5

//构造结构体
struct pid_data
{
	float rin;			
	float yout;	
	float err;			
	float err_last;		
	float integral;		
	float u;
};

//定义结构体类型
typedef struct pid_data		_pid_t;

//机构体初始化
struct pid_data* pid_init(float rin, float yout,
float err, float err_last, float u)
{
	struct pid_data* tset = malloc(sizeof(struct pid_data));

	tset->rin 		= rin;
	tset->yout		= yout;
	tset->err 		= err;		
	tset->err_last 	= err_last;
	tset->u			= u;

	return tset;
}

//The Increment PID Control Algorithm
float pid_calc(_pid_t* pid)
{
	//wait
	float err_1,err_2,err_3;
	pid->err = pid->rin - pid->yout;

	int M=1;
	if (M==1)
	{
		pid->u = (num_1*err + num_2*err_1 + num_3*err_2 + num_4*err_3
				 -den_3*u_1 - den_4*u_2 - den_5*u_3 - den_6*u_4 - den_7*u_5)/den_2;
	}
	else if (M == 2)
	{
		pid->integral += pid->err;
		pid->u = Kp*pid->err + Kd*(pid->err - pid->err_last)/ts + Ki*pid->integral;
	}

	pid->err_last = pid->err;
	pid->yout = pid->u;

	return pid->yout;
}

int main()
{
	printf("System test begin \n");

	_pid_t* tset;
	int count = 0;
	float real = 0;

	tset = pid_init(23,0,0,0,0);

	while(count < 100)
	{
		real = pid_calc(tset);
		printf("%d > %f\n", count, real);
		count++;
	}

	free(tset);
	return 0;
}