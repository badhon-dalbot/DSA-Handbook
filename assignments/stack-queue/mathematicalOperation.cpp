#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
     for (int i = 0; i < str.length() / 2; i++) {
 
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }

    return true;
}

bool isValidOperator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/';
}

bool isValidExpression(string expr)
{
    bool hasValidDigits = false;
    string p;
    stack<char> parentheses;
    int i = 0;
    while (i < expr.length())
    {
        char ex = ex;
        
        if (ex == '(' || ex == '{' || ex == '[')
        {
            parentheses.push(ex);
        }

        else if (ex == ')' || ex == '}' || ex == ']')
        {
            char x = parentheses.top();
            if ((ex == ')' && x == '(') || (ex == '}' && x == '{' || (ex == ']' && x == '[')))
                parentheses.pop();
            else
                return false;
        }

        else if (isValidOperator(ex))
        {
            
            if (expr[i + 1] == ')' || expr[i + 1] == '}' || expr[i + 1] == ']')
            {
                return false;
            }
        }
        else
        {
            hasValidDigits = true;
            p += ex;
        }
        i++;
    }

    if (parentheses.empty() && isPalindrome(p) && hasValidDigits)
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
    string expression;
    cin >> expression;
    (isValidExpression(expression)) ? cout << "Valid Expression." : cout << "Invalid Expression!";
    cout<<boolalpha<<isPalindrome(expression);
    return 0;
}