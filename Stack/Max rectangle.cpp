// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

// Example 1:

// Input:
// n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8
// Explanation: For the above test case the
// matrix will look like
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// the max size rectangle is 
// 1 1 1 1
// 1 1 1 1
// and area is 4 *2 = 8.





vector<int> NSR( vector<int> v, int n){
      vector<int> v1;
      stack<int> st;
      for(int i=n-1;i>=0;i--){
          if(st.empty()){
              v1.push_back(n);
          }
          else{
              while(!st.empty() && v[st.top()]>=v[i]){
                  st.pop();
              }
              if(st.empty()) v1.push_back(n);
              else v1.push_back(st.top());
          }
          st.push(i);
      }
      reverse(v1.begin(),v1.end());
      return v1;
  }
  vector<int> NSL( vector<int> v, int n){
      vector<int> v1;
      stack<int> st;
      for(int i=0;i<n;i++){
          if(st.empty()){
              v1.push_back(-1);
          }
          else{
              while(!st.empty() && v[st.top()]>=v[i]){
                  st.pop();
              }
              if(st.empty()) v1.push_back(-1);
              else v1.push_back(st.top());
          }
          st.push(i);
      }
     // reverse(v.begin(),v.end());
      return v1;
  }
  int MAH(vector<int> v, int n){
      
      vector<int> r=NSR(v,n);
      
      vector<int> l=NSL(v,n);
      int maxi=-1;
      for(int i=0;i<n;++i){
          maxi=max(maxi,(r[i]-l[i]-1)*v[i]);
      }
      return maxi;
  }
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> v;
        for(int i=0;i<m;++i){
            v.push_back(M[0][i]);
        }
        int mx=MAH(v,m);
       for(int j=1;j<n;++j){
        for(int i=0;i<m;++i){
            if(M[j][i]==0) v[i]=0;
            else v[i]+=1;
        }
        
        mx=max(mx,MAH(v,m));
        
        }
        return mx;
    }
