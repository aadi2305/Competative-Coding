#include <iostream>
#include <vector>
#include <map>
#include <list>
#define ll unsigned long int

using namespace std;

int Xgiver(map<ll, ll>Y)
{
    for(auto i= Y.begin();i != Y.end(); i++ )
    {
        if((i->second)%2 != 0)return i->first;
    }
};
int Ygiver(map<ll,ll>X)
{
    for(auto i= X.begin();i != X.end(); i++ )
    {
        if((i->second)%2 != 0)return i->first;
    }
};
int main()
{
    int T;
    cin >> T;
    for(int i = 0; i<T; i++)
    {
        ll N;
        cin >> N;
        map <ll,ll> X;
        map <ll,ll> Y;
        for(int j = 0; j<(4*N-1); j++)
        {
            int x,y;
            cin >> x >> y;
            X[x]++;
            Y[y]++;
        }
        cout << Ygiver(X) << " "<< Xgiver(Y) << endl;      
    }
}