#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;

public:
    Queue()
    {
        frontIndex = -1;
        rearIndex = -1;
    }
    void enqueue(int x)
    {
        if (MAX_SIZE == rearIndex)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            if (frontIndex == -1)
                frontIndex = 0;
            rearIndex = (rearIndex + 1) % MAX_SIZE;
            arr[rearIndex] = x;
        }
    }

    int dequeue()
    {
        int x;
        if (isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            exit(1);
        }
        else
        {
            x = arr[frontIndex];
            if (frontIndex == rearIndex)
            {
                frontIndex = -1;
                rearIndex = -1;
            }
            else
            {
                frontIndex = (frontIndex + 1) % MAX_SIZE;
            }
             return x;
        }
       
    }

    bool isEmpty()
    {
        return frontIndex == -1 && rearIndex == -1;
    }
};

class Stack {
    private:
    Queue q1, q2;

    public:
    void Push(int x)
    {

        q1.enqueue(x);
        while (!q2.isEmpty())
        {
            q1.enqueue(q2.dequeue());
        }
        swap(q2, q1);
    }
    int Pop(){
        if(q2.isEmpty()) return -1;
        return q2.dequeue();
    }
    bool isEmpty(){
        return q2.isEmpty();
    }
};

int main()
{
   
    // Queue q; 
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // cout<<q.dequeue();
    // cout<<q.dequeue();
    // cout<<q.dequeue();
    // q.dequeue();

    Stack st;
    st.Push(3);
    st.Push(4);
    st.Push(2);
     cout<<st.Pop()<<endl;
     cout<<st.Pop()<<endl;
     cout<<st.isEmpty();
    return 0;
}
