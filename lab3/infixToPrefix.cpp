#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if (c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
};

string infixToPrefix(string s){
    reverse(s.begin(), s.end());

    stack<char> st;
    string res;

    for(int i = 0; i<s.length(); i++){
        if(s[i]>='a' && s[i] <='z' || s[i]>='A' && s[i] <='Z' ){
            res+=s[i];
        }  
        else if(s[i] == ')'){
            st.push(s[i]);
        }
        else if(s[i] == '('){
            while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop(); //pops ')' if stack is not empty
            }
        }
        else{//for operators which checks for both right to left and left to right associativity
            while(!st.empty() && ((s[i]=='^')? precedence(s[i]) <= precedence(st.top()): precedence(s[i]) < precedence(st.top()))){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    
    reverse(res.begin(), res.end());

    return res;
}

int main(){

    cout << infixToPrefix("(a-b/c)*(a/k-l)") <<endl;

    return 0;
}

//examples:
//(a-b/c)*(a/k-l) : *-a/bc-/akl
//(A+B*C) : +A*BC
//K+L-M*N+(O^P)*W/U/V*T+Q^C^V : ++-+KL*MN*//*^OPWUVT^Q^CV