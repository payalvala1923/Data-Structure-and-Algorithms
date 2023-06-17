//  503. Next Greater Element II

// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]
 
 
 
 vector<int> nextGreaterElement(int N, vector<int>& arr) {
        vector<int> v;
        stack<int> s;
          for(int i=N-1;i>=0;i--){
            while(!s.empty()&&s.top()<=arr[i]){
                    s.pop();
                }
            s.push(arr[i]);
        }


        for(int i=N-1;i>=0;i--){
            if(s.size()==0){
                v.push_back(-1);
            }
            else{
                if(s.size()>0 && s.top()>arr[i]){
                    v.push_back(s.top());
                }
                else if(s.size()>0 && s.top()<=arr[i]){
                   while(s.size()>0 && s.top()<=arr[i]){
                       s.pop();
                   }
                   if(s.size()==0) v.push_back(-1);
                   else v.push_back(s.top());
                }
                
            }
            s.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
