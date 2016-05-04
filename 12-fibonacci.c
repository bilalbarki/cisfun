#include <stdio.h>
/*my functions*/
void p_number();
void come_on_print_it();
/*global variables*/
int c, l1, m1, r1, l2, m2, r2, nl, nm, nr;
/*global variables are already initialized to zero*/
/*main function*/
int main(){
	int i;
	r2=1;	/*initialize*/
	for (i=1; i<=98; i++){	/*loop for 98 fibonacci numbers*/
		p_number();
		come_on_print_it();
		if (i<98) printf(", ");	/*commas, dont print for last*/
	}
	printf("\n");
	return 0;
}


/*calculates fibonacci number*/
void p_number(){
	nr=r2+r1; /*add all right */
	nm=m2+m1;	/*add all middle*/
	nl=l2+l1;	/*add all left*/
	if (nr>999999999){	/*if overflow*/
		c=nr/1000000000; /*c is carry*/
		nr=nr%1000000000;
		nm=nm+c;
	}
	if (nm>999999999){	/*if overflow*/
		c=nm/1000000000;
		nm=nm%1000000000;
		nl=nl+c;
	}
	/* move to next numbers in fibonacci series*/
	l1=l2;
	m1=m2;
	r1=r2;
	l2=nl;
	m2=nm;
	r2=nr;
}

void come_on_print_it(){ /*prints the numbers*/
	if (nl>0) printf("%d%d%d", nl, nm, nr);
	else if (nm>0) printf ("%d%d", nm, nr);
	else printf("%d", nr);
}