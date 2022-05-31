#include <stdio.h>




void main()



{


   
int n,p[10],i,k,l,j,e[10][10],temp=0,newtemp=0,delay,c[10][10],m;


printf("enter the delay time\n");


scanf("%d",&delay);


printf("enter the number of processes\n");


scanf("%d",&n);


for(i=1;i<=n;i++)


{


printf("number of events in p[%d]\n",i);


scanf("%d",&p[i]);


}


for(i=1;i<=n;i++)


for(j=0;j<=p[i];j++)


e[i][j]=0;


for(i=1;i<=n;i++)


for(j=1;j<=p[i];j++)

 
e[i][j]=e[i][j-1]+delay;



printf("eg: if 1->2, give p1=some number, and p2=some number+1, give 0 for no match\n");



for(i=1;i<=n;i++)


{ 


for(j=1;j<=p[i];j++)


{


printf("for c[%d][%d]",i,j);


scanf("%d",&c[i][j]);


}
}



for(i=1;i<=n;i++)


{


for(j=1;j<=p[i];j++)


{


temp=c[i][j];


for(k=i+1;k<=n;k++)


{


for(l=1;l<=p[k];l++)


{


newtemp=c[k][l];


if((temp+1==newtemp) &&(temp!=0 && newtemp!=0))


{


if(e[i][j]>=e[k][l])


{


e[k][l]=e[k][l]<(e[i][j]+delay)?(e[i][j]+delay):e[k][l];


if(e[k][l]==(e[i][j]+delay))

{

for(m=l;m<=p[k];m++)


{


e[k][m+1]=e[k][m]+delay;


}
}

}

}


else if((temp==newtemp+1) &&(temp!=0 && newtemp!=0))


{


if(e[i][j]<=e[k][l])


{


e[i][j]=e[i][j]<(e[k][l]+delay)?(e[k][l]+delay):e[i][j];


if(e[i][j]==(e[k][l]+delay))

{

for(m=j;m<=p[i];m++)


{


    e[i][m+1]=e[i][m]+delay;

}

  }
  
}

}

}

}

}

}


//printing values


for(i=1;i<=n;i++)


for(j=1;j<=p[i];j++)


printf("event %d%d : %d\n",i,j,e[i][j]);


}