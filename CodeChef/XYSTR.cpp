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
        string S;
        cin >>S;
        int pairs = 0, length = S.length();
        for(j, 0, length)
        {
            if(S[j]== 'x')
            {
                if(S[j+1] == 'y') 
                {
                    pairs++;
                    j++;
                    continue;
                }
            }
            else if(S[j] == 'y')
            {
                if(S[j+1] == 'x') 
                {
                    pairs++;
                    j++;
                    continue;
                }
            }
        }
        cout << pairs << endl;  

    }
    return 0;
}