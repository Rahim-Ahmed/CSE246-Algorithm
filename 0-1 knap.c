#include<stdio.h>
void knapsack(int weight[],int value[],int bag_size,int item){
   int B[item+1][bag_size+1];
    for(int i=0;i<=item;i++)
        B[i][0]=0;
    for(int i=0;i<=bag_size;i++)
        B[0][i]=0;
    printf("\nMatrix is:\n");

    for(int i=0;i<=item;i++){
        for(int j=0;j<=bag_size;j++){
                if(i>0 && j>0){
                    B[i][j]=B[i-1][j];
                    if( (j>=weight[i-1])&& B[i][j]<B[i-1][j-weight[i-1]]+value[i-1])
                        B[i][j]=B[i-1][j-weight[i-1]]+value[i-1];
                }
            printf("\t%d", B[i][j]);

        }
        printf("\n");
    }
    printf("\nMaximum profit: %d",B[item][bag_size]);
    printf("\nSelected items are:");

    while(item!=0){
        if(B[item][bag_size]!=B[item-1][bag_size]){
            printf("\n Items no %d where weight is:%d and value is:%d",item,weight[item-1],value[item-1]);
            bag_size-=weight[item-1];
        }
        item--;

    }

}

int main(){
    int W[]={7,4,6,5};
    int V[]={150,75,120,90};
    int M=10;
    int size= sizeof(W)/sizeof(W[0]);
    knapsack(W,V,M,size);



}
