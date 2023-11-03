#include<stdio.h>
#include<stdlib.h>
int main(){
    int* arr = (int*)malloc(sizeof(int)*6);
    scanf("%d %d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5]);
    for (int i=-999;i<1000;i++){
        for (int j=-999;j<1000;j++){
            if (i*arr[0]+j*arr[1]==arr[2]&&i*arr[3]+j*arr[4]==arr[5]){
                printf("%d %d",i,j);
            }
        } 
        
    }
    return 0;
}
