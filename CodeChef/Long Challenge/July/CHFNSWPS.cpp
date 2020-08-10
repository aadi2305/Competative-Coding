#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#define ll long long
#define uli unsigned long int

using namespace std;
int solution(ll A[], ll B[],uli N, map<int,int>A1, map<int,int>B1)
{
    vector <int> A2,B2;
    int size1 = 0,size2 = 0, total = 0, prevA = 0, prevB = 0;
    for(int i = 0; i<N; i++)
    {
        if((A1[A[i]]+B1[A[i]])%2 != 0)return(-1);
        if((A1[B[i]]+B1[B[i]])%2 != 0)return(-1);
        if(A1[A[i]] != B1[A[i]] && prevA != A[i])
        {

            prevA = A[i];
            int n = (A1[A[i]]-B1[A[i]])/2;
            if(n<0)
            {
                n = n*(-1);
                // cout << "For "<< A[i]<< " n: "<< n << endl;
                for (int j = 0; j < n; j++)
                {
                    A2.push_back(A[i]);
                    size1++;
                    // cout << A[i] << " Pushed Back in A2"<< ", Size1: "<< size1 << endl;
                }
            }   
        } 
        if(A1[B[i]] != B1[B[i]] && prevB != B[i])
        {
            prevB = B[i];
            int n = (B1[B[i]]-A1[B[i]])/2;
            
            if(n<0)
            {
                cout << "Here" << endl;
                n = n*(-1);
                // cout << "For "<< B[i]<< " n: "<< n << endl;
                for (int j = 0; j < n; j++)
                {
                    B2.push_back(B[i]);
                    size2++;
                    // cout << B[i] << " Pushed Back in B2"<< ", Size2: "<< size2 << endl;
                }
            }   
        }            
    }
    cout << "A2: " << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << A2[i] << ' ';
    }
    cout << "B2: " << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << B2[i] << ' ';
    }
    cout << endl;
    // cout << size1 << size2 << endl;
    if(size1 = 0)return 0;
    for(int e = 0; e<A2.size(); e++)
    {
        //cout << "A2[e]: " << A2[e] << ", B2[size2 - 1- e]: " << B2[size2 - 1- e] << endl; 
        if(A2[e]> B2[size2 - 1- e])total += B2[size2 - 1- e];
        else if(A2[e]< B2[size2 - 1- e])total += A2[e];
        else{
            total+= A2[e];
        }
    }
    return total;
    
};
int main()
{
    int T;
    cin >> T;
    for(int k = 0; k<T; k++)
    {
        uli N;
        cin >> N;
        ll A[N];
        ll B[N];
        map <int, int> A1,B1;
        for (int i = 0; i < N; i++)
        {
            int input1;
            cin>> input1;
            A[i]= input1;
            A1[input1]++;
        }
        for (int i = 0; i < N; i++)
        {
            int input1;
            cin>> input1;
            B[i]= input1;
            B1[input1]++;
        }
        sort(A, A+N);
        sort(B, B+N);
        cout << "A: " << endl;
        for(auto it = A1.begin(); it!= A1.end(); it ++)
        {
            cout << it->first << ' '<< it->second<< endl;
        }
        cout << "B: " << endl;
        for(auto it = B1.begin(); it!= B1.end(); it ++)
        {
            cout << it->first << ' '<< it->second<< endl;
        }
        cout << solution(A,B,N,A1,B1) << endl;
    }
}