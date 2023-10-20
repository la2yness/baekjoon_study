#include<stdio.h>
#include<stdlib.h>
int main(){
	int givennum;
	scanf("%d",&givennum);
	while (givennum!=-1){
		int* arr = (int*)malloc(sizeof(int)*givennum+1);
		
		int tmp = 1;
		for (int i=2;i<givennum;i++){
			arr[i] = 0;
			if (givennum%i==0){
				arr[i] = i;
				tmp+=i;	
			}
		}
		if (tmp==givennum){
			printf("%d = 1 ",givennum);
			for (int i=2;i<givennum;i++){
				if (arr[i]){
					printf("+ %d ",i);
				}
			}
			printf("\n");
		}
		else{
			printf("%d is NOT perfect.\n",givennum);
		}
		free(arr);
	
	scanf("%d",&givennum);
	}
	return 0;
}
