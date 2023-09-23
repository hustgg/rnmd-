#include <stdio.h>
int main()
{   int x,y,i,p,j;
    int min=10;
    int count[3];//输入的楼层 
    int num[3];//单位时间差 
    int kk[3];//要去的楼层 
    int time[5];//时间捏 
    printf("输入电梯所在层数\n")； 
    scanf("%d",&j)
    printf("第一人第二人第三人分别输入所在层数\n");
    for(i=0;i<3;i++){
	scanf("%d",&x);	
	count[i]=x;
}
    printf("分别输入要去层数\n");
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
