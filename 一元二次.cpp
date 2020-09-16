#include<stdio.h>
#include<math.h>
void m(float a,float b,float c)
{
	double x1,x2;
	x1=(-b-sqrt(b*b-4*a*c))/(2*a);
	x2=(-b+sqrt(b*b-4*a*c))/(2*a);
	printf("方程组有两个实根：x1=%2.2f,x2=%2.2f\n",x1,x2);
}
 
void m1(float a,float b,float c)
{
	double x;
	x=(-b)/2*a;
	printf("方程有一个实根：x1=x2=%2.2f",x);
}
 
int main()
{
	float a,b,c;
	double sum;
	printf("请输入a,b,c系数：");
	scanf("%f%f%f",&a,&b,&c);
	printf("方程为：%2.2fx^2+%2.2fx+%2.2f=0\n",a,b,c);
    sum=b*b-4*a*c;
	if(sum>0)
		m(a,b,c);
	else if(sum==0)
		m1(a,b,c);
	else printf("方程无解！！！\n");
}
