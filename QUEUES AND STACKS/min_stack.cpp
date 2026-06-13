// MIN STACK

#include <iostream>
#include <stack>
using namespace std;

class MinStack {

private:

    stack<int> st;
    stack<int> minSt;

public:

    void push(int val) {

        st.push(val);

        if(minSt.empty() ||
           val <= minSt.top())
        {
            minSt.push(val);
        }
    }

    void pop() {

        if(st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {

        return st.top();
    }

    int getMin() {

        return minSt.top();
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(2);
    st.push(8);
    st.push(1);

    cout << st.getMin() << endl; // 1

    st.pop();

    cout << st.getMin() << endl; // 2

    return 0;
}