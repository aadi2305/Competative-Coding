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
        ll N;
        int total = 0,prev;
        cin >> N;
        vector <int> S[N];
        for(int j = 0; j<N; j++)
        {
            ll input1;
            cin >> input1;
            if (j == 0) 
            {
                prev = input1;
            }
            else
            {
                int add;
                if (input1 > prev)add = input1 - 1 - prev;
                else if(input1 < prev)
                {
                    add = input1 + 1 - prev;
                    add = add*(-1);
                }
                else add = 0;
                total += add;
                prev = input1;
            }
        }
        cout << total << endl;
    }
}