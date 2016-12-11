// FIvanO
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include<iomanip>
#include <map>
#include <deque>
#define mp(x,y) make_pair(x,y)

using namespace std;

bool getX(double &x); // введення х
double f_Sum(double x, int &n1, int &n2); //обчислення сумми
double f_fract(double x, int &it); // обчислення бібл.
void outHead(); // виведення заголовку
void outVal(double x, double f_F, double f_S, double dif, int it, int n1, int n2); // виведення значень

int main()
{
    ios_base::sync_with_stdio(0);

    double x;
    int n1 = -2, n2 = -2, it = 0;
    #define L 15
    while (getX(x))
    {
        double f_S = f_Sum(x, n1, n2);
        double f_F = f_fract(x, it);
        double dif = fabs(f_S - f_F);
        outHead();
        outVal(x, f_F, f_S, dif, it, n1, n2);
    }


}

void outHead() // виведення заголовку
{
    cout.width(L); cout<<"x";
    cout.width(L); cout<<"f_fract(x)";
    cout.width(L); cout<<"f_sum(x)";
    cout.width(L); cout<<"difference";
    cout.width(L); cout<<"N_adds1";
    cout.width(L); cout<<"N_adds2"<<endl;
}

void outVal(double x, double f_F, double f_S, double dif, int it, int n1, int n2) // виведення значень
{
    cout.width(L); cout<<x;
    cout.width(L); cout<<f_F;
    cout.width(L); cout<<f_S;
    cout.width(L); cout<<dif;
    cout.width(L); cout<<n1;
    cout.width(L); cout<<n2<<endl;
}

double f_Sum(double x, int &n1, int &n2) //обчислення сумми
{
    const double eps = 10e-20;
    double a = x;
    double sinx = x;
    double cosx = 1;
    double chisl = x;
    double znam = 1;
    double d = x * x;

    n1 = 0;

    while(fabs(a) > eps)
    {
        n1 ++;
        chisl *= d;
        znam *= 2*n1 * (2 * n1 + 1);
        a = chisl / znam;
        if ( n1 % 2 == 1) a *= -1;
        sinx += a;
    }
        cout << "sinMine(" << x << ") = " << sinx << endl;
        cout << "sinLib(" << x << ") = " << sin(x) << endl;

    a = 1;
    chisl = 1;
    znam = 1;
    n2 = 0;

    while(fabs(a) > eps)
    {
        n2 ++;
        chisl *= d;
        znam *= (2 * n2 - 1) * 2 * n2;
        a = chisl / znam;
        if ( n2 % 2 == 1) a *= -1;
        cosx += a;
    }
        cout << "cosMine(" << x << ") = " << cosx << endl;
        cout << "cosLib(" << x << ") = " << cos(x) << endl;

    return sinx / cosx;
}

double f_fract(double x, int &it) // обчислення ланц.
{
    const double eps = 1e-8;
    double p = 3 * x;
    double p1 = x;
    double p2 = 3 * x;
    double q = - x * x + 3;
    double q1 = 1;
    double q2 = - x * x + 3;
    double a = - x * x;
    double n = 0;
    double b = 3;

    it = 2;

    while ( fabs( p2 / q2 - p1 / q1 ) > eps)
    {
        it ++;
        b += 2;
        p = b * p2 + a * p1;
        q = b * q2 + a * q1;
        p1 = p2;
        q1 = q2;
        p2 = p;
        q2 = q;
    }
    return p / q;
}

bool getX(double &x)
{
    cout << "Enter x from (-pi/2; pi/2):" << endl;
    if (cin >> x) return true;
    else return false;
}
