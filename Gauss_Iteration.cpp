// BISMILLAHIR RAHMANIR RAHIM

#include <bits/stdc++.h>
using namespace std;

/*
27a+6b-c-8d=85
6a+15b+2c+7d=72
a+b+54c-d=110
a+2b+8c-5d=122
*/

int main()
{
    //..........................<<Equation to Matrix>>..........................
    int n = 4;
    float a[n][n + 1];
    cout << "Equations?" << endl;

    for (int j = 0; j < n; j++)
    {
        string s, st[n], con;
        char var[n];
        getline(cin, s);
        int i = 0;
        bool fvar[n] = {false};

        for (int k = 0; k < n; k++)
            var[k] = k + 'a';

        for (int k = 0; s[k] != '\0'; k++)
            for (int l = 0; l < n; l++)
                if (s[k] == var[l])
                    fvar[l] = true;

        for (int l = 0; l < n; l++)
        {
            int c = 0;
            if (fvar[l] == false)
                st[l] += '0';
            else
            {
                for (; s[i] != var[l]; i++)
                {
                    if (s[i] == '-')
                        st[l] += s[i];
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        c++;
                        st[l] += s[i];
                    }
                }
                if (c == 0)
                    st[l] += '1';
            }
            a[j][l] = stoi(st[l]);
        }

        for (; s[i] != '\0'; i++)
            if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
                con += s[i];

        a[j][n] = stoi(con);
    }

    cout << endl
         << "Augmented Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    //..........................<<Gauss Iteration>>..........................

    float v[n] = {0.0};

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            float temp = 0.0;
            for (int j = 0; j < n; j++)
                if (j != i)
                    temp += a[i][j] * v[j];
            v[i] = 1.0 / a[i][i] * (a[i][n] - temp);
        }

        cout << "Iteration " << k + 1 << ":\t";
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }

    cout << endl
         << "Final Result:\t";
    for (int i = 0; i < n; i++)
        cout << v[i] << "   ";
}