class Solution {

// private:
//     void solve(string &str, stack<char> st) {

//         if (st.empty()){
//             return;
//         }

//         char ch = st.top();
//         st.pop();

//         solve(str, st);

//         str.push_back(ch);
//     }


public:
    string removeStars(string s) {

        int j=0;
        for (int i=0; i<s.size(); i++) {

            if (s[i] == '*') {
                j--;
            }

            else {
                s[j] = s[i];
                j++;
            }
        }

        return s.substr(0, j);

        
        //...................................
        //👇👇👇memory limit exceeded👇👇👇
        //...................................

        // stack<char> st;

        // for (int i=0; i<s.size(); i++) {

        //     char ch = s[i];

        //     if (ch == '*' && st.empty()) {
        //         continue;
        //     }
        //     if (ch == '*' && !st.empty()) {
        //         st.pop();
        //         continue;
        //     }

        //     st.push(ch);
        // }

        // string str = "";
        // solve(str, st);
        // return str;

    }
};