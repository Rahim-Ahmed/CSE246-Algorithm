#include<stdio.h>

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}



void selectionsort(int data[], int size){
    for(int i=0;i<size-1;i++){
            int min=i;
            for(int j=i+1;j<size;j++){
                    if(data[j]<data[min])
                        min=j;
    }
     if(min!=i){


     swap(&data[i],&data[min]);
    }
}

}

void printdata(int data[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",data[i]);
    }

}

int main(){
    int data[]={1,3,0,10,5,8};

    int size=sizeof(data)/sizeof(data[0]);


    selectionsort(data,size);

    printdata(data,size);

}
