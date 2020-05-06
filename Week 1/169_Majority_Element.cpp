/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

//Solution 1 Using hashmap to sotre frequency of each element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums) {
            freq[num]++;
            if(freq[num] > nums.size()/2)
                return num;
        }
        return 0;
    }
};

/*
Complexity analysis
Time: O(N)
Space: O(N)
*/

//Solution 2 Sorting the array and returning the middle element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

/*
Complexity analysis
Time: O(NlogN)
Space: O(1)
*/

//Solution 3 Moore's voting algorithm

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int majorityIndex = 0;
        for (int count = 1, i = 1; i < num.size(); i++) {
            num[majorityIndex] == num[i] ? count++ : count--;
            if (count == 0) {
                majorityIndex = i;
                count = 1;
            }
        }

        return num[majorityIndex];
    }
};

/*
Complexity analysis
Time: O(N)
Space: O(1)
*/
