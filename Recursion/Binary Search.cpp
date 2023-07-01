int find(vector<int>& nums, int low, int high, int target){
    if(low>high) return -1;
    int mid=low+(high-low)/2;
    if(nums[mid]==target) return mid;
    if(nums[mid]<target){
        return find(nums, mid+1, high, target);
    }
    else{
         return find(nums, low, mid-1, target);
    }
    
}
int search(vector<int>& nums, int target) {
    return find(nums,0, nums.size()-1, target);
}
