#include <stdio.h>
int main()

{   int num;
    printf("�����м��˳�������\n");
	scanf("%d",&num);
    switch(num){
	case 1:
	{
	int a,b,c;
	printf("��ֱ�����Ⱥ���ݲ��� ����Ҫ���ڼ��� �����������ڲ���\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("%d 0 0\n",c);
	//�ڵڼ��� ��ʼ���� �м����� 
	int d=a-c;
	int abs_d=abs(d);
	printf("%d %d 1\n",a, abs_d);
	//�ڵڼ��� ���ж�� �м����� 
	int f=a-b;
	int abs_f=abs(f);
	int e=abs_d+abs_f;
	printf("%d %d 0\n",b, e);
	break;}
    case 2:
	{
	int a,b,c,A,B;
	printf("�������ڵ����ڵڼ���\n");
	scanf("%d",&c) ;
	printf("���һ���˷ֱ�����Ⱥ���ݲ��� ����Ҫ���ڼ���\n");
	scanf("%d %d",&a,&b);
	printf("��ڶ����˷ֱ�����Ⱥ���ݲ��� ����Ҫ���ڼ���\n");
	scanf("%d %d",&A,&B);
	printf("%d 0 0\n",c);
	//�ڵڼ��� ��ʼ���� �м�����
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
	default:printf("��Ǹ���ݳ�����\n");
	}
}
