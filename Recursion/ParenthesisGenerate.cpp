 void g(int open , int close, string s,vector<string> & ans){
        if(open==0 && close==0){
            if(s.size()!=0){
                ans.push_back(s);
                return;
            }
            return;
        }
        
        if(open>0){
            s.push_back('(');
            g(open-1,close,s,ans);
            s.pop_back();
        }
        if(open<close){
            s.push_back(')');
            g(open,close-1,s,ans);
            s.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
         string s="";
         vector<string> ans;
         g(n,n,s,ans);
       return ans;
    }
