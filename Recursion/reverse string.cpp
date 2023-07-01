string r(string &str, int s, int e){
	if(s>e) return str ;
	swap(str[s],str[e]);
	s++;
	e--;
	return r(str,s,e);
}
string reverseString(string str)
{
	return r(str,0,str.size()-1);
}
