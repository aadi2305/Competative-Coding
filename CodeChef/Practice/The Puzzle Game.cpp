#include <iostream>

using namespace std;

bool isPrime(int number)
{
    if(number == 2)return true;
    else if(number % 2 != 0)
    {
        int half = (number /2)+1;
        for(int i = 2; i< half; i++)
        {
            if(number % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    
    
}

int main()
{
    int number= 5 ;
    cout << isPrime(97) << endl;
    return 0;
}