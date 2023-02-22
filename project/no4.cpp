#include <bits/stdc++.h>
using namespace std;

    int red=0;
    int blue=1;
    int green=2;
    int yellow=3;

int main(){
    int selectedIndexforColor[4]={-1,-1,-1,-1}; // Kon color er flag koynumber ghor theke nisi (-1 mane ekhono oi color er flag nei nai)
    int c[6]={   red,  blue , green, red, yellow,blue}; // Color Array (6 ta ghorervitre kon ghore ki color er flag ase)
    int points[6]={5,  13,      7,   8,     9,     4}; // Points of each of the 6 flags

    int m,n;
    cout<<"Enter Value of m: "<<endl;
    cin>>m;
    cout<<"Enter Value of n: "<<endl;
    cin>>n;

    int isSelected[6]={0,0,0,0,0,0}; // Value 0 jodi oi ghorer flag ta select korinai. Ar jodi select kori taile Value 1 bananbo
    int max_score=0;
    for(int i=0;i<6;i++){
    if(selectedIndexforColor[c[i]]==-1){
        int tmp_score=max_score+n*points[i];
            if(tmp_score>=max_score){
            max_score=tmp_score;
            selectedIndexforColor[c[i]]=i;
            isSelected[i]=1;
            }
    }
    else{
        int tmp_score=max_score-n*points[selectedIndexforColor[c[i]]]+m*points[selectedIndexforColor[c[i]]]+m*points[i];
        int tmp_score2=max_score-n*points[selectedIndexforColor[c[i]]]+n*points[i];
            if(tmp_score>=max_score){
                max_score=tmp_score;
                isSelected[i]=1;
            }
            if(tmp_score2>=max_score){
                max_score=tmp_score2;
                isSelected[selectedIndexforColor[c[i]]]=0;
                isSelected[i]=1;
            }
    }
}

for(int i=0;i<6;i++){
    if(isSelected[i]!=0){
        cout<<endl<<"Flag no. "<<(i+1)<<" having "<<points[i]<<" points has been selected"<<endl;
    }
}

cout<<endl<<"Maximum Points: "<<max_score<<endl;
}
