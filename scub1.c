#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double a = 0;
    double b = 0;
    scanf("%lg %lg", &a, &b);
    if(a != b)
    {
        if(a >= b)
        {
            printf("%lg", a-b);
        }
        else
        {
            printf("%lg", b-a);
        }
    }
    else printf("o");
}
