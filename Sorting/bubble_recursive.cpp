void bubble(int a[], int n){
        if(n==1) return;
        
        for(int i=0;i<n-1;++i){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
        bubble(a,n-1);
    }
    public:
    void bubbleSort(int arr[], int n)
    {
        bubble(arr,n);
    }
