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
        uli N,Q;
        cin >> N >> Q;
        map <uli, vector <ll>> m1;
        map <uli, vector <int>> m2;
        for (int i = 1; i <= N; i++)
        {
            int input1;
            cin >> input1;
            m1[i].push_back(input1);
        }
        for (int i = 1; i <= N; i++)
        {
            int input1;
            cin >> input1;
            m1[i].push_back(input1);
        }
        for (auto it = m1.begin(); it!= m1.end();it++)
        {
            int prev = (it->second)[0] ,z = 0;
            cout << "prev: " << prev << endl;
            if(it->first == 1)
            {
                
                for (int j = 2; j <=N ; j++)
                {
                    if(m1[j][0]<=prev)
                    {
                        z = 1;
                        // cout << m1[j][0] << " Pushed Back at" << it->first << endl;
                        m2[it->first].push_back(j);
                        prev = m1[j][0];
                    }
                    else
                    {
                        if(z==0){
                        m2[it->first].push_back(0);
                        break;
                        }
                        else if(z ==1)
                        {
                            z = 0;
                            break;
                        }
                    }
                }
                // cout << m2[1][0] << endl;
                // cout << z << endl;
            }
            else
            {
                //cout << "it->first: "<< it->first << endl;
                for (int j = (it->first)-1 ; j> 0; j--)
                {
                    if(m1[j][0]<=prev)
                    {
                        cout << j << " Pushed Back at" << it->first << endl;
                        m2[it->first].push_back(j);
                        prev = m1[j][0];
                        z = 1;
                    }
                    else
                    {
                         if(z==0)
                        {
                        m2[it->first].push_back(0);
                        break;
                        }
                        else if(z ==1)
                        {
                            z = 0;
                            break;
                        }
                    }
                }
                prev = (it->second)[0];
                for (int j = (it->first)+1; j <=N ; j++)
                {
                    if(m1[j][0]<=prev)
                    {
                        // cout << m1[j][0] << " Pushed Back at" << it->first << endl;
                        m2[it->first].push_back(j);
                        prev = m1[j][0];
                        z =1;
                    }
                    else
                    {
                         if(z==0){
                        m2[it->first].push_back(0);
                        break;
                        }
                        else if(z ==1)
                        {
                            z = 0;
                            break;
                        }
                    }
                    
                }
            }
        }
        for(auto it = m2.begin(); it!= m2.end(); it++)
        {
            cout << it->first << ": ";
            for (int i = 0; i < (it->second).size(); i++)
            {
                cout << (it->second)[i] << ", ";
            }
            cout << endl; 
        }
        
          
    }
}