#include <iostream>
#include <stack>
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

string infixToPostfix(string s){
    stack<char> st;
    string res;

    for(int i = 0; i<s.length(); i++){
        if(s[i]>='a' && s[i] <='z' || s[i]>='A' && s[i] <='Z' ){
            res+=s[i];
        }  
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop(); //pops '(' if stack is not empty
            }
        }
        else{//for operators
            while(!st.empty() && ((s[i]=='^')? precedence(s[i]) < precedence(st.top()): precedence(s[i]) <= precedence(st.top())) ){
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
    return res;
}

int main(){

    cout << infixToPostfix("K+L-M*N+(O^P)*W/U/V*T+Q^C^V") <<endl;

    return 0;
}

//examples:
//(a-b/c)*(a/k-l) : abc/-ak/l-*
//(A+B*C-D/E) : ABC*+DE/-
//A+B-(C*D/E+F)-G*H : AB+CD*E/F+-GH*-
//K+L-M*N+(O^P)*W/U/V*T+Q : KL+MN*-OP^W*U/V/T*+Q+
//K+L-M*N+(O^P)*W/U/V*T+Q^C^V : KL+MN*-OP^W*U/V/T*+QCV^^+