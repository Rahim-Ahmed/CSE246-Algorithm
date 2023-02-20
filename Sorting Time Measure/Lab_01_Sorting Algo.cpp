#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define SIZE 30000
int data[SIZE];

void RandomDataWrite(char *FileName){
    FILE *fp;
    time_t t;
    int i;
    fp = fopen(FileName, "w");
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; i++){
        fprintf(fp, "%d\n", rand()%INT_MAX);
    }
    fclose(fp);
}

void ReadFromFile(char *FileName){
    FILE *fp;
    int i;
    fp = fopen(FileName, "r");
    for(i = 0; i < SIZE; i++){
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
}

void WriteToConsole(){
    for(int i = 0; i < SIZE; i++){
        printf("%10d", data[i]);
    }
}

void SelectionSort(){
        for (int i = 0; i < SIZE - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (data[j] < data[min])
                min = j;
        }
        int temp=data[i];
        data[i]=data[min];
        data[min]= temp;
    }
}


void InsersionSort(){
           for (int i = 1; i < SIZE ; i++)
    {
        int key = data[i];
        int j=i-1;
        while((key<data[j]) && (j>=0))
              {
                  data[j+1]=data[j];
                  j--;

              }
              data[j+1]=key;

    }
}

void BubbleSort(){

 for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE -i -1; j++)
        {
            if (data[j] > data[j+1]){
                int temp=data[j];
                data[j]=data[j+1];
                data[j+1]= temp;

            }

        }
    }

}


void DecendingSelectionSort(){
        for (int i = 0; i < SIZE - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (data[j] > data[min])
                min = j;
        }
        int temp=data[i];
        data[i]=data[min];
        data[min]= temp;
    }
}


void DecendingInsersionSort(){
           for (int i = 1; i < SIZE ; i++)
    {
        int key = data[i];
        int j=i-1;
        while((key>data[j]) && (j>=0))
              {
                  data[j+1]=data[j];
                  j--;

              }
              data[j+1]=key;

    }
}

void DecendingBubbleSort(){

 for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE -i -1; j++)
        {
            if (data[j] < data[j+1]){
                int temp=data[j];
                data[j]=data[j+1];
                data[j+1]= temp;

            }

        }
    }

}


int main(){
    clock_t start, end;

    int i, ans;
    RandomDataWrite("RandomIntegers.txt");

    ReadFromFile("RandomIntegers.txt");
    start = clock();
    SelectionSort();
    end = clock();
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n Selection Sort took %f seconds to execute \n", time_taken);

    ReadFromFile("RandomIntegers.txt");
    start = clock();
    InsersionSort();
    end = clock();
     time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n Insersion Sort took %f seconds to execute \n", time_taken);

    ReadFromFile("RandomIntegers.txt");
    start = clock();
    BubbleSort();
    end = clock();
     time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n Bubble Sort took %f seconds to execute \n", time_taken);



    start = clock();
    SelectionSort();
    end = clock();
     time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n For sorted data Selection Sort took %f seconds to execute \n", time_taken);

    start = clock();
    InsersionSort();
    end = clock();
     time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n For sorted data Insersion Sort took %f seconds to execute \n", time_taken);


    start = clock();
    BubbleSort();
    end = clock();
     time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n For sorted data Bubble Sort took %f seconds to execute \n", time_taken);



    ReadFromFile("RandomIntegers.txt");
    start = clock();
    DecendingSelectionSort();
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n For Descending data Selection Sort took %f seconds to execute \n", time_taken);

    ReadFromFile("RandomIntegers.txt");
    start = clock();
    DecendingInsersionSort();
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n For Descending data Insertion Sort took %f seconds to execute \n", time_taken);

    ReadFromFile("RandomIntegers.txt");
    start = clock();
    DecendingBubbleSort();
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n For Descending data Bubble Sort took %f seconds to execute \n", time_taken);

  // for display those elements
   /* for (int i = 0; i < SIZE; i++)
    {
        printf("%d  ", data[i]);
    }
    printf("\n");
*/

}
