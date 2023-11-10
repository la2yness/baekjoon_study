#include<stdio.h>
#include<stdlib.h>
int main(){
        int student,tmp,idx=1,sidx=0,i=0;
        int* arr;
        int* stack;
        scanf("%d",&student);
        arr = (int*)malloc(sizeof(int)*student);
        stack = (int*)malloc(sizeof(int)*student);
        for (int i=0;i<student;i++){
                scanf("%d",&tmp);
                arr[i] = tmp;
        }
	while(1){
		if (i==student)
			break;
		else if (arr[i]==idx){
                        idx++;
			i++;
                }
		else if(idx==stack[sidx-1]){
			stack[sidx-1]=0;
			sidx--;
			idx++;
		}
                else{
			stack[sidx]=arr[i];
			sidx++;
			i++;
		}
        }
	for (int i=sidx-1;i>-1;i--){

                if (stack[i]!=idx){
                        printf("Sad");
                        return 0;
                }
                idx++;
        }
        printf("Nice");
        free(arr);free(stack);
        return 0;
}
