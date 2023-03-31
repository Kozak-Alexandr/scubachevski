#include <stdio.h>
#include <stdlib.h>

void function(int array[], int N)
{
for(int i=0; i < N; i++)
    if (array[i] % 2 == 0)
    {
        array[i] = array[i] * 2;
    }
    else
    {
        array[i] = array[i] +2;
    }
}

int main () 
{
    int N = 0;
    scanf("%d", &N);
    int* array = (int*)calloc(N, sizeof(int));
    for(int i=0; i < N; i++)
    scanf("%d", &array[i]);
    function(array, N);
    for( int i = 0; i<N; i++)
    printf("%d", array[i]);
    free(array);

}



