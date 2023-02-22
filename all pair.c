#include<stdio.h>
#define INF 99999
#define V 4
#define max 4

void path_print(int graph[max][max]){
    printf("\nThe shortest path of all vertex is:");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]==INF)
                printf("\n vertex %d to %d is: INF",i+1,j+1);
            else{
                printf("\n vertex %d to %d is: %d",i+1,j+1,graph[i][j]);

            }
        }
        printf("\n");
    }

}

void prisolution(int graph[max][max]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]==INF)
                printf("\tINF");
            else{
                printf("\t%d",graph[i][j]);
            }
        }
        printf("\n");
    }

}

void floydWarshall(int graph[max][max]){
    int i,j,k;
    for(k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(graph[i][j]>graph[i][k]+graph[k][j])
                   graph[i][j]=graph[i][k]+graph[k][j];
            }
    }

    if(k+1!=V){
        printf("\nMatrix using path %d:\n",k+1);
        prisolution(graph);
    }

    }

    printf("\nFinal Matrix using path %d:\n",k);
    prisolution(graph);
    path_print(graph);

}
int main(){
    /* Let us create the following weighted graph
               10
         (1)------->(4)
          |		    /|\
        5 |		     |
          |		     | 1
         \|/		 |
         (2)------->(3)
                3		 */

    	int graph[V][V] = {
                        { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 }
						};

    floydWarshall(graph);
}
