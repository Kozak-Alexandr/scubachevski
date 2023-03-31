#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int sizeout = 0;
    char out[1 << 17];

    int npoints = 0;
    char col[1 << 17];
    char x[1 << 17];
    char y[1 << 17];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int command = 0;
        scanf("%d", &command);
        if(command == 1)
        {
            scanf("%d %d %c", &x[npoints], &y[npoints], &col[npoints]);
            npoints++;
            
        }
        else
        {
            int xx = 0;
            int yy = 0;
            scanf("%d %d", &xx, &yy);
            out[sizeout] = 'N';
            for(int k = 0; k < npoints; k++)
            {
                if(x[k] == xx && y[k] == yy)
                {
                    out[sizeout] = col[k];
                }    
            }
            sizeout++;
        }
    }
    for(int i = 0; i < sizeout; i++ )
    {
        printf("%c\n", out[i]);
    }
    
}