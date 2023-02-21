#include <limits.h>
#include <stdio.h>
int k_table[20][20];

void print_optimal(int i,int j){
    if (i == j)
    printf(" A%d ",i);
    else
       {
          printf("(");
          print_optimal(i, k_table[i][j]);
          print_optimal(k_table[i][j] + 1, j);
          printf(")");
       }
}


void MatrixChainOrder(int p[], int n){
	int m[n][n];
	int i, j, k, L, q;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
        if(j<=i)
        k_table[i][j]=0;
		m[i][j] = 0;
	}
    }
	for (L = 1; L < n-1; L++) {
		for (i = 1; i < n - L ; i++)
		{
			j = i + L ;
			int min= INT_MAX;
			int mark;
			for (k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < min){
                    min=q;
                    mark=k;

				}

			}
			k_table[i][j]=mark;
			m[i][j] = min;
		}
	}

    printf("\nMatrix is:\n");
	   for (i = 1; i < n; i++){
        for (j = 1; j < n; j++){
        printf("\t%d", m[i][j]);
	}
        printf("\n");
    }



    printf("\nK table:\n ");
	   for (i = 1; i < n; i++){
        for (j = 1; j < n; j++){
        printf("\t%d", k_table[i][j]);
	}
        printf("\n");
    }

        printf("\n Minimum number of multiplications is %d\n ",m[1][n - 1]);

}


int main(){
   //int matrix[] = {40, 25, 20, 10, 5, 15, 25};
	int matrix[] = {8,3,5,7,10,5,9};
	//int matrix[] = {1, 2, 3, 4, 3};
	//int matrix[] = { 1, 2, 3, 4};

	int size = sizeof(matrix) / sizeof(matrix[0]);

	int i=1,j=size-1;

    MatrixChainOrder(matrix, size);
    printf("\n Parenthesization of a matrix-chain product: ");
    print_optimal(i,j);
    printf("\n");

}

