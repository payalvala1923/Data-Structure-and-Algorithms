
// Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 


// Example 1:

// Input:
// S = "aba", K = 2
// Output:
// 3
// Explanation:
// The substrings are:
// "ab", "ba" and "aba".
// Example 2:

// Input: 
// S = "abaaca", K = 1
// Output:
// 7
// Explanation:
// The substrings are:
// "a", "b", "a", "aa", "a", "c", "a". 





long long int solve(string s, int k){
        long long int left=0, right=0, ans=0, n=s.size(),d=0;
    	long long int f[26]={0};
    	
    	while(right<n){
    	    
    	    
    	    f[s[right]-'a']++;
    	    if( f[s[right]-'a']==1){
    	        d++;
    	    }
    	    
    	    
    	    // decreasing the size of window
    	    while(d>k){
    	        f[s[left]-'a']--;
    	        if(f[s[left]-'a']==0){
    	            d--;
    	        }
    	        left++;
    	    }
    	    
    	    right++;
    	    ans+=(right-left+1);
    	}
    	return ans;
    }
    long long int substrCount (string s, int k) {
    	return solve(s,k)-solve(s,k-1);
    }
