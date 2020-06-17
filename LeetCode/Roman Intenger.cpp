#include <iostream>

using namespace std;

int romantoint(string roman)
{
    int number = 0 ;
    for(int i=0; i<roman.length(); i++)
    {
        //cout <<"First i "<< i<<endl;
        if(roman[i] == 'I' && roman[i+1] != 'V' && roman[i+1] != 'X')
        {
            number+= 1;
        }
        else if(roman[i] == 'I' && roman[i+1] == 'V' && roman[i+1] != 'X')
        {
            number+= 4;
            i++;
            continue;
            
        }
        else if(roman[i] == 'I' && roman[i+1] != 'V' && roman[i+1] == 'X')
        {
            number+= 9;
            i++;
            continue;
            
        }
        if(roman[i] == 'X' && roman[i+1] != 'L' && roman[i+1] != 'C')
        {
            number += 10;
        }
        else if(roman[i] == 'X' && roman[i+1] == 'L' && roman[i+1] != 'C')
        {
            number += 40;
            i++;
            continue;
            
        }
        else if(roman[i] == 'X' && roman[i+1] != 'L' && roman[i+1] == 'C')
        {
            number += 90;
            i++;
            continue;
            
        }
        if(roman[i] == 'C' && roman[i+1] != 'D' && roman[i+1] != 'M')
        {
            number += 100;
        }
        else if(roman[i] == 'C' && roman[i+1] == 'D' && roman[i+1] != 'M')
        {
            number += 400;
            i++;
            continue;
            
        }
        else if(roman[i] == 'C' && roman[i+1] != 'D' && roman[i+1] == 'M')
        {
            number += 900;
            i++;
            continue;
            
        }
        if(roman[i]== 'V')
        {
            number += 5;
        }
        if(roman[i]== 'L')
        {
            number += 50;
        }
        if(roman[i]== 'D')
        {
            number += 500;
            
        }
         if(roman[i]== 'M')
        {
            number += 1000;
            
        }
        //cout << i<< roman[i] << number << endl;    

    }
    return number;
}
int main()
{
    string roman;
    while(roman != "quit")
    {
        cin >> roman;
        cout << romantoint(roman) << endl;
    }
    
    
}