
#include<iostream>
#include<string>
 
using namespace std;

void Merging(int A[],int R, int B[],int S, int C[])
{
 int nA = 1, nB=1, ptr=1;
 while(nA<=R && nB<=S)
 {
  if(A[nA]<B[nB])
  {
   C[ptr] = A[nA];
   ptr = ptr+1;
   nA+=1;
  }
  else{
   C[ptr] = B[nB];
   ptr++;
   nB++;
  }
 }
 
 if(nA>R){
   for(int k=0; k<=S-nB; k++){
    C[ptr+k] = B[nB+k];
   }
 }
 else{
   for(int k=0; k<=R-nA; k++){
    C[ptr+k] = A[nA+k];
   }
 }
}
   
int main()
{
 int n,m;
 cout<<"Enter first array size : ";
 cin>>n;
 int A[n+10];
 cout<<"Enter Element : \n";
 for(int i=1; i<=n; i++) cin>>A[i];
 
// sort(A,A+n);     // if array not sorted, then use this
 
 cout<<"Enter second array size : ";
 cin>>m;
 cout<<"Enter Elements : \n";
 int B[m+10];
 for(int i=1;i<=m; i++) cin>>B[i];
 
// sort(B,B+m);
 
 int C[m+n+10];
 
 Merging(A,n,B,m,C);
 
 cout<<"\nSorted Array \n";
 for(int i=1; i<=n+m; i++) cout<<C[i]<<" ";
 
 return 0;
}
