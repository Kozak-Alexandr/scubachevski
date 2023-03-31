 

/*void function(int array[], int N, int sum)
{
for(int i=0; i < N; i++)
    {
        sum = sum + array[i];
    }

}*/

int main () 
{
    int N = 0;
    int sum = 0;
    scanf("%d", &N);
    int* array = (int*)calloc(N, sizeof(int));
    for(int i=0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    //function(array, N, sum);
    
    for(int i=0; i < N; i++)
    {
        sum = sum + array[i];
    }
   // printf("%d", sum);
    for( int i = 0; i<N; i++)
    {
    array[i] = sum / N;
    printf("%d", array[i]);
    }

    free(array);

}