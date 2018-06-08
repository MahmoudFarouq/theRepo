#include <iostream>
#include <stack>
using namespace std;

bool IsValid(string x)
{
    stack<char> s;
    int len = x.length();
    for(int i = 0; i < len; i++)
    {
        if( x[i] == '(' || x[i] == '{' || x[i] == '[') s.push(x[i]);
        else if(x[i] == ')' || x[i] == '}' || x[i] == ']')
        {
            char c = s.top();
            if(x[i] - c <= 2)s.pop();
            else return false;
        }
        else if(x[i] == '/' && x[i+1] == '*')
        {
            while(!(x[i] == '*' && x[i+1] == '/'))
            {
                if(i >= len) return false;
                i++;
            }
        }
    }
    if(s.size() == 0) return true;
    return false;
}

int main()
{
    string x1 = "([{}])(){}[]{[]}";
    string x2 = "({)}";
    string x3 = "({/*)}]]]]]]}*/})";
    string x4 = "({/*[][[]]]]]})";
    string x5 = "[{/*******/}]";

    cout << IsValid(x1) << endl;
    cout << IsValid(x2) << endl;
    cout << IsValid(x3) << endl;
    cout << IsValid(x4) << endl;
    cout << IsValid(x5) << endl;

    /*cout << (int)'{' << " " << (int)'}' << endl;
    cout << (int)'(' << " " << (int)')' << endl;
    cout << (int)'[' << " " << (int)']' << endl;*/
    return 0;
}
