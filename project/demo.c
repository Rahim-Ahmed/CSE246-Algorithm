#include<stdio.h>
    int red=0,blue=1,green=2,yellow=3;

int main(){
    printf("\n      --- --- --- Welcome to this adventure game--- --- ---");
    printf("\nThere are flags of 4 colors and 8 rooms\n");
    int selectedIndexforColor[4]={-1,-1,-1,-1};
    int c[8]={   red,  blue , green, red, yellow,blue, yellow, green};
    char color[8][10]={   "red", "blue"  ,"green", "red", "yellow","blue", "yellow"  ,"green"};
    int points[8]={         2,     8,         3,      5,      11,      9,       1,         4};
    int isSelected[8]={0,0,0,0,0,0,0,0};
    int max_score=0;

    int tmPointUsingN[]={0,0,0,0};
    int tmPointUsingNIndex[]={0,0,0,0};

    printf("\nThe point array for 8 room is: [");
    for(int i=0;i<8;i++)
     printf("%d ",points[i]);

    printf("]\nFind the flags in a way so that you can achieve maximum points in the game.");
    printf("\n      --- --- --- --- --- --- --- --- --- --- --- ---\n");

    int m,n;
    printf("\nEnter Value of m: ");
    scanf("%d",&m);
    printf("\nEnter Value of n: ");
    scanf("%d",&n);

    int index,max,temp,min,tmp_score,count=0;
    printf("\nSelected Flags are: ");


if(m==0 && n==0){
        printf("\n\n    No Flags are Selected as points of selecting all the Flags is: 0");

}

else if(m<0 && n<0){
        printf("\n\n    No Flags are Selected as points of selecting Flags is negative. ");

}
else if(n<=0 && m>0){
     for(int i=0;i<8;i++){
        min=9999,temp=0;
     for(int j=0;j<8;j++){
        temp=points[j];
         if(temp<=min && isSelected[j]==0){
            min=temp;
            index=j;
         }
     }
     isSelected[index]=1;
     if(selectedIndexforColor[c[index]]==-1){
            tmp_score=n*points[index];
            tmPointUsingN[c[index]]=tmp_score;
            tmPointUsingNIndex[c[index]]=index;
            selectedIndexforColor[c[index]]=index;


     }
     else{
        int tmp_score2=m*points[index];
        int hold=tmp_score2+tmPointUsingN[c[index]];

        if(hold>0){

            max_score=max_score+tmp_score2+tmPointUsingN[c[index]];
            count+=2;
            printf("\n  Room no: %d where color of the flag is %s corresponding point is: (%d X %d)=%d"
                   ,index+1,color[index],points[index],m,tmp_score2);
            printf("\n  Room no: %d where color of the flag is %s corresponding point is: (%d X %d)=%d"
                   ,tmPointUsingNIndex[c[index]]+1,color[index],(tmPointUsingN[c[index]]/n),n,tmPointUsingN[c[index]]);
        }
        else{
            printf("\n  Room no: %d where color of the flag is %s corresponding point is:(%d X %d)= %d --->[which is not selected]"
                   ,index+1,color[index],points[index],m,tmp_score2);
            printf("\n  Room no: %d where color of the flag is %s corresponding point is: (%d X %d)=%d --->[which is not selected]"
                   ,tmPointUsingNIndex[c[index]]+1,color[index],(tmPointUsingN[c[index]]/n),n,tmPointUsingN[c[index]]);
            }

     }

    }
}
else{
    for(int i=0;i<8;i++){
        max=0,temp=0;
     for(int j=0;j<8;j++){
        temp=points[j];
         if(temp>=max && isSelected[j]==0){
            max=temp;
            index=j;
         }
     }
     isSelected[index]=1;
     if(selectedIndexforColor[c[index]]==-1){
            tmp_score=n*points[index];
         if(tmp_score>=0){
            max_score=max_score+tmp_score;
            selectedIndexforColor[c[index]]=index;
            count++;
            printf("\n  Room no: %d where color of the flag is %s corresponding point is: (%d X %d)=%d"
                   ,index+1,color[index],points[index],n,tmp_score);
            }
            else{
            printf("\n  Room no: %d where color of the flag is %s corresponding point is:(%d X %d)= %d --->[which is not selected]"
                   ,index+1,color[index],points[index],n,tmp_score);

            }
     }
     else{
        int tmp_score2=m*points[index];
        if(tmp_score2>=0){
            max_score=max_score+tmp_score2;
            count++;
            printf("\n  Room no: %d where color of the flag is %s corresponding point is: (%d X %d)=%d"
                   ,index+1,color[index],points[index],m,tmp_score2);
        }
        else{
            printf("\n  Room no: %d where color of the flag is %s corresponding point is:(%d X %d)= %d --->[which is not selected]"
                   ,index+1,color[index],points[index],m,tmp_score2);
            }

     }

    }
}




 printf("\n\n Maximum Points: %d",max_score);
 printf("\n The Number of Selected flag is: %d\n",count);
}

