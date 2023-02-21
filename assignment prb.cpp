#include<bits/stdc++.h>

using namespace std;

int main(){
int n, result=0;

cout<<"Enter no of assignments"<<endl;

cin>>n;

int d[n];
cout<<"Enter the difficulty level for each assignment"<<endl;

for(int i=0;i<n;i++){
    cin>>d[i];
}

sort(d,d+n);
int j=1;
for(int i=1;i<=n;i++){
    result=result+(d[i]*(n-i));

}
cout<<"max no of point are:"<<result;

return 0;

}
