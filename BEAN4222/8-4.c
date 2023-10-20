#include<stdio.h>
#include<math.h>
int main(){
	int rst, tmp,time;
	scanf("%d",&time);
	rst = 4;
	for(int i=1;i<pow(2,time-1)+1;i*=2){
		tmp = 3*(i)*(i)+2*i;
		rst+=tmp;
	}
	printf("%d",rst);
	return 0;
}
	

