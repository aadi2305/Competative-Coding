#include <iostream>
#include <vector>
#define ll long long
#define for(i,s,e) for(ll i = s; i<e; i++)


using namespace std ;

int main()
{
    ll T ;
    cin >> T;
    for(i, 0, T)
    {
        int N,K, n, lostAmount = 0;
        cin >> N >> K;
        for(j, 0, N)
        {
            cin >> n;
            if(n > K)lostAmount += n - K;
        }
        cout << lostAmount << endl;
    }
    return 0;
}