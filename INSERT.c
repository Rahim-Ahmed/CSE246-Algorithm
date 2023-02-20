#include<stdio.h>

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}



void insert(int data[], int size){
    for(int i=1; i<size;i++){
    int key= data[i];
    int j=i-1;
    while((data[j]>key) && j>=0 ){
        data[j+1]=data[j];
        j--;
    }
        data[j+1]=key;
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


    insert(data,size);

    printdata(data,size);

}
