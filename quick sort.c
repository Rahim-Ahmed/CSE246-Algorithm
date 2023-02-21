
#include<stdio.h>
#include<stdbool.h>

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}


int partition(int data[],int start, int end){
    int pivot=data[start];
    int i=start+1;
    int j=end;

    while(true){
         while(data[i]<pivot)
            i++;

         while(data[j]>pivot)
            j--;

        if(i<j){
            swap(&data[i],&data[j]);

        }
        else{
            swap(&data[j],&data[start]);
            return j;
        }


    }



}

void quick(int data[],int start, int end){
    if(start<end){
        int p = partition(data,start,end);

        quick(data,start,p-1);
        quick(data,p+1,end);

    }


}

void printdata(int data[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",data[i]);
    }
}

int main(){
    int data[]={454,56,65,6,78,34,5,23,52,98,67};
    int size = sizeof(data)/sizeof(data[0]);

     printf("%d \n",size);

    quick(data,0,size-1);

    printdata(data,size);
}

