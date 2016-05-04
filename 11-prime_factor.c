#include <unistd.h>
int print_char(char c);
void print_number(long n);
/*main function*/
int main()
{
  long number,div, largest;
  largest=0;/*initialize to zero*/
  number=612852475143; /*the predefined number*/
  /*checks from 2*/  
  div = 2;
  /*start loop until number !=0 */  
  while(number!=0){
    if(number%div!=0) /*check next if remainder isnt 0*/
      div = div + 1; /*add 1*/
    else {
      number = number / div;
      if (div>largest) largest=div; /*find largest*/
      if(number==1) /*break when number reaches 1*/
	break;
    }
  }
  print_number(largest);/*print largest*/
  print_char('\n'); /*print new line*/
  return 0;
}

/*prints number one by one*/
void print_number(long n)
{
  long count,i,temp,j,x;
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
