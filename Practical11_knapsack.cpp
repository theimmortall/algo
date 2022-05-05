#include<iostream> 
using namespace std; 
int max(int a, int b) 
{ 
  return (a>b)?a:b; 
}
 int knapSack(int W, int wt[], int val[], int n) 
{ 
  if (n==0 || W==0) // base case 
  return 0; 
  if (wt[n-1]>W) 
  return knapSack(W, wt, val, n-1); 
  else 
  return max( 
 val[n-1]+ knapSack(W-wt[n-1],wt, val, n-1), 
 knapSack(W, wt, val, n-1)); 
} 
int main() 
{ 
 int n ; 
 
 int W = 10; 
 cout<<"\nEnter the number of items : "; 
 cin>>n ; 
 int val[n], wt[n]; 
 cout<<"\nEnter the values of item : "; 
 for(int i =0 ; i<n ;i++) 
 { 
  cin>>val[i]; 
 }
 cout<<"\nEnter the weights of item : "; 
 for(int i =0 ; i<n ;i++) 
 { 
   cin>>wt[i]; 
 } 
 cout<<"\nThe knapsack capacity is \t"<<W; 
 cout<<"\n\nThe values with their weight :\n"; 
 cout<<"\nValues\t\tWeight\t\n"; 
 for(int i=0;i<3;i++) 
 { 
  cout<<val[i]<<"\t\t"<<wt[i]<<"\n"; 
 } 
 cout<<"\nThe optimal value is \t"<<knapSack(W, wt, val, n); 
 return 0; 
} 
