class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> s1;
        stack<char> s2;

        for (int i=0; i<s.size(); i++) {

            char ch = s[i];
            if (s[i] == '#' && s1.empty()) {
                continue;
            }
            if (s[i] == '#') {
                s1.pop();
                continue;
            }
            s1.push(ch);
        }

        for (int i=0; i<t.size(); i++) {

            char ch = t[i];
            if (t[i] == '#' && s2.empty()) {
                continue;
            }
            if (t[i] == '#') {
                s2.pop();
                continue;
            }
            s2.push(ch);
        }
        
        return (s1 == s2);
    }
};