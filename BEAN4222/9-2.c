#include<stdio.h>
int main(){
	int ttl,idx,tmp,flag;
	tmp = 0;
	scanf("%d %d",&ttl,&idx);
	for(int i=1;i<=ttl;i++){
		if (ttl%i==0){
			tmp++;
			if (tmp==idx){
				printf("%d",i);
				flag = 1;
				break;
				
			}
				
		}
	}
	
	if (!flag){
		printf("%d",0);
	}
	return 0;

}
