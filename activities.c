#include<stdio.h>


void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}



void selectionsort(int data[],int start[], int size){
    for(int i=0;i<size-1;i++){
            int min=i;
            for(int j=i+1;j<size;j++){
                    if(data[j]<data[min])
                        min=j;
    }
     if(min!=i){
     swap(&data[i],&data[min]);
     swap(&start[i],&start[min]);
    }
}

}




void active(int start[],int finish[], int size){

    selectionsort(finish,start,size); // sort finish only

    int i=0;
    printf("\n (%d,%d)",start[i],finish[i]);
    int count=1;

    for (int j=1;j<size;j++){
        if(start[j]>=finish[i]){
                i=j;
                count++;
                printf(",(%d,%d)",start[i],finish[i]);
        }
    }
    printf("\n Total activities: %d",count);

}

int main(){


    int s[]={1,3,0,5,5,8};
    int f[]={2,4,6,7,9,9};
    int size= sizeof(s)/sizeof(s[0]);
    active(s,f,size);
}

