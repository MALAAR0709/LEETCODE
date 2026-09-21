class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        vector<int> pCount(26, 0);
        vector<int> window(26, 0);

        // Count characters in p
        for (char c : p) {
            pCount[c - 'a']++;
        }

        int k = p.length();

        // Sliding window
        for (int i = 0; i < s.length(); i++) {

            // Add current character
            window[s[i] - 'a']++;

            // If window becomes bigger than k
            if (i >= k) {
                window[s[i - k] - 'a']--;
            }

            // Compare frequencies
            if (window == pCount) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};