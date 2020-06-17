#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b,c,d,T;
    T = 1;
    //cin >> T;
    cin >> a,b,c,d;
    while(a != b && a<b)
    {
        if(c>d)
        {
            a =a + c;
            b =b+  d;
        }
        else if(c<d)
        {
            a =a + d;
             b =b+  c;
        }
        else cout << "NO" << endl;
        
    }
    cout << "a: " << a<< ", b:" << b << endl; 
    if(a == b) cout << "YES" << endl;
    else
    {
        if( c != d)cout << "NO" << endl;
    }
    return 0;
}