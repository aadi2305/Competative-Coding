#include <iostream>

using namespace std;

int main()
{
    int n,p, target,k=0;
    cin >> n;
    int arr1[n];
    for(int i = 0; i<n; i++)
    {
        cin >> p;
        arr1[i]= p;
    }
    cin >> target;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr1[i]+arr1[j] == target)
            {
                cout << i <<" "<< j<< endl;
                k = 1;
                break;
            }
        }
        if(k ==1)
        {
            break;
        }
    }

}