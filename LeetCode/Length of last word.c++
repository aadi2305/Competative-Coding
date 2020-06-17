#include <iostream>

using namespace std;
int length(string s)
{
    int counter = 0;
    for(int i= 0; s[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
};
int lengthoflastword(string s)
{
    int space_position; 
    for(int i = 0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            space_position = i;
        }
    }
    int counter = s.length() - (space_position+1);
    return counter;
};
int main()
{
    string s;
    cin >> s;
    cout << s << endl;

}