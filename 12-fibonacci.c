#include <stdio.h>
void p_number();
void come_on_print_it();

int c, l1, m1, r1, l2, m2, r2, nl, nm, nr;

int main(){
	int i;
	r2=1;
	for (i=0; i<=98; i++){
		p_number();
		come_on_print_it();
		if (i<98) printf(", ");
	}
	printf("\n");
	return 0;
}



void p_number(){
	nr=r2+r1;
	nm=m2+m1;
	nl=l2+l1;
	if (nr>999999999){
		c=nr/1000000000;
		nr=nr%1000000000;
		nm=nm+c;
	}
	if (nm>999999999){
		c=nm/1000000000;
		nm=nm%1000000000;
		nl=nl+c;
	}
	l1=l2;
	m1=m2;
	r1=r2;
	l2=nl;
	m2=nm;
	r2=nr;
}

void come_on_print_it(){
	if (nl>0) printf("%d%d%d", nl, nm, nr);
	else if (nm>0) printf ("%d%d", nm, nr);
	else printf("%d", nr);
}