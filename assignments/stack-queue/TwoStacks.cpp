#include <bits/stdc++.h>
using namespace std;

class TwoStacks
{
private:
    int *arr;
    int size;
    int top1;
    int top2;

public:
    TwoStacks(int maxSize)
    {
        size = maxSize;
        arr = new int[size];
        top1 = size / 2;
        top2 = size / 2;
    }

    void pushStack1(int x)
    {
        if (top1 > 0)
        {
            top1--;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack is overflow" << endl;
            return;
        }
    }
    void pushStack2(int x)
    {
        if (top2 < size - 1)
        {
            top2++;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack is overflow" << endl;
        }
    }
    int popStack1()
    {
        int y;
        if (!isEmptyStack1())
        {
            y = arr[top1];
            top1++;
            return y;
        }

        else
        {
            cout << "STACK underflow" << endl;
            exit(1);
        }
    }
    int popStack2()
    {
        int y;
        if (!isEmptyStack2())
        {
            y = arr[top2];
            top2--;
            return y;
        }

        else
        {
            cout << "STACK underflow" << endl;
            exit(1);
        }
    }
    bool isEmptyStack1()
    {
        return (top1 >= size / 2);
    }
    bool isEmptyStack2()
    {
        return (top2 <= size / 2);
    }
};

int main()
{
    TwoStacks myStacks(6);
    myStacks.pushStack1(5);
    myStacks.pushStack1(10);

    myStacks.pushStack2(20);
    myStacks.pushStack2(25);

    int popped1 = myStacks.popStack1();
    int popped2 = myStacks.popStack2();
    cout << popped1 << " " << popped2 << endl;

    myStacks.pushStack2(30);

    int popped3 = myStacks.popStack1();
    int popped4 = myStacks.popStack2();
    cout << popped3 << " " << popped4 << endl;

    bool isEmpty1 = myStacks.isEmptyStack1();
    bool isEmpty2 = myStacks.isEmptyStack2();

    cout<<isEmpty1<<" "<<isEmpty2;
    

    return 0;
}