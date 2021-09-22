#include <bits/stdc++.h>
using namespace std;

int ranks(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '-' || c == '+') return 1;
    if (c == '(' || c == ')') return 0;
    else return -1; 
}

void convert(string s)
{
    stack <char> st;
    string postfix = "";    
    for (int i = 0; i < s.length(); i++)
    {
        if (ranks(s[i]) == -1) postfix += s[i];
        else if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                char c = st.top();
                st.pop();
                postfix += c;
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && ranks(s[i]) <= ranks(st.top()))
            {
                char c = st.top();
                st.pop();
                postfix += c;
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        char c = st.top();
        st.pop();
        postfix += c;
    }
    cout << postfix <<endl;
}

main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        convert(s);
    }
}