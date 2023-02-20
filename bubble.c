#include<stdio.h>

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}



void bubble(int data[], int size){
    for (int i=0;i<size-1;i++){
        for (int j=0;j<size-i-1;j++){
                if(data[j]>data[j+1])
            swap(&data[j+1],&data[j]);
        }
    }
}

void printdata(int data[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",data[i]);
    }

}

int main(){
    int data[]={2,3,56,45,6,657,878,76,65,7,64,56,5,3,4,55,};

    int size=sizeof(data)/sizeof(data[0]);


    bubble(data,size);

    printdata(data,size);

}
