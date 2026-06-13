#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;


// 1. VALID PARENTHESES (Leetcode 20)


bool isValid(string s) {

    stack<char> st;

    for(char ch : s) {

        // Opening bracket
        if(ch == '(' ||
           ch == '{' ||
           ch == '[')
        {
            st.push(ch);
        }

        else {

            // No matching opening bracket
            if(st.empty())
                return false;

            char top = st.top();

            if((ch == ')' && top == '(') ||
               (ch == '}' && top == '{') ||
               (ch == ']' && top == '['))
            {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}


// 2. IMPLEMENTING STACK USING QUEUES


class MyStack {

private:

    queue<int> q;

public:

    void push(int x) {

        q.push(x);

        int size = q.size();

        // Move older elements behind
        for(int i=0;i<size-1;i++) {

            q.push(q.front());
            q.pop();
        }
    }

    int pop() {

        int val = q.front();

        q.pop();

        return val;
    }

    int top() {

        return q.front();
    }

    bool empty() {

        return q.empty();
    }
};

// 3. IMPLEMENT QUEUE USING STACKS

class MyQueue {

private:

    stack<int> input;
    stack<int> output;

public:

    void push(int x) {

        input.push(x);
    }

    int pop() {

        if(output.empty()) {

            while(!input.empty()) {

                output.push(input.top());
                input.pop();
            }
        }

        int val = output.top();

        output.pop();

        return val;
    }

    int peek() {

        if(output.empty()) {

            while(!input.empty()) {

                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {

        return input.empty() &&
               output.empty();
    }
};


int main() {

    cout << "===== VALID PARENTHESES =====\n";

    string s = "{[()]}";

    cout << isValid(s) << endl;

    cout << "\n===== STACK USING QUEUE =====\n";

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;

    cout << st.pop() << endl;

    cout << st.top() << endl;

    cout << "\n===== QUEUE USING STACK =====\n";

    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.peek() << endl;

    cout << q.pop() << endl;

    cout << q.peek() << endl;

    return 0;
}