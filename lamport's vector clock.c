#include<stdio.h>

#include<stdlib.h>


#include<math.h>

void main()

{

int m[10],n,i,j,p[10][10],c[10][10],maxevent=0,data,k,temp,newtemp,l,o=1,comp,acomp,y,z,q,r,value=2;

printf("enter the number of processes\n");

scanf("%d",&n);



for(i=1;i<=n;i++)

{

printf("for process p%d\n",i);

scanf("%d",&m[i]);

}



for(i=1;i<=n;i++)

{
for(j=1;j<=m[i];j++)

{

if(maxevent>m[j])

{
maxevent=maxevent;
}

else

maxevent=m[j];

}
}


for(i=1;i<=n;i++)

for(j=1;j<=maxevent;j++)

p[i][j]=0;



for(i=1;i<=n;i++)

for(j=1;j<=maxevent;j++)

c[i][j]=0;



for(i=n;i>=1;i--)

{

for(j=1;j<=m[i];j++)

{

data=1;

if(i==n)

{

data=1*j;

p[i][j]=data;

}

else

{

k=n-i;

while(k!=0)

{

data=data*10;

k--;

}

p[i][j]=data*j;

}

}

}



printf("enter the casually related events...given a number for event..then that number +1 for the next..eg: a->b; a=2,b=3\n");

for(i=1;i<=n;i++)



{
 


for(j=1;j<=m[i];j++)



{



printf("for c[%d][%d]",i,j);



scanf("%d",&c[i][j]);



}

}




for(i=1;i<=n;i++)

{

for(j=1;j<=m[i];j++)

{


for(l=i+1;l<=n;l++)

{

    for(o=1;o<=m[l];o++)

{


temp=c[i][j];

newtemp=c[l][o];


 
 


if((temp+1==newtemp)&&(temp!=0)&&(newtemp!=0)&&(temp==value))

{
   
 value=value+4;

     
    for(q=n+1;q>=1;q--)

    {

comp=(int)p[i][j] % (int)(pow(10,q));

acomp=(int)p[l][o-1] % (int)(pow(10,q));

comp=comp/pow(10,(q-1));

acomp=acomp/pow(10,(q-1));

if(comp>acomp)

{

for(y=o;y<=m[l];y++)

{

p[l][y]=p[l][y]-(acomp*pow(10,(q-1)));

p[l][y]=p[l][y]+(comp*(pow(10,q-1)));


}
}
}

    i=1;
    
j=1;

    l=i+1;
   
 o=1;

}

else if((temp==newtemp+1)&&(temp!=0)&&(newtemp!=0)&&(newtemp==value))

{

    value=value+4;
   
 for(r=n+1;r>=1;r--)
  
  {

comp=(int)p[l][o] % (int)(pow(10,r));

acomp=(int)p[i][j-1] % (int)(pow(10,r));

comp=comp/pow(10,r-1);

acomp=acomp/pow(10,r-1);

if(comp>acomp)

{

for(z=j;z<=m[i];z++)

{

p[i][z]=p[i][z]-(acomp*pow(10,r-1));

p[i][z]=p[i][z]+(comp*pow(10,r-1));

}
}
}

    i=1;

    j=1;
   
 l=i+1;
 
   o=1;

}




}
   
}
   
}
    
}



for(i=1;i<=n;i++)

for(j=1;j<=maxevent;j++)

printf("%d%d : %d\n",i,j,p[i][j]);


}