


bool ispar(string x)
    {
        stack<char> st;
        for(int i=0;i<x.size();++i){
            if(st.size()==0 || x[i]=='(' || x[i]=='{' || x[i]=='['){
                st.push(x[i]);
            }
            else
            {
                if((st.top()=='('&& x[i]==')') || (st.top()=='{'&& x[i]=='}') || (st.top()=='['&& x[i]==']') ){
                    st.pop();
                }
                else return false;
            }
        }
        return st.size()==0;
    }
