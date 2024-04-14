#include <bits/stdc++.h>
using namespace std;

int b[7][6];

void print1(int b[7][6],char x[],int i ,int j)
    {
        if(i==0 ||  j==0)
        {
            return;
        }
        if(b[i][j]==0)
        {
            print1(b,x,i,j);
            cout<<x[i];
        }
        else if(b[i][j]==1)
        {
            print1(b,x,i-1,j);
        }
        else
        {
            print1(b,x,i,j-1);
        }
    }
int lcs(char x[], char y[])
{
    int m, n;
    m = strlen(x);
    n = strlen(y);
    //int b[m][n];
    int c[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j]=0;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j]=1;
               
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j]=-1;
            }
        }
    }
    


    return c[m][n];
}

int main()
{
    char x[] = "ABCBDAB";
    char y[] = "BDCABA";
    cout << lcs(x, y);
    print1(b,x,7,6);
   
    return 0;
}