#include<stdio.h>
 
int main()
{
	char z = 'A';
	char y;
		
	const char *p = &y; // Can’t change pointed characters using pointer, can change pointer
		
	p = &z;
	
	/* Invalid, gives compier error "assignment of read-only location *p" */
	// *p = 'B';		// You can’t change pointed characters using pointer
	
	printf(" %c \n",*p);
        // *p = 'B';  Here will be come to a compiler erro
		
	return 0;
}
