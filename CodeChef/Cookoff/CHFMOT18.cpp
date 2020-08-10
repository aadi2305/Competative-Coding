#include <iostream>
#include <vector>
#include <map>
#include <list>
#define ll long long
#define uli unsigned long int

using namespace std;
int solution(ll S,ll N)
{
    uli total = 0;
    if(S>N)
    {
        uli remainder = S%N;
        total += (S-remainder)/N;
        if (remainder == 0)return total;
        else if(remainder ==1) total +=1;
        else if(remainder %2 == 0)total += 1;
        else if(remainder %2 != 0)total += 2;
    }
    else if(S == N)return 1;
    else
    {
        if(S%2 == 0)return 1;
        else if(S == 1)return 1;
        else if(S%2 != 0)return 2;
    }
    
    return total;
}
int main()
{
    int T;
    cin >> T;
    for(int k = 0; k<T; k++)
    {
       ll S,N;
       cin >> S >> N;
       cout << solution(S,N) << endl; 
    }
}