#include <iostream>
#include <vector>
#include <map>
#define for(i,s,e) for(long long i = s; i<e; i++)

using namespace std ;
map<long long,long long> m; 
bool changes(long long money)
{
    if(money == 15)
    {
        if(m[10]>0)m[10] -= 1;
        else if(m[5]> 1) m[5] -= 2;
        else return false;
    }
    else if(money == 10)
    {
        if(m[5]> 0)m[5] -=1;
        else return false;
        m[10] +=1;
    }
    else if(money == 5)
    {
        m[5] +=1;
        return true;
    }

    return true;
};
bool YesOrNo(vector<long long> vtr, long long N)
{
    
    m[15] = 0;
    m[5] = 0;
    m[10] = 0;
    for(i,0, N)
    {
        bool ToF = changes(vtr[i]);
        if(ToF == false) return false;
    }
    return true;
};
int main()
{
    long long T ;
    cin >> T;
    for(i, 0, T)
    {
        long long N;
        vector <long long> vtr;
        cin >> N;
        for(j, 0, N)
        {
            long long input;
            cin >> input;
            vtr.push_back(input);
        }
        bool YoN = YesOrNo(vtr, N);
        if(YoN == false)cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}