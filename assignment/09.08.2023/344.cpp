class Solution {
public:

    void function(vector<char>& s, int i){

        int n=s.size();

        if (i>=(n/2)){
            return;
        }

        swap(s[i], s[n-i-1]);
        i++;

        function(s,i);
    }

    void reverseString(vector<char>& s) {
        
        int i=0;
        function(s,i);
        
    }
};