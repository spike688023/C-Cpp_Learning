#include<stdio.h>
 
int main()
{
	char z;
	char y;
		
	/* Invalid, gives compier error "uninitialized const p" */
	// char * const p;		// Need to initialize at declaration time
	
	char * const p = &z; 	// Address cannot be changed, Must be initialize at declaration time

    *p = 'A';			

	/* Invalid, gives compier error "assignment of read-only variable p" */
	// p = &y;				// const pointer can't be change, must be initialize at declaration time
	
	printf(" %c \n",*p);
		
	return 0;
}
