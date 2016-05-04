/* Fibonacci Series c language */
#include<stdio.h>
#include <unistd.h>
int print_char(char c);
void print_number(int n);

int main()
{
  int first = 0, second = 1, next, c;
  int sum;
  sum=0;
  /*
  printf("Enter the number of terms\n");
  scanf("%d",&n);

  printf("First %d terms of Fibonacci series are :-\n",n);*/

  for ( c = 0 ; next<4000000 ; c++ )
    {
      next = first + second;
      first = second;
      second = next;
      if (next<4000000 && next%2==0){
	/*printf("%d %d\n",c, next);*/
	sum+=next;
      }
    }
  print_number(sum);
  print_char('\n');
  return 0;
}

/*prints number one by one*/
void print_number(int n)
{
  int count,i,temp,j,x;
  temp=0; /*to store prev result*/
  i=n;
  for (count=0;i!=0;count++) /*count digits*/
    i=i/10;
  if (n<0)    /*if neg print '-'*/
    print_char('-');
  do{   /*do loop to work for 0*/
    i=n;
    x=count;
    for(;x>1;x--){  /*start from beginning*/
      i=i/10;
    }
    j=i-(temp*10);  /*subtract prev value*/
    temp=i;        /*save prev value*/
    if (j<0){  /*if neg digit make pos*/
      j=j*(-1);
    }
    print_char(j+48); /*+48 for ascii*/
    count--;
  }
  while(count>0);
}

/*prints character one by one*/
int print_char(char c)
{
  return (write(1, &c, 1));
}
