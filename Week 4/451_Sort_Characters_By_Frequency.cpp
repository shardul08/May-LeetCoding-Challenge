/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

// Solution

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(91);  //ord('z')-ord(' ')=90
        string res = "";
        for(char c:s)
            freq[c-' ']++;
        for(int i=s.length();i>0;i--) {
            for(int j=0;j<91;j++)
                if(freq[j]==i) {
                    res.append(i,' '+j);
                   // for(int k=0;k<i;k++)
                     //   res+= ' '+j;
                }
        }
        return res;
    }
};

/*
Complexity analysis
Time: O(N)
Space: O(1)
*/
