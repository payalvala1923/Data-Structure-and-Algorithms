
void selectionSort(int arr[], int n)
    {
      for(int i=0;i<n;++i){
          int ind=i;
          for(int j=i;j<n;++j){
              if(arr[ind]>arr[j]){
                  ind=j;
              }
          }
          
          swap(arr[ind],arr[i]);
      }
    }

