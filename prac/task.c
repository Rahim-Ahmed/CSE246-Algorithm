#include<stdio.h>
#include <stdbool.h>


int lower_bound(int arr[], int N, int X)
{
	int mid;
	int low = 0;
	int high = N;

	while (low < high) {
		mid = low + (high - low) / 2;


		if (X <= arr[mid]) {
			high = mid;
		}

		else {
			low = mid + 1;
		}
	}

	if(low < N && arr[low] < X) {
	low++;
	}


	return low;
}


int upper_bound(int arr[], int N, int X)
{
	int mid;
	int low = 0;
	int high = N;
	while (low < high) {

		mid = low + (high - low) / 2;
		if (X >= arr[mid]) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	if(low < N && arr[low] <= X) {
	low++;
	}
	return low;
}

int main(){
    int n,s, temp;
    scanf("%d %d",&n,&s);

int A[n];

for(int i=0;i<n;i++)
    scanf("%d",&A[i]);



    int upper = upper_bound(A,n,s);
	if (upper == n) {
		printf("%d",n);
	}
	else {

		printf("%d ",upper);
	}


	int lower = lower_bound(A,n,s);


    if (lower == n) {
		printf("0");
        }
    else {
            for (int i=n; i>=0;i--){
                if (A[lower]==A[i]){
                    lower=i;
                }

            }
            printf(" %d\n ", lower);

    }








}
