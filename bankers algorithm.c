

#include<stdio.h>

void main()

{

int flag=0,co=1,M[10][10],N[10][10],A[10][10],click,i,j,k,r,p,R[10],n,S[10],W[10],REQ[10],TW[10],FP[10];
int l=1,t,f=0,LP[10];
printf("enter the number of processes\n");

scanf("%d",&n);

printf("enter the number of processes in an array\n");



printf("enter the number of resources\n");

scanf("%d",&r);

printf("enter the number for each resource type\n");

for(i=1;i<=r;i++)

{

printf("for R %d ",i);

scanf("%d",&R[i]);



W[i]=0;

S[i]=0;

TW[i]=0;

}
for(i=1;i<=n;i++)
{FP[i]=0;
LP[i]=0;
}
printf("enter the allocation matrix\n");

for(i=1;i<=n;i++)


{

for(j=1;j<=r;j++)

{

printf("for A[%d][%d]\n",i,j);

scanf("%d",&A[i][j]);
}
}


for(i=1;i<=r;i++)

{for(j=1;j<=n;j++)

{S[i]+=A[j][i];}}

for(i=1;i<=r;i++)
{

    W[i]=R[i]-S[i];

printf("work matrix: %d\n",W[i]);
}

printf("enter the maximum matrix\n");

for(i=1;i<=n;i++)

{
for(j=1;j<=r;j++)

{
printf("for M[%d][%d]\n",i,j);

scanf("%d",&M[i][j]);
}
}


while(co!=0)

{
    
printf("for requesting resource click 1, or click 0\n"); 
scanf("%d",&click);
if(click==1)

{
click=0;
printf("enter the  process which is making the request\n");
scanf("%d",&p);
printf("enter the request for each resource type\n");
for(i=1;i<=r;i++)
{
printf("for R %d ",i);
scanf("%d",&REQ[i]);
}
for(i=1;i<=r;i++)
{
if(W[i]>=REQ[i])
{
TW[i]=W[i]-REQ[i];
flag+=1;
}
else
{
printf("safe sequence not possible\n");
exit(0);;
}
if(flag==3)
{

flag=0;

for(j=1;j<=r;j++)

{

W[j]=TW[j];

A[p][j]+=REQ[j];


}
}
}
}
 
for(i=1;i<=n;i++)

for(j=1;j<=r;j++)


N[i][j]=M[i][j]-A[i][j];


do{
for(i=1;i<=n;i++)

{
for(j=1;j<=r;j++)

{
if((N[i][j]<=W[j])&&(FP[l]==0)&&(LP[i]!=1))

{
TW[j]=A[i][j];
flag+=1;
}
else if(FP[l]!=0)
{
    l++;
    flag=0;
}


if(flag==3 && j==r && (FP[l]==0) )

{

flag=0;

for(k=1;k<=r;k++)
{
W[k]+=TW[k];
TW[k]=0;



}

FP[l]=i;

l++;
f+=1;
LP[i]=1;
}
else if(flag!=3 && j==r && (FP[l]==0))
{
flag=0;
for(k=1;k<=r;k++)
{
TW[k]=0;
}
}




}


}
}while((f<n)&&(f!=n));
for(i=1;i<=r;i++)
{
    
if(W[i]==R[i])
{
flag+=1;
l=1;

    
}
else{
printf("nonsense!!exit now!!");
exit(0);
    
}
if(flag==3){
printf("safe sequence exists\n");
co=0;}

}

}

printf("the processes are in the order given below\n");

for(l=1;l<=n;l++)



printf("%d\n",FP[l]);
}




























