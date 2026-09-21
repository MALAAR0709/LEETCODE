class Solution {
public:
    int countGoodSubstrings(string s) {

        int count = 0;

        // Take every group of 3 characters
        for (int i = 0; i + 2 < s.length(); i++) {

            // Map = character → frequency
            unordered_map<char, int> mp;

            // Count the 3 characters
            mp[s[i]]++;
            mp[s[i + 1]]++;
            mp[s[i + 2]]++;

            // If there are 3 different characters
            if (mp.size() == 3) {
                count++;
            }
        }

        return count;
    }
};