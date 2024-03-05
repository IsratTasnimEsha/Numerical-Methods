//Secant Method
#include<bits/stdc++.h>
using namespace std;

#define Er 0.0001

//function f(x) = x^2 - 4x - 10;

double f(double x)
{
    return x*x-4*x-10;
}

int main()
{
    double x1,x2,x0;
    int step=0;

    cout<<"Enter two inital value: ";
    cin>>x1>>x2; //0 6

    while(1)
    {

        cout<<"x1 = "<<x1<<"\n";
        cout<<"x2 = "<<x2<<"\n";
        cout<<"f(x1) = "<<f(x1)<<"\n";
        cout<<"f(x2) = "<<f(x2)<<"\n";

        x0=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
    	cout<<"x = "<<x0<<"\n";

        if(abs(((x0-x2)/x0))<=Er)break;
        else{
            x1=x2;
    	    x2=x0;
        }
        step++;

        cout<<endl<<endl;

    }
    cout<<"Result: "<<x0<<" after no. of "<<step<<" steps"<<endl;
}