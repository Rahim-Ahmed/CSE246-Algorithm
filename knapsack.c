#include<stdio.h>

int n=5;
int w[]={5, 10, 15, 22, 25};
int v[]={30, 40, 45, 77, 90};

int W=60;
void knapsack(){
    int currrent_w;
    float total_v;
    int i, maxi;
    int used[n];
    for (i = 0; i < n; i++)
        used[i] = 1;


    currrent_w = W;
    while (currrent_w > 0) {
        maxi = -1;

        for (i = 0; i < n; i++)
            if ( (used[i] == 1) && ((maxi == -1) || ( (float)v[i]/w[i] > (float)v[maxi]/w[maxi]) ) )
                maxi = i;

        used[maxi] = 0;

        currrent_w = currrent_w - w[maxi];
        total_v =total_v + v[maxi];

        if (currrent_w >= 0)
            printf("Item %d, ", maxi + 1);
        else {
            total_v = total_v - v[maxi];
            total_v = total_v + (1 + (float)currrent_w/w[maxi]) * v[maxi];


            printf("and (%.2f out of %d) of Item %d. \n",
                ((1 + (float)currrent_w/w[maxi]) * w[maxi]), w[maxi], maxi + 1);

        }
    }

    printf("Maximum benefits: %.2f unit\n", total_v);


}

int main (){
knapsack();
}
