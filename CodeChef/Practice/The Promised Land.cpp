#include <iostream>

using namespace std;
int number_finder(int x, int y, int S)
{
    while(x % S != 0)
    {
        x--;
    }
    while(y % S != 0)
    {
        y--;
    }
    x = x/S;
    y = y/S;
    return x*y;
}
void print_list(int arr[], int size)
{
    cout << "[";
    for(int i = 0; i<size ; i++)
    {
        cout << arr[i] <<", ";
    }
    cout << "]"<< endl;
}
int main()
{
    int TestCases;
    cin >> TestCases;
    int ans[TestCases];
    for(int i= 0 ; i<TestCases ; i++)
    {
        int N,M,X,Y,S, no_boxes, total = 0;
        cin >> N >> M;
        cin >> X >> Y >>S;
        int X_arr[X], Y_arr[Y];
        X ++;
        Y++;
        for(int j=0 ; j <X ; j++)
        {
            if(j ==X-1)
            {
                X_arr[j] = N+1;
            }
            else cin >> X_arr[j];
        }
        for(int j=0 ; j <Y ; j++)
        {
            if(j == Y-1)
            {
                Y_arr[j] = M+1;
            }
            else cin >> Y_arr[j];
        }
        //cout <<"X: "<< X << ", Y: "<<Y<< endl;
        //cout<<"X: ";
        //print_list(X_arr, X);
        //cout<<"Y: ";
        //print_list(Y_arr, Y);
        no_boxes = (X+1)*(Y+1);
        int x, y;
        for(int j = 0 ; j< X ; j++)
        {
            for(int k = 0 ; k< Y; k++)
            {   
                if(k == 0)
                {
                    if(j == 0)
                    {
                        x = X_arr[j]-1;
                        y = Y_arr[k]-1;
                        total += number_finder(x, y, S);
                    }
                    else if(j !=0 && j!= X-1)
                    {
                        x = X_arr[j] - X_arr[j-1] - 1;
                        y = Y_arr[k]-1;
                        total += number_finder(x, y, S);
                    }
                    else if( j == X-1)
                    {
                        x = N- X_arr[j-1];
                        y = Y_arr[k]-1;
                        total += number_finder(x, y, S);
                    }
                    
                }
                else if(k != 0 && k !=Y-1)
                {
                    if(j == 0)
                    {
                        x = X_arr[j]-1;
                        y = Y_arr[k] - Y_arr[k-1] -1;
                        total += number_finder(x, y, S);
                    }
                    else if(j !=0 && j!= X-1)
                    {
                        //cout << "Here" << endl;
                        //cout<<"k: "<< k<< endl;
                        //cout<<"j: "<< j<< endl;
                        y = Y_arr[k] - Y_arr[k-1] -1; 
                        x = X_arr[j] - X_arr[j-1] - 1;
                        total += number_finder(x, y, S);
                    }
                    else if(j == X-1)
                    {
                        y = Y_arr[k] - Y_arr[k-1] -1;
                        x = N - X_arr[j-1];
                        total += number_finder(x, y, S);
                    }
                }
                else if(k == Y-1)
                {
                    if(j == 0)
                    {
                        x = X_arr[j]-1;
                        y = M - Y_arr[k -1];
                        total += number_finder(x, y, S);
                    }
                    else if(j !=0 && j!= X-1)
                    {
                        y = M - Y_arr[k -1]; 
                        x = X_arr[k] - X_arr[k-1] - 1;
                        total += number_finder(x, y, S);
                    }
                    else if(j == X-1)
                    {
                        y = M - Y_arr[k -1];
                        x = N - X_arr[j-1];
                        total += number_finder(x, y, S);
                    }
                }
            //cout << "X_arr: "<< X_arr[j] << ", x: "<< x<<", Y_arr: " << Y_arr[k] << ", y: "<< y<< ", total: "<< total<< endl; 
            }
        }
    ans[i] = total; 
    }
    for(int i = 0; i<TestCases ; i++)
    {
        cout << ans[i]<< endl;
    }
 
}