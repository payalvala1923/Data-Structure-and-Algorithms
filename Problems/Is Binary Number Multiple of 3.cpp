int isDivisible(string s){
	    int n = s.size();
	    int even = 0;
	    int odd = 0;
	    
	    for(int i = 0; i < n; i++){
	        if(s[i] ==  '1'){
	            if(i % 2 == 0){
	                even++;
	            }
	            else if(i % 2 != 0){
	                odd++;
	            }
	        }
	    }
	    
	   return abs(even - odd) % 3==0;

	}
