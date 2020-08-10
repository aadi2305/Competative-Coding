#include <iostream>
#include <vector>
#include <map>
#include <list>
#define ll long long

using namespace std;

int main()
{
    int T;
    cin >> T;
    vector <ll> scammervtr;
    vector <ll> non_scammervtr;
    for(int i = 0; i<T; i++)
    {
        map <int,vector<int>> mp;
        
        ll scammers = 0, non_scammers = 0;
        ll minX, maxX, N;
        cin >> N >> minX>> maxX;
        vector<int> y_vtr;
        for(int k = 0; k<N; k++)
        {
            ll w,b;
            cin >> w >> b;
        }
    
    }
    for(int i = 0; i< T ; i++)  
    {
        cout << non_scammervtr[i] << ' '<<scammervtr[i] << endl;
    }
}