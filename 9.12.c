#include <stdio.h>
int main()
{   int x,y,i,p,j;
    int min=10;
    int count[3];//�����¥�� 
    int num[3];//��λʱ��� 
    int kk[3];//Ҫȥ��¥�� 
    int time[5];//ʱ���� 
    printf("����������ڲ���\n")�� 
    scanf("%d",&j)
    printf("��һ�˵ڶ��˵����˷ֱ��������ڲ���\n");
    for(i=0;i<3;i++){
	scanf("%d",&x);	
	count[i]=x;
}
    printf("�ֱ�����Ҫȥ����\n");
     for(i=0;i<3;i++){
	scanf("%d",&x);	
	kk[i]=x;
}
    for(i=0;i<3;i++){
    num[i]=abs(count[i]-j);	
}
    for(i=0;i<3;i++){
    	if(num[i]<min){
    		min=num[i];p=i;
		}
	} 
	printf("%d 0 0\n",j);
	printf("%d %d 1\n",count[p],num[p]);
	printf("%d %d 0\n",kk[p],time)
   
}
