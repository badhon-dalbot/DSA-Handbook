#include <bits/stdc++.h>
using namespace std;

bool isValidOperator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/';
}

bool isValidExpression(const string &expression)
{
    stack<char> parentheses;
    bool hasValidOperator = false;
    bool hasNonEmptyParentheses = false;

    for (size_t i = 0; i < expression.size(); ++i)
    {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{')
        {
            parentheses.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (parentheses.empty() || ((c == ')' && parentheses.top() != '(') || (c == ']' && parentheses.top() != '[') || (c == '}' && parentheses.top() != '{')))
            {
                return false;
            }
            parentheses.pop();
            if (hasValidOperator)
            {
                hasNonEmptyParentheses = true;
            }
        }
        else if (isValidOperator(c))
        {
            if (i == 0 || i == expression.size() - 1 || !isdigit(expression[i - 1]) || !isdigit(expression[i + 1]))
            {
                return false; // Missing operand before or after the operator
            }
            
            hasValidOperator = true;
        }
    }

    return !parentheses.empty() || (hasValidOperator && hasNonEmptyParentheses);
}

int main()
{
    string expression = "((4+1)(4*4)";
    cout << boolalpha << isValidExpression(expression) << endl;

    return 0;
}
