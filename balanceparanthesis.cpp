#include <iostream>
#include <stack>
using namespace std;

bool BalancedParan(string expr)
{
    stack<char> s;
    
    int length = expr.length();
    
    for(int i=0;i<length;i++)
    {
        if(expr[i]=='{')
        {
            s.push(expr[i]);
        }
        if(expr[i]=='}')
        {
            if((s.top()=='{') && !s.empty())
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        
        if(expr[i]=='[')
        {
            s.push(expr[i]);
        }
        if(expr[i]==']')
        {
            if(s.top() == '[' && !s.empty())
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        
        if(expr[i]=='(')
        {
            s.push(expr[i]);
        }
        if(expr[i]==')')
        {
            if(s.top() == '(' && !s.empty())
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(s.empty())
    {
    return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string expr;
    cin>>expr;
    
    if(BalancedParan(expr))
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}