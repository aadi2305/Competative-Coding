#include <iostream>
#include <vector>
#include <map>
#include <list>
#define ll long long
#define uli unsigned long int

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int k = 0; k<T; k++)
    {
        int K,N;
        map <int,vector <int>> m;
        cin >> N >> K;
       for(int i = 0; i<N; i++)
       {
            int input1, var2;
            cin >> input1;
            var2 = K-input1;
            if(var2 % input1 == 0)
            {
                int var3 = var2 / input1;
                if(var3 < 0)var3 = var3*(-1);
                m[var3].push_back(input1);
            }
       }
       if(m.empty())cout << -1 << endl;
       else
       {
            cout << m.begin()->second[0] << endl; 
       }
       
       
       
    }
}