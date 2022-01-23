#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string s) {
    stack<char> stk;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else {
            char opp;
            if (c == ')') opp = '(';
            if (c == ']') opp = '[';
            if (c == '}') opp = '{';

            if (stk.empty() || stk.top() != opp) {
                return false;
            } else {
                stk.pop();
            }
        }
    }

    return stk.empty();
}

