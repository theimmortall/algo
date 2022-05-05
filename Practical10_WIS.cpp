#include<iostream> 
#include<algorithm> 
using namespace std; 
int computepj(int i,int S[],int FT[]) 
{ 
 int c=0; 
 
 for(int j=1;j<i;j++) 
 { 
 
  if(FT[j]<=S[i]) 
  { 
   c= j ; 
  } 
 
 } 
 
 return c; 
} 
int Computeopt(int j,int S[],int FT[],int Wt[]) 
{ 
 if(j==0) 
 return 0; 
 
 else 
 return 
 max(Wt[j]+Computeopt(computepj(j,S,FT),S,FT,Wt), 
 Computeopt(j-1,S,FT,Wt)); 
} 
 int main() 
 { 
 int num; 
 cout<<"Enter the number of requests : "; 
 cin>>num; 
 int J[num]; // job no. 
 int S[num]; // start time 
 int FT[num]; // finish time 
 int Wt[num]; // weight 
 int t; 
 cout<<"\nEnter the job names : \n"; 
 for(int i=1;i<=num;i++) 
 { 
  cin>>J[i]; 
 } 
 cout<<"\nEnter the start time ,finish time and weight for each request : \n"; 
 for(int i=1;i<=num;i++) 
 { 
   cout<<"\nFor "<<i<<"\n ST\t"; 
   cin>>S[i]; 
   cout<<"\n FT\t"; 
   cin>>FT[i]; 
   cout<<"\n WT\t"; 
   cin>>Wt[i]; 
 } 
 cout<<"\nEntered requests\n"; 
 cout<<"Job\t Start_time\t finish_time\t weight\n"; 
 for(int i=1;i<=num;i++) 
 { 
  cout<<J[i]<<"\t\t"<<S[i]<<"\t\t"<<FT[i]<<"\t\t"<<Wt[i]<<"\t\t\n"; 
 } 
 bool flag = true ; 
//to sort the jobs in the order of increasing finish time 
 for(int i=1;i<=num;i++) 
 { 
  for(int j=1;j<=num-i;j++) 
 { 
  if(FT[j]>FT[j+1]) 
 { 
  flag = false ; 
  t=FT[j]; 
  FT[j]=FT[j+1]; 
  FT[j+1]=t; 
 
 t=S[j]; 
 S[j]=S[j+1]; 
 S[j+1]=t; 
 
 t=J[j]; 
 J[j]=J[j+1]; 
 J[j+1]=t; 
 
 t=Wt[j]; 
 Wt[j]=Wt[j+1]; 
 Wt[j+1]=t; 
 } 
 
 
} 
} 
int pj; 
if(flag == false) // will execute only if the we have sorted the data according to finish time 
{ 
 cout<<"After sorting\n"; 
 cout<<"Job\t Start_time\t finish_time\t weight\n"; 
 for(int i=1;i<=num;i++) 
 { 
   cout<<J[i]<<"\t\t"<<S[i]<<"\t\t"<<FT[i]<<"\t\t"<<Wt[i]<<"\t\t\n"; 
 } 
} 
cout<<"\n\n"; 
for(int i=1;i<=num;i++) 
{ 
 cout<<"p("<<i<<")\t"; 
 pj=computepj(i,S,FT); 
 cout<<pj<<"\n"; 
} 
cout<<"\nOptimal value "<<Computeopt(num,S,FT,Wt); 
return 0 ; 
} 
