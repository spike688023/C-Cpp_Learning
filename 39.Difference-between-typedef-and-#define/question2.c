#include <stdio.h>

typedef struct p
{
    int x, y;
};

int main()
{
    p k1 = {1, 2};
    printf("%d\n", k1.x);

return 0;
}
