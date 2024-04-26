#include <bits/stdc++.h>
using namespace std;

int stck[100], top = -1;

void push(int x)
{
    if (top >= 99)
        cout << "STACK overflow" << endl;

    else
    {
        top++;
        stck[top] = x;
    }
}

int pop()
{
    int y;
    if (top <= -1)
        cout << "STACK underflow" << endl;
    else
    {
        y = stck[top];
        top--;
        return y;
    }
}
int main()
{
    push(20);
    push(10);
    push(45);
    push(33);

    pop();

    for (int i = 0; i <= top; i++)
    {
        cout << stck[i] << " ";
    }
    return 0;
}