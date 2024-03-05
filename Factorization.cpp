// BISMILLAHIR RAHMANIR RAHIM

#include <bits/stdc++.h>
using namespace std;

/*
2x+3y+z=9
x+2y+3z=6
3x+y+2z=8
*/

int main()
{
    int n = 3;
    float a[n][n + 1];
    cout << "Equations?" << endl;

    ofstream outf("input.txt");

    for (int j = 0; j < n; j++)
    {
        string s;
        getline(cin, s);
        outf << s << endl;
    }
    outf.close();

    ifstream inf("input.txt");

    string s;
    int j = 0;

    while (inf >> s)
    {
        j++;
        string st[n], con;
        char var[n];
        int i = 0;

        for (int k = 0; k < n; k++)
            var[k] = k + 'x';

        for (int l = 0; l < n; l++)
        {
            int c = 0;
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

            a[j][l] = stoi(st[l]);
        }

        for (; s[i] != '\0'; i++)
            if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
                con += s[i];

        a[j][n] = stoi(con);
    }

    cout << endl
         << "Augmented Matrix: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    float u11, u12, u13, u21, u22, u23, u31, u32, u33, l21, l31, l32;
    u11 = a[1][0], u12 = a[1][1], u13 = a[1][2];
    l21 = a[2][0] / u11;
    u22 = a[2][1] - l21 * u12;
    l31 = a[3][0] / u11;
    u23 = a[2][2] - l21 * u13;
    l32 = (a[3][1] - l31 * u12) / u22;
    u33 = a[3][2] - l31 * u13 - l32 * u23;

    cout << endl
         << "Lower Matrix: " << endl;
    cout << 1 << "\t" << 0 << "\t" << 0 << endl
         << l21 << "\t" << 1 << "\t" << 0 << endl
         << l31 << "\t" << l32 << "\t" << 1 << endl;

    cout << endl
         << "Upper Matrix: " << endl;
    cout << u11 << "\t" << u12 << "\t" << u13 << endl
         << 0 << "\t" << u22 << "\t" << u23 << endl
         << 0 << "\t" << 0 << "\t" << u33 << endl;
}