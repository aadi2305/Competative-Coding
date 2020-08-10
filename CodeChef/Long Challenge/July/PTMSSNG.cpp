    #include <iostream>
    #include <vector>
    #include <map>
    #include <list>
    #include <algorithm>
    #define ll unsigned long int

    using namespace std;

    int Xgiver(map<ll, ll>Y)
    {
        auto i = Y.begin();
        return i->first;

    };
    int Ygiver(map<ll,ll>X)
    {
        auto i = X.begin();
        return i->first;
    };
    int main()
    {
        int T;
        cin >> T;
        for(int i = 0; i<T; i++)
        {
            ll N;
            cin >> N;
            map <ll,ll> X;
            map <ll,ll> Y;
            for(int j = 0; j<(4*N-1); j++)
            {
                int x,y;
                cin >> x >> y;
                if(X[x]!= 1)X[x]=1;
                else X.erase(x);
                if(Y[y]!=1)Y[y]=1;
                else Y.erase(y);

            }
            cout << Ygiver(X) << " "<< Xgiver(Y) << endl;      
        }
    }