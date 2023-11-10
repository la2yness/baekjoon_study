#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hash(char *call){
    int index;
    index = 0;
    for (int i=1;i<5;i++){
        index+=call[i-1]*i;
    }
    index %= 1000000;
    return index;
}

void append(char **arr, char *call){
    int hashnum;
    hashnum = hash(call);
    strcpy(arr[hashnum], call);
}

void delete(char **arr, char *call){
    int hashnum;
    hashnum = hash(call);
    arr[hashnum][0] = '\0';
}

int main(){
    char **arr = NULL;
    arr = (char**)malloc(sizeof(char*) * 1000000);
    for (int i=0;i<1000000;i++){
        arr[i] = (char*)malloc(sizeof(char)*5);
        arr[i][0] = '\0';
    }
    int call;
    scanf("%d",&call);
    for(int i =0;i<call;i++){
        char str[6],type[6];
        scanf("%s %s",str,type);
        if (strcmp(type,"enter") == 0){
            append(arr, str);
        }
        else{
            delete(arr, str);
        }
    }
    for(int i=0;i<1000000;i++){
        if (arr[i][0] != '\0'){
            printf("%s\n",arr[i]);
        }
    }

    return 0;

}

