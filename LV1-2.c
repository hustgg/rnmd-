#include <stdio.h>
int main()

{   int num;
    printf("输入有几人乘坐电梯\n");
	scanf("%d",&num);
    switch(num){
	case 1:
	{
	int a,b,c;
	printf("请分别输入等候电梯层数 电梯要到第几层 电梯现在所在层数\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("%d 0 0\n",c);
	//在第几层 开始运行 有几个人 
	int d=a-c;
	int abs_d=abs(d);
	printf("%d %d 1\n",a, abs_d);
	//在第几层 运行多久 有几个人 
	int f=a-b;
	int abs_f=abs(f);
	int e=abs_d+abs_f;
	printf("%d %d 0\n",b, e);
	break;}
    case 2:
	{
	int a,b,c,A,B;
	printf("输入现在电梯在第几层\n");
	scanf("%d",&c) ;
	printf("请第一个人分别输入等候电梯层数 电梯要到第几层\n");
	scanf("%d %d",&a,&b);
	printf("请第二个人分别输入等候电梯层数 电梯要到第几层\n");
	scanf("%d %d",&A,&B);
	printf("%d 0 0\n",c);
	//在第几层 开始运行 有几个人
	if(abs(c-a)<abs(c-A)) {
	printf("%d %d 1\n",a,abs(c-a));
	printf("%d %d 0\n",b,abs(c-a)+abs(a-b));
	printf("%d %d 1\n",A,abs(c-a)+abs(a-b)+abs(b-A));
	printf("%d %d 0\n",B,abs(c-a)+abs(a-b)+abs(b-A)+abs(A-B));
	
	}
	else{
	printf("%d %d 1\n",A,abs(c-A));
	printf("%d %d 0\n",B,abs(c-A)+abs(A-B));
	printf("%d %d 1\n",a,abs(c-A)+abs(A-B)+abs(a-B));
	printf("%d %d 0\n",b,abs(c-A)+abs(A-B)+abs(a-B)+abs(a-b));
	}
	break;}
	default:printf("抱歉电梯超载了\n");
	}
}
