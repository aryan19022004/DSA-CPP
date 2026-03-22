class Solution {
public:
    string repeatedSubstring(string s) {
        int n = s.size();
        for(int k = 1; k <= n/2; k++) {
            if(n % k == 0) { // check if k divides n
                string sub = s.substr(0, k); // candidate substring
                string built = "";
                int times = n / k;
                for(int i = 0; i < times; i++) {
                    built += sub; // repeat substring
                }
                if(built == s) {
                    return sub; // found smallest repeating substring
                }
            }
        }
        return ""; // no repeated substring
    }
};
