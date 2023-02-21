
#include<stdio.h>
#include<stdbool.h>


int mergesort(int data[],int start,int middle, int end){

    int i,j,k;
    int n1= middle - start +1;
    int n2= end-middle;

    int L[n1],R[n2];

    for( i=0;i<n1;i++)
        L[i]= data[start+i];

    for( j=0;j<n2;j++)
        R[j]=data[middle+1+j];

     i=0;
     j=0;
     k=start;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            data[k]=L[i];
            i++;
        }
        else{
            data[k]=R[j];
            j++;

        }
        k++;

    }

    while(i<n1){
            data[k]=L[i];
            i++;
            k++;
    }
    while(j<n2){
            data[k]=R[j];
            j++;
            k++;
    }



}

void merge(int data[],int start, int end){
    if(start<end){
        int middle= start +(end-start)/2;

        merge(data,start,middle);
        merge(data,middle+1,end);

        mergesort(data,start,middle,end);

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

    merge(data,0,size-1);

    printdata(data,size);
}

