#include<stdio.h>
#include<stdlib.h>
int main(){
	for ( int i = 0; i<5; i++){
		arr[i] = (char*)malloc(sizeof(char) * 15);
	}
	for (int i = 0; i<5;i++){
		scanf("%s", arr[i]);
	}
	for (int i = 0; i<15;i++){
		for (int j=0; j<5;j++){
			if (!arr[j][i]){
				continue;
			}
			printf("%c", arr[j][i]);
		}
	}
	for (int i = 0; i < 5; i++) {
    		free(arr[i]); 
	}
	free(arr);
	return 0;
}

	
