// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}

// top right corner thi jya sudhi 1 ave tya sudhi ny to down agr 1 ave to j j--kri ne jovanu



int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
      // code here
       int i=0;
        int j=m-1;
        int ans=-1;
       while(i<n && j>=0){
           if(arr[i][j]==1){
               
             ans=i;
             j--;
           }
           else{
               i++;
           }
           
       }
       return ans;
  }

