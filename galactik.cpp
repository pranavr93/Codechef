#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
long long n,m,i,mini=16000,min2=16000,count=0,sum=0,j;
int cost[100100];
struct node
{
     int index;
     int flag;
     struct node *next;
};
struct node *a[1000010];
struct node *temp[1000010];
struct node *temp1;

void dfs(struct node *tem)
{

         if(tem->index!=j&&tem!=NULL&&tem->flag!=0)
         {
             tem->flag=0;
             count++;
             if(cost[tem->index]<min2){min2=cost[tem->index];}
             dfs(a[tem->index]);
             dfs(tem->next);
         }

}
int main()
{
long long x,y,tempo;
     scanf("%d%d",&n,&m);
   for(i=1;i<=m;i++)
   {
       scanf("%ld%ld",&x,&y);
       if(x<=y){}
       else{tempo=x;x=y;y=tempo;}
       if(a[x]==NULL)
       {
          a[x]= (struct node*) malloc(sizeof(struct node));
          a[x]->index=y;
          a[x]->flag=1;
          a[x]->next=NULL;
          temp[x]=a[x];
       }
       else
       {
          temp1 = (struct node*) malloc(sizeof(struct node));
          temp1->index=y;
          temp1->flag=1;
          temp1->next=NULL;
          temp[x]->next=temp1;
          temp1=NULL;
       }
          if(a[y]==NULL)
       {
          a[y]= (struct node*) malloc(sizeof(struct node));
          a[y]->index=x;
          a[y]->flag=1;
          a[y]->next=NULL;
          temp[y]=a[y];
       }
       else
       {
          temp1 = (struct node*) malloc(sizeof(struct node));
          temp1->index=x;
          temp1->flag=1;
          temp1->next=NULL;
          temp[y]->next=temp1;
          temp1=NULL;
       }

   }

   for(i=1;i<=n;i++)
   {
     scanf("%d",&cost[i]);
     if(cost[i]<0){cost[i]=15000;}
     if(cost[i]<mini){mini=cost[i];}
   }
   int flag2=0;

   for(i=1;i<=n;i++)
   {
     count=0;
     min2=16000;
     j=i;
     if(a[j]==NULL)
     {
          if(cost[j]>=0){sum+=(mini+cost[j]);}
          else{printf("-1\n");return 0;}
     }
     if(a[j]->flag==0){continue;}

   count++;
   dfs(a[j]);
   if(min2==15000)
     {
          flag2=1; continue;
     }

   sum+=(min2+mini);
   }
   if(flag2==1&&count==1){printf("0\n");return 0;}
   if(flag2==1&&count!=1){printf("-1\n");return 0;}
   else
   {
     printf("%ld\n",sum);
   }
   return 0;
}
