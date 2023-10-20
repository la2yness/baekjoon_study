#include<stdio.h>
int main(){
	int fst,scd,thd,big,sum;
	scanf("%d %d %d",&fst,&scd,&thd);
	sum =fst+scd+thd;
	big = fst;
	if (big<scd){
		big = scd;
	}
	if (big<thd){
		big = thd;
	}
	while (big>=sum-big){
		big--;
		sum--;

	}
	printf("%d",sum);	
	

		
	return 0;
}
