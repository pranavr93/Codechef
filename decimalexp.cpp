#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
int n,d,t,r,temp,k,flag=0,a[1000002];
cin>>t;
while(t--)
{
cin>>n>>d>>r;
if(n==d){cout<<"0"<<endl;continue;}
k=0;
temp=n*10;
flag=0;
while(1)
{

     while(temp<d)
     {
          a[k]=0;
          if(k+1==r){cout<<a[k]<<endl;flag=1;break;}
          temp=temp*10;
          k++;
     }
     if(flag==1){break;}
     a[k]=temp/d;
      if(k+1==r){cout<<a[k]<<endl;flag=1;break;}
     k++;
     if(temp%d==0){cout<<"0"<<endl;break;}
     temp=(temp%d)*10;
}
}
return 0;
}
