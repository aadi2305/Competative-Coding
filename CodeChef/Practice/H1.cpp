#include <iostream>
#include <vector>
#include <map>
#include <list>
#define ll long long

using namespace std;
vector <int> idealvtr = {1,2,3,4,5,6,7,8,9};
bool isPrime[17] = {0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1};
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
int rearrange(vector <int> vtr)
{
    
};
int main()
{
    int T;
    cin >> T;
    
    for(int i = 0; i<T; i++)
    {
        vector <int> vtr;
        int input;
        for (int i = 0; i < 9; i++)
        {
            cin >> input;
            vtr.push_back(input);
        }
        cout << rearrange(vtr) << endl;
    }
}