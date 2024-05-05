#include<stdio.h>
// using namespace std;
int main()
{
    // int*p;
    int a[]={10,20,30,40,50,60};
    int*b=a;
    


int* p[]={a,a+1,a+2,a+3,a+4,a+5};
int** pp=p;

printf("%d\n",pp-p);
printf("%d\n",*pp-a);
printf("%d\n",**pp);
printf("%d\n",*pp);

*pp++;
printf("first operation");
 printf("%d\n",*pp);
// printf("%d\n",p);
printf("%d\n",pp-p);
printf("%d\n",p);
printf("%d\n",*pp-a);
printf("%d\n",**pp);
++*pp;
printf("SECOND operation");
 printf("%d\n",*pp);
 printf("%d\n",p);
printf("%d\n",pp-p);
printf("%d\n",*pp-a);
printf("%d\n",**pp);
   return 0; 
}