/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

 

Note:

    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000].
*/

// Solution

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> s1_freq(26), s2_freq(26);
        if(s1.length() > s2.length())
            return false;
        for(char c:s1)
            s1_freq[c-'a']++;
        for(int i=0;i<s1.length();i++)
            s2_freq[s2[i]-'a']++;
        if(s1_freq == s2_freq)
            return true;
        int start = 1;
        int end = s1.length();
        while(end < s2.length()) {
            if(s2[start-1] != s2[end]) {
                s2_freq[s2[start-1]-'a']--;
                s2_freq[s2[end]-'a']++;
            }
            if(s1_freq == s2_freq)
                return true;
            start++;
            end++;
        }
        return false;
    }
};

/*
Complexity analysis
Time: O(len(s2))
Space: O(1)
*/
