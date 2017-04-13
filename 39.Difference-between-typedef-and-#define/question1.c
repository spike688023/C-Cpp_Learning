#include <stdio.h>

typedef struct student
{
    char a;
}stu;

void main()
{
    struct student s;
    s.a = "hey\n";
    printf("%s", s.a);
}
