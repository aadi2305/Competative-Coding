#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <string> generate(int s)
{
    vector <string> vect ;


};
void print(vector <string> vect)
{
    for(auto it = vect.begin(); it != vect.end(); it++)
    {
        cout << *it << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector <string> generated_vect = generate(n);
    print(generated_vect);
}

