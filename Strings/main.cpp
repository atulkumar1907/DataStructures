#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    string str ="akdjfskjf";

    // convert to lower case
    // transform(str.begin(), str.end(), str.begin(), ::toupper)
    // transform(str.begin(), str.end(), str.begin(), ::tolower)

    for(int i=0; i<str.length(); i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]-=32;
        }
    }
    // cout<<str<<endl;

    // convert to upper case

    for(int i=0; i<str.length(); i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]+=32;
        }
    }
    // cout<<str<<endl;

    // biggest no. from numeric string

    string s = "89734273";

    sort(s.begin(), s.end(), greater<int>());

    // cout<<s<<endl;

    // first character with maximum frequency
    string s1="lfjsldjfsfdshf";

    int freq[26];

    for(int i=0; i<26; i++){
        freq[i]=0;
    }

    for(int i=0; i<s1.size(); i++){
        freq[s1[i]-'a']++;
    }

    char ans='a';
    int maxF = 0;

    for(int i=0; i<26; i++){
        if(freq[i]>maxF);
        maxF = freq[i];
        ans = i+'a';
    }

    cout<<maxF<<" "<<ans<<endl;


    return 0;

}