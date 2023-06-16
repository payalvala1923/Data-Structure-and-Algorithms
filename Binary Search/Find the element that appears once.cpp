
//Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.

int search(int A[], int N){
	  
        int s=0,e=N-1;
        while(s<=e){
            int mid=(s+e)/2;
            
            if(mid== 0 && A[mid] != A[mid + 1]) {
	            return A[mid];
	        }
	        if(mid== N - 1 && A[N - 1] != A[N - 2]) {
	            return A[mid];
	        }
	        
	        if(A[mid] != A[mid - 1] && A[mid] != A[mid + 1]) {
	            return A[mid];
	        }
	        
            if(mid%2!=0){
                if(A[mid-1]==A[mid]){
                    s=mid+1;
                }
                else if(A[mid+1]==A[mid]){
                    e=mid-1;
                    
                }
                else{
                    return A[mid];
                }
            }
            else{
                if(A[mid-1]==A[mid]){
                    e=mid-2;
                }
                else if(A[mid+1]==A[mid]){
                   
                    s=mid+2;
                }
                else{
                    return A[mid];
                }
            }
        }
        return -1;
	    
	}
