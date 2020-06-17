#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <sstream> 

using namespace std;

int countDigit(long long n) 
{ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
} 

long int reverse(long int x)
{
    stack <int> stck;
    int length = countDigit(x);
    for(int i = 0; i< length ; i++)
    {
        stck.push(x / (10*(i-1))%10);
    }

}

int main()
{
    long int number;
    int length = countDigit(number);
    cin >> number;
    for(int i = 0; i< length ; i++)
    {
        int power = pow(10,i);
        cout<<  power;
    }
    return 0;
     
}