#include<stdio.h>
 
int main()
{
	char z = 'A';
	char y;
	
	const char * const p = &z; 	// Both address and value cannot be changed, Initialized at declaration time
	
	/* Invalid, gives compier error "assignment of read-only variable p" */
	// p = &y;					// Can't change pointer, Need to initialize at declaration time

	/* Invalid, gives compier error "assignment of read-only location *(const char*)p" */
	// *p = 'B'; 				// Can’t change pointed characters
	
	printf(" %c \n",*p);
		
	return 0;
}
