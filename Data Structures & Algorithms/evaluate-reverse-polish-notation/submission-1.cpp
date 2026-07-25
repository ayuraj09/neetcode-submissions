class Solution {
public:

    bool sign(string &s){
        if(s.length()==1){
            if(s[0]=='+' || s[0]=='-' || s[0]=='*' || s[0]=='/')
            return 1;
        }
        return 0;
    }

    int eval(string &s, int &a, int &b ){
        if(s[0]=='+') return a+b;
        if(s[0]=='-') return a-b;
        if(s[0]=='/') return a/b;
        if(s[0]=='*') return a*b;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto &it : tokens){
            if(sign(it)){
                if(s.size()>=2){
                    int b = s.top();
                    s.pop();
                    int a = s.top();
                    s.pop();
                    int val  = eval(it,a,b);
                    s.push(val);
                }
            }else{
                int num = stoi(it);
                s.push(num);
            }
        }
        return s.top();
    }
};
