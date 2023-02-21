#include<stdio.h>
    int red=0;
    int blue=1;
    int green=2;
    int yellow=3;

int main(){
    printf("\n---Welcome to this adventure game---");
    printf("\nThere are flags of 4 colors and 6 rooms");
    int selectedIndexforColor[4]={-1,-1,-1,-1}; // Kon color er flag koynumber ghor theke nisi (-1 mane ekhono oi color er flag nei nai)
    int c[6]={   red,  blue , green, red, yellow,blue}; // Color Array (6 ta ghorervitre kon ghore ki color er flag ase)
    char color[6][10]={   "red", "blue"  ," green", "red", "yellow","blue"}; // Color Array (6 ta ghorervitre kon ghore ki color er flag ase)
    int points[6]={     5,    13,        7,       8,      9,       4}; // Points of each of the 6 flags

    int isSelected[6]={0,0,0,0,0,0}; // Value 0 jodi oi ghorer flag ta select korinai. Ar jodi select kori taile Value 1 bananbo
    int max_score=0;

    int m,n;
    printf("\nEnter Value of m: ");
    scanf("%d",&m);
    printf("\nEnter Value of n: ");
    scanf("%d",&n);

    for(int i=0;i<6;i++){
    if(selectedIndexforColor[c[i]]==-1){
        int tmp_score=n*points[i];
            if(tmp_score>=0){
            max_score=max_score+tmp_score;
            selectedIndexforColor[c[i]]=i;
            isSelected[i]=1;
            printf("\nRoom no. %d where color of the flag is %s corresponding point is: (%d X %d)=%d"
                   ,i+1,color[i],points[i],n,tmp_score);
            }
            else{
            printf("\nRoom no. %d where color of the flag is %s corresponding point is:%d --->[which is not selected]"
                   ,i+1,color[i],tmp_score);

            }
    }
    else{
        int tmp_score=n*points[i];
        int tmp_score2=m*points[i];
        if(tmp_score2>=0 && tmp_score2>tmp_score){
            max_score=max_score+tmp_score2;
            isSelected[i]=1;
            printf("\nRoom no. %d where color is %s corresponding point is: (%d X %d)=%d"
                   ,i+1,color[i],points[i],m,tmp_score2);
        }
        else if(tmp_score>=0){
            max_score=max_score+tmp_score;
            isSelected[i]=1;
            printf("\nRoom no. %d where color is %s corresponding point is: (%d X %d)=%d"
                   ,i+1,color[i],points[i],n,tmp_score);

        }
        else{
            printf("\nRoom no. %d where color is %s is not selected"
                   ,i+1,color[i]);
            }

    }
}
 printf("\nMaximum Points: %d",max_score);
}
