/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

// Solution

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26,0),pos;
        if(s.length() < p.length())
            return pos;
        for(char c:p)
            freq[c-'a']++;
        for(int i=0;i<p.length();i++)
            freq[s[i]-'a']--;
        if(count(freq.begin(), freq.end(), 0) == 26)
            pos.push_back(0);
        int start=1,end=p.length();
        while(end<s.length()) {
            freq[s[start-1]-'a']++;
            freq[s[end]-'a']--;
            if(count(freq.begin(), freq.end(), 0) == 26)
                pos.push_back(start);
            start++;
            end++;
        }
        return pos;
    }
};

/*
Complexity analysis
Time: O(len(s))
Space: O(1)
*/
