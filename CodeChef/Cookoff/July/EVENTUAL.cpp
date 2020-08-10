#include <iostream>
#include <vector>
#include <map>
#include <list>
#define ll long long
#define uli unsigned long int

using namespace std;
string solution(int mp[])
{
    for (int i = 0; i<26; i++)
    {
        if(mp[i]%2 != 0)return "NO";
    }
    return "YES";
    
}
int hash_value(char c)
{
    int value, ascii = c;
    value = ascii - 96;
    return value;
}
int main()
{
    int T;
    cin >> T;
    for(int k = 0; k<T; k++)
    {
        int N,hash;
        int mp1[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        string S;
        cin >> N;
        for(int i = 0; i<N; i++)
        {
            char input1;
            cin >> input1;
            hash = hash_value(input1);
            S[i] = input1;
            mp1[hash]++;
        }
        // for (int i = 0; i < 26; i++)
        // {
        //     cout << mp1[i] << endl;
        // }
        
        cout << solution(mp1) << endl;
    }
}