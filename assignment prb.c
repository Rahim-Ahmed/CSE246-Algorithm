
#include<stdio.h>
#include<stdbool.h>

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void swap2(char *a, char *b){
    char t=*a;
    *a=*b;
    *b=t;
}




int partition(int data[],char id[], int start,int end){
     int pivot=data[start];
     int i=start+1;
     int j=end;

     while (true){
        while(data[i]>pivot)
            i++;
        while(data[j]<pivot)
            j--;

        if (i<j){
            swap(&data[i],&data[j]);
            swap2(&id[i],&id[j]);
        }
        else{
                swap(&data[j],&data[start]);
                swap2(&id[j],&id[start]);
                return j;

        }



     }


}

void quicksort(int data[],char id[], int start,int end){
    if(start<end){
        int p = partition(data,id,start,end);

        quicksort(data,id,start,p-1);
        quicksort(data,id,p+1,end);


    }



}


void assignment(int difficulty[],char id[],int size ){

    quicksort(difficulty,id,0,size-1);


    int sum=0;

    for(int i=0;i<size;i++)
        sum= sum+(difficulty[i]*(size-(i+1)));

    printf("\nMaximum point = %d",sum);
    printf("\nAssignment Submission Order = ");

    for(int i=0;i<size;i++)
    printf("A%c, ",id[i]);



}



int main(){


    char id[]={'A1','A2','A3','\0'};
    int difficulty[]={5,3,2};
    int size= sizeof(difficulty)/sizeof(difficulty[0]);
    assignment(difficulty,id,size);
}
