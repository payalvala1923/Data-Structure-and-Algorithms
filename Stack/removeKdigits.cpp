// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.



string removeKdigits(string num, int k) {
        string ans="";
        for(auto it:num){
            while(ans.size()>0 && ans.back()>it && k>0){
                ans.pop_back();
                k--;
            }
           if(ans.size()==0 && it=='0');
            else ans+=it;
        }
        while(ans.size()>0 && k>0){
            ans.pop_back();
            k--;
        }
        if(ans.size()==0) return "0";
        return ans;
    }
