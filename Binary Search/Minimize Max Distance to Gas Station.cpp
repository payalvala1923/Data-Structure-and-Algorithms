bool isPossible(vector<int> &stations, int K,double mid){
        int station_count=0;
        for(int i=1;i<stations.size();i++){
            int temp = floor((stations[i]-stations[i-1])/mid);
            if(2*mid == (double)(stations[i]-stations[i-1])){
                temp--;
            }
            station_count += temp;
            if(station_count>K) return false;
        }
        return true;
    }
    double findSmallestMaxDist(vector<int> &stations, int K){
         double low = 0;
          double high = stations[stations.size()-1]-stations[0];
          double ans = 0;
          while((high-low)>1e-7){
              double mid = low + (high-low)/2.0;
              if(isPossible(stations,K,mid)){
                  ans = mid;
                  high=mid;
              }
              else{
                  low=mid;
              }
          }
          return ans;
    }
