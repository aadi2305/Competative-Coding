#include <iostream>
#include <stack>
using namespace std;

bool solution(string code )
{
    stack <char> stck;
    for(int i = 0; i<code.length(); i++)
    {
        cout << "Code -1: "<< code[code.length()-1]<< endl;
        if(code.length() % 2 != 0)return false;
        //else if(code[code.length()-1] == '(' || code[code.length()-1] == '['|| code[code.length()-1] == '{' )return false;
        //else if(code[1] == ')' || code[1] == ']'|| code[1] == '}' )return false;
        else if(code[i] == '(')stck.push(')');
        else if(code[i] == '[')stck.push(']');
        else if(code[i] == '{')stck.push('}');
        else if(code[i]== ')')
        {
            if(stck.top() != ')')return false;
            stck.pop();
        }
        else if(code[i]== ']')
        {
            if(stck.top() != ']')return false;
            stck.pop();
        }
        else if(code[i]== '}')
        {
            if(stck.top() != '}')return false;
            stck.pop();
        }
    }
    return true;
}

int main()
{
    string code;
    cin >> code;
    cout<< solution(code)<< endl;
}