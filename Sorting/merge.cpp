void merge(int arr[], int l, int m, int r)
    {
         
         int left=l;
         int right=m+1;
         
         int ans[r-l+1],j=0;
         while(left<=m && right<=r){
             if(arr[left]<arr[right]){
                 ans[j]=arr[left];
                 left++;
             }
             else{
                 ans[j]=arr[right];
                 right++;
             }
             j++;
         }
         
         while(left<=m){
             ans[j]=arr[left];
             left++;
             j++;
         }
         while(right<=r){
             ans[j]=arr[right];
             right++;
             j++;
         }
         
         for(int i=0;i<r-l+1;++i){
             arr[l+i]=ans[i];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
