class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};


//---------------------------2nd approch----------------------------------
//----Almost same time and space-----
// class MyStack {
// public:
//     queue<int> q1;
//     queue<int> q2;
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q1.push(x);
//     }
    
//     int pop() {
//         while (q1.size() != 1) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         int val = q1.front();
//         q1.pop();    
//         swap(q1, q2);   
//         return val;
//     }
    
//     int top() {
//         while (q1.size() != 1) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };



/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */