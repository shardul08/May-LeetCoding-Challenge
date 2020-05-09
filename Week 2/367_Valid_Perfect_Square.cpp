/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true

Example 2:

Input: 14
Output: false

*/

// Solution 1

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i=1;
        while(i*i <= num) {
            if(i*i == num)
                return true;
            i++;
        }
        return false;
    }
};

// Solution 2

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while(num > 0) {
            num -= i;
            i += 2;
        }
        return num==0;
    }
};
