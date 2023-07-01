void solve( vector<vector<int>>& ans, vector<int> subset,int i,vector<int> & nums){
        if(i==nums.size()){
            ans.push_back(subset);
            return;
        }

        //without ith element(exclude)
        solve(ans,subset,i+1,nums);

        //with ith element(include)
        subset.push_back(nums[i]);
        solve(ans,subset,i+1,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        solve(ans,subset,0,nums);
        return ans;
    }
