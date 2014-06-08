#include<stdio.h>
#include<conio.h>
void TOH(int n,char x,char y,char z);
void main()
{
 int n;
 printf("Enter number of plates:");
 scanf("%d",&n);
 TOH(n-1,'L','R','C');  //L -> Left pole, R -> Right Pole, C -> Center pole.

 getch();
}
void TOH(int n,char x,char y,char z) //transfer n disks from one pole to another.
{
 if(n>0) //boundary condition.
 {
  TOH(n-1,x,z,y);  //recursive statement.
  printf("\n %c -> %c",x,y);
  TOH(n-1,z,y,x);
 }
}
