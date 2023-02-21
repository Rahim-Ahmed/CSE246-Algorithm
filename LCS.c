#include<stdio.h>
#include<string.h>

char s2[] = "ABEFXYZ";
char s1[] = "FBKXCY";

//char s1[] = "ACDB";
//char s2[] = "ACBD";

void LCS_algo(){
    printf("\ S1:%s\n",s1);
    printf("\ S2:%s\n",s2);

    int m=strlen(s1);
    int n=strlen(s2);
    int LCS[m+1][n+1];

    for(int i=0;i<=m;i++)
        LCS[i][0]=0;
    for(int i=0;i<=n;i++)
        LCS[0][i]=0;

    printf("\nMatrix is:\n");

     for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
                if(i>0 && j>0){
                        if(s1[i-1]==s2[j-1]){
                          LCS[i][j]=1+LCS[i-1][j-1];
                        }
                        else if(LCS[i-1][j]>LCS[i][j-1]){
                           LCS[i][j]= LCS[i-1][j];
                        }
                        else{
                           LCS[i][j]= LCS[i][j-1];
                        }

                }
            printf("\t%d", LCS[i][j]);

        }
        printf("\n");
    }

    int index=LCS[m][n];
    char result[index];
    result[index]='\0';
    int i=m, j=n;

    while( i>0 || j>0){
        if(s1[i-1]==s2[j-1] ){
            result[index-1]=s1[i-1];
            i--;
            j--;
            index--;
        }
        else if(LCS[i-1][j]>LCS[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    printf("\n LCS:%s",result);


    int index2=LCS[m][n];
    char result2[index2];
    result2[index2]='\0';
    i=m, j=n;

    while( i>0 ||  j>0){
        if(s1[i-1]==s2[j-1] ){
            result2[index2-1]=s1[i-1];
            i--;
            j--;
            index2--;
        }
        else if(LCS[i-1][j]>=LCS[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }


    int check = strcmp(result,result2);
     if(check!=0){
       printf("\n LCS:%s", result2);
    }







}

int main(){
    LCS_algo();
}
