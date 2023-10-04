class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> st;

        int sum = 0;

        for (int i=0; i<operations.size(); i++) {

            string str = operations[i];

            if (str == "C") {
                if (!st.empty()) {
                    sum -= st.top();
                    st.pop();
                }
            }

            else if (str == "D") {
                int n = st.top()*2;

                st.push(n);
                sum += st.top();
            }

            else if (str == "+") {      
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.push(n1);
                int ans = n1 + n2;
                st.push(ans);
                sum += st.top();
            }

            else {
                int n = stoi(operations[i]);

                st.push(n);
                sum += st.top();
            }
        }
        return sum;        
    }
};