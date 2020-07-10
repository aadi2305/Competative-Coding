#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <math.h>
#define ll long long

using namespace std;
int getpow(int num, int index)
{
    int ans = 1;
    for (int j = 0; j < index; j++)
    {
        ans = ans* num;
    }
    return ans;  
}
int sumofdigits(int num)
{
    int total= 0, min = 0, i = 1;
    do
    { 
        int j = num% getpow(10, i);
        total+= (j-min) / pow(10, (i-1));   
        i++;
        //cout << "Total: "<< total << ", Min: "<< min << ", i:"<<i << endl;
    }while (num% getpow(10, (i-1))!= num);
    return total;
}
int main()
{
    int T;
    cin >> T;
    for(int i = 0; i<T; i++)
    {
        int N, chefpts= 0, mortypts=0, A,B;
        cin >> N;
        for(int j = 0; j<N; j++)
        {
            cin >> A >> B;
            //cout << "A: "<< sumofdigits(A)<< ", B: "<< sumofdigits(B) << endl;
            if ( sumofdigits(A) > sumofdigits(B)) chefpts++;
            else if(sumofdigits(A) < sumofdigits(B)) mortypts++;
            else 
            {
                chefpts++;
                mortypts++;
            }
            //cout << "Chefpts: "<< chefpts<< ", Mortypts: "<< mortypts << endl;
        }
        if(chefpts > mortypts)cout << 0 << " "<< chefpts<< endl;
        else if(mortypts > chefpts )cout << 1<< " "<< mortypts << endl;
        else cout << 2 <<" "<< chefpts<< endl;
    }

}