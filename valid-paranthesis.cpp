#include<bits/stdc++.h>

using namespace std;

int main()
{

    string s = "(({}))" ;

    stack<char>st;

    for(char c : s)
    {
        if(c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if(st.empty())
            {
                cout<<"This is not a valid paranthesis";
                return 0;
            }

            if(c == ')' && st.top() != '(')
            {
                cout<<"Not valid";
                return 0;
            }
            if(c == '}' && st.top() != '{')
            {
                cout<<"Not valid";
                return 0;
            }
            if(c == ']' && st.top() != '[')
            {
                cout<<"Not valid";
                return 0;
            }

            st.pop();
        }

    }


    if(st.empty())
    {
        cout<<"Valid";
    }
    return 0;
}
