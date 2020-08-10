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
        for(int k = 0; k<N; k++)
        {
            ll w,b;
            cin >> w >> b;
            mp[k].push_back(w);
            mp[k].push_back(b);
        }
        for(int k = minX; k<=maxX; k++)
        {
            ll y;
            ll temp = k;
            for(int j = 0; j<N; j++)
            {
                y = (mp[j][0]*temp)+mp[j][1];
                temp = y;
            }
            cout << "temp: " << temp << endl;
            if(temp %2 == 0) non_scammers++;
            else if(temp %2 != 0) scammers++;
        }
        scammervtr.push_back(scammers);
        non_scammervtr.push_back(non_scammers);
    }
    for(int i = 0; i< T ; i++)  
    {
        cout << non_scammervtr[i] << ' '<<scammervtr[i] << endl;
    }
}