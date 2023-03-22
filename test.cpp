#include <bits/stdc++.h>
using namespace std;


int KMP(string s1, string s2){
    int m=s1.length();
    int n=s2.length();
    vector<int> lps(s1.length());
    int len=0, i=1;
    
    lps[0]=0;

    while (i<s1.length()){
        if (s1[i]==s1[len]){
            ++len;
            lps[i]=len;
            ++i;
        }
        else 
        {
            if (len!=0){
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                ++i;
            }
        }
    }
    for (auto x:lps){
        cout<<x<<" ";
    }
    cout<<endl;
    int j=0;
    i=0;
    while ((n - i) >= (m - j)) {
        if (s1[j] == s2[i]) {
            j++;
            i++;
        }
 
        if (j == m) {
            return (i-j);
        }
        else if (i < n && s1[j] != s2[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return -1;
}

int main(){
    string txt = "ABABDABACDABABCABABABABCABAB";
    string pat = "ABABCABAB";
    cout<<KMP(pat,txt);
}