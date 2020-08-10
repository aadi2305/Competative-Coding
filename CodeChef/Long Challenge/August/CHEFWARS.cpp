#include <iostream>
#include <vector>
#include <map>
#include <list>
#define ll long long
#define uli unsigned long int

using namespace std;

int main()
{
    uli T;
    cin >> T;
    for(int k = 0; k<T; k++)
    {
        uli P,H;
        cin >> H >> P;
        if(2*P > H)cout << 1 << endl;
        else cout << 0 << endl;
    }
}