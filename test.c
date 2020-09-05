#include <stdio.h>
#include <stdlib.h>

int main(){
    int A[10];
    int i;
    for(i=0;i<10;i++){
        A[i]=i;
    }
    for(i=0;i<10;i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
    }

