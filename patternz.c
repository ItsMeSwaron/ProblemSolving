#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int m = 2*n - 1;

    char arr[n][m];
    
    // for(int i=0;i<n;i++)
    // {
    //     int tmp = 1;
        
    //     for(int j=0;j<n;j++)
    //     {
    //         arr[i][j] = tmp;
    //         printf("%d", arr[i][j]);
    //         tmp++;
    //     }
    //     printf("\n");
    // }

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         printf("%d", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            arr[i][j] = '*';
        }
    }

    // for(int i=0;i<n;i++)
    // {   
    //     for(int j=0;j<n;j++)
    //     {
    //         if(i == n/2)
    //         {
    //             arr[i][j] = 'H';
    //         }
    //         else if(j == 0 || j == n-1)
    //         {
    //             arr[i][j] = 'H';
    //         }
    //     }
    // }

    int skipFirst = 1;
    int skipLast = m-2;
    
    for(int i=n-2;i>=0;i--)
    {   
        for(int j=0;j<skipFirst;j++)
        {
            arr[i][j] = ' ';
        }

        for(int j=m-1;j>skipLast;j--)
        {
            arr[i][j] = ' ';
        }

        skipFirst++;
        skipLast--;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}