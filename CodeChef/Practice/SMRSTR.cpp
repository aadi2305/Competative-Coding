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
    for(int i = 0; i<T; i++)
    {
        ll N, Q;
        cin >> N >> Q;
        int D[N],X[Q]; 
        for(int j = 0; j<N; j++)
        {
            int input1;
            cin >> input1;
            D[j] = input1;
        }
        for(int j = 0; j<Q; j++)
        {
            int input1;
            cin >> input1;
            int ans = input1;
            for(int k = 0; k<N; k++)
            {
                ans = ans / D[k];
            }
            cout << ans << " ";
        }
        cout << ' ' << endl;
        
        
    }
}