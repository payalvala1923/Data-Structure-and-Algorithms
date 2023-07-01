void solve(string s,string output, int index,vector<string> &ans ){
  if(s.size()<=index){
	  if(output.size()!=0) ans.push_back(output);
	  return;
  }
  //exclude
  solve(s, output, index+1,ans);
  // include
  output.push_back(s[index]);
  solve(s, output, index+1,ans);
}
vector<string> subsequences(string str){
	vector<string> ans;
	string output="";
	solve(str,output,0,ans);
	
	return ans;
}
