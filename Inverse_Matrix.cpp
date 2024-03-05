// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

/*
4
1 2 3 4
2 8 16 18
3 16 9 12
4 18 16 32
*/

/*
3
1 2 3
2 5 3
1 0 8
*/

int main()
{
    /*
    #ifndef ESHA
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    */

    int n = 4;
    float a[n][n], iden[n][n], fact[n];
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (i == j)
                iden[i][j] = 1;
            else
                iden[i][j] = 0;
        }

    for (int i = 1; i < n; i++) // row
    {
        for (int j = i; j < n; j++)
            fact[j] = (float)a[j][i - 1] / a[i - 1][i - 1];

        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < n; k++) // col
            {
                a[j][k] -= fact[j] * a[i - 1][k];
                iden[j][k] -= fact[j] * iden[i - 1][k];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) // row
    {
        for (int j = 0; j < i + 1; j++)
            fact[j] = (float)a[j][i + 1] / a[i + 1][i + 1];

        for (int j = 0; j < i + 1; j++)
        {
            for (int k = 0; k < n; k++) // col
            {
                a[j][k] -= fact[j] * a[i + 1][k];
                iden[j][k] -= fact[j] * iden[i + 1][k];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        float p = a[i][i];
        for (int j = 0; j < n; j++)
        {
            a[i][j] /= p;
            iden[i][j] /= p;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << iden[i][j] << "\t";
        cout << endl;
    }
}