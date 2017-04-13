#include<stdio.h>

typedef char* charPtr_t;
#define charPtr_d char*

int main()
{
charPtr_t a,b;
charPtr_d x,y;
char *test;
int *test2;

printf("%d,%d,%d,%d\n",sizeof(a),sizeof(b),sizeof(x),sizeof(y));
printf("%d\n",sizeof(test));
printf("%d\n",sizeof(test2));

return 0;
}
