#include<iostream>
#include<stack>
using namespace std;

void reverseString(string& s){
    if(s.length()==1){
        cout<<s<<endl;
        return;
    }

    stack<string> st;

    for(int i=0; i<s.length(); i++){
        string word = "";
        while(s[i]!=' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return;
}

int main(){

    string s = "Hey, How are you doing?";

    reverseString(s);

    return 0;
}