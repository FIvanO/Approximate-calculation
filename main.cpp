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

bool getX(double &x)
{
    cout << "Enter x from (-pi/2; pi/2):" << endl;
    if (cin >> x) return true;
    else return false;
}
