#include<iostream> 
#include<stdlib.h> 
using namespace std; 
int randomno(int lower,int upper) 
{ 
 
 int num=(rand()%(upper-lower+1))+lower; 
 return num; 
 
} 
int PARTITION(int A[],int p,int r) 
{ 
 int x,temp; 
 x=A[r]; 
 int i=p-1; 
 
 for(int j=p;j<=r-1;j++) 
 { 
 if(A[j]<=x) 
 { 
 
 i=i+1; 
 temp=A[i]; 
 A[i]=A[j]; 
 A[j]=temp; 
 } 
 } 
 
 temp=A[i+1]; 
 A[i+1]=A[r]; 
 A[r]=temp; 
 
 
 return (i+1); 
} 
int randomizedpartition(int A[],int p,int r) 
{ 
 int T; 
 
 int i=randomno(p,r); 
 T=A[r]; 
 A[r]=A[i]; 
 A[i]=T; 
 
 return PARTITION(A,p,r); 
} 
int randomizedselect(int A[],int p,int r,int i) 
{ 
 if(p==r) 
 { 
 return A[p]; 
 } 
 
 int q,k; 
 q=randomizedpartition(A,p,r); 
 k=q-p+1; 
 if(i==k) 
 { 
 return A[q]; 
 } 
 else if(i<k) 
 { 
 return randomizedselect(A,p,q-1,i); 
 } 
 
 else 
 { 
 return randomizedselect(A,q+1,r,i-k); 
 } 
} 
int main() 
{ 
 int n, i; 
 int small; 
 int smallele; 
 
 cout<<"\nEnter the number of elements : "; 
 cin>>n; 
 int A[n]; 
 
 cout<<"\nEnter the elements : "; 
 for(i = 1; i <= n; i++) 
 { 
 cin>>A[i]; 
 } 
 
 cout<<"\n Enter the ith smallest element you want : "; 
 cin>>small; 
 
 smallele=randomizedselect(A,1,n,small); 
 
 cout<<"The "<<small<<"th smallest element is\t"<<smallele; 
 return 0; 
} 
