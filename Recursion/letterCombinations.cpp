void solve(string &digits, string output, int index, vector<string>& ans,vector<string> mapping){
    //base case
    if(index>=digits.size()){
        ans.push_back(output);
        return;
    }
    int number=digits[index]-'0';
    string value=mapping[number];
    for(int i=0;i<value.size();++i){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans, mapping);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>  ans;
        if(digits.size()==0) return ans;
        string output="";
        int index=0;
        solve(digits,output, index, ans, mapping);
        return ans;

    }







vector<string> letterCombinations(string digits) {
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>  ans;

        if(digits.length()==0)
            return ans;
        ans.push_back("");

        for(int i=0;i<digits.length();i++){
            vector<string> v;
            string s=mapping[digits[i]-'0'];
            for(int j=0;j<s.length();j++){
                for(int k=0;k<ans.size();k++){
                    string t=ans[k];
                    v.push_back(t+s[j]);
                }
            }
            ans.swap(v);
        }
        return ans;
    }
