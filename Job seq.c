
#include<stdio.h>
#include <conio.h>
#include <stdbool.h>


max(int x[],int k)
{
	int t,i;
	t=x[0];
	for(i=1;i<k;i++)
        {
		if(x[i]>t)
			t=x[i];
	}
	return(t);
}

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


int partition(int data[],int deadline[],char id[], int start,int end){
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
            swap(&deadline[i],&deadline[j]);
            swap2(&id[i],&id[j]);
        }
        else{
                swap(&data[j],&data[start]);
                swap(&deadline[j],&deadline[start]);
                swap2(&id[j],&id[start]);
                return j;

        }



     }


}

void quicksort(int data[],int deadline[],char id[], int start,int end){
    if(start<end){
        int p = partition(data,deadline,id,start,end);

        quicksort(data,deadline,id,start,p-1);
        quicksort(data,deadline,id,p+1,end);


    }



}



void job(int deadline[],int profit[],char id[],int slot, int size){

    quicksort(profit,deadline,id,0,size-1);

    char id_s[slot-1];
    int result[slot-1];

    for (int i=0;i<slot;i++)
        result[i]=NULL;


    for (int i=0;i<size;i++){
        for (int j=deadline[i]-1;j>=0;j--){
        if(result[j]==NULL){
            result[j]=profit[i];
            id_s[j]= id[i];
            break;
        }
        }
    }

     printf("\n Following is maximum profit sequence of jobs: \n    ");
 for(int i=0;i<slot;i++){
        printf("%c, ",id_s[i]);
    }



}

int main(){


    char id[]={'a','b','c','d','e','\0'};
    int deadline[]={2,1,2,1,3};
    int profit[]={100,19,27,25,15};
    int size= sizeof(deadline)/sizeof(deadline[0]);
    int slot = max(deadline,size);

    job(deadline,profit,id,slot,size);
}


