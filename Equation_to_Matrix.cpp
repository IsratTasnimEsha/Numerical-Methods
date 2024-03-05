// BISMILLAHIR RAHMANIR RAHIM

#include <bits/stdc++.h>
using namespace std;

/*
-27x+6y-z=85
6x+16y+2z=72
x+y+54z=110
*/

int main()
{
    ofstream outf1("input.txt");
    for (int i = 0; i < 3; i++)
    {
        string s;
        getline(cin, s);
        outf1 << s << endl;
    }
    outf1.close();

    ifstream inf1("input.txt");
    ofstream outf2("output.txt");
    string s1;
    while (inf1 >> s1)
    {
        int i = 0;
        if (s1[0] >= 'a' && s1[0] <= 'z')
        {
            outf2 << 1 << " ";
            i = 1;
        }
        else if (s1[0] == '-')
        {
            outf2 << "-";
            i = 1;
        }
        for (; i < s1.size(); i++)
        {
            if (s1[i] == '+' || s1[i] == '=')
                outf2 << " ";
            else if (s1[i] == '-')
                outf2 << " -";
            else if ((s1[i] >= 'a' && s1[i] <= 'z') && (s1[i - 1] == '+' || s1[i - 1] == '-'))
            {
                outf2 << 1 << " ";
            }
            else if (s1[i] >= 'a' && s1[i] <= 'z')
                ;
            else if (s1[i] >= '0' && s1[i] <= '9')
                outf2 << s1[i];
        }
        outf2 << endl;
    }
    inf1.close();
    outf2.close();
}