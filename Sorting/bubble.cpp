void bubbleSort(int arr[], int n)
    {
        for(int i=0;i<n;++i){
            int f=0;
            for(int j=0;j<n-i-1;++j){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    f=1;
                }
            }
            if(f==0){
                break;
            }
        }
    }


void bubbleSort(int arr[], int n)
    {
        for(int i=0;i<n;++i){
            for(int j=0;j<n-i-1;++j){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
