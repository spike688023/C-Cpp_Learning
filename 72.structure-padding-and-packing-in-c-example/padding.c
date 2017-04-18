//#include <iostream>
#include <stdio.h>

//using namespace std;

struct school
{
	double a = 0;
	int b = 1;
	char h = '1';	
	int c;
	char d;	
};

int main()
{
	school students;
	
	printf("size of double %d \n",sizeof(students.a));
	printf("size of int %d \n",sizeof(students.b));
	printf("size of char %d \n",sizeof(students.h));
	printf("size of struct %d \n",sizeof(students));
	return 0;
	
}
