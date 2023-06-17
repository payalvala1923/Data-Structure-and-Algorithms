// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

// Example 1:

// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10



long long trappingWater(int arr[], int n){
        int mxr[n];
        int mxl[n];
        mxr[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            mxr[i]=max(arr[i],mxr[i+1]);
        }
        mxl[0]=arr[0];
        for(int i=1;i<n;++i){
            mxl[i]=max(mxl[i-1],arr[i]);
        }
        long long sum=0;
        for(int i=0;i<n;++i){
            sum+=(min(mxl[i],mxr[i])-arr[i]);
        }
        return sum;
    }
