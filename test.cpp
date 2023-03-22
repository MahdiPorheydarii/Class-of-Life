#include <bits/stdc++.h>
using namespace std;

char complement(char x){
  if (x=='A') return 'T';
  if (x=='T') return 'A';
  if (x=='C') return 'G';
  if (x=='G') return 'C';
  if (x=='#') return '#';
  return '$';
}

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

vector<int> palindrome(string t) {
    string s;
    for(auto c: t) {
        s += string("#") + c;
    }
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == complement(s[i + p[i]])) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    vector<int> manc = vector<int>(begin(p) + 1, end(p) - 1);
    
    vector<int> result;
    for (int i = 2; i < manc.size(); i++){
        if (i%2==0) result.push_back((manc[i]-1)/2);
    }

    return result;
}

int main(){
    // test of KMP algorithm
    string txt = "ABABDABACDABABCABABABABCABAB";
    string pat = "ABABCABAB";
    cout<<KMP(pat,txt)<<endl;

    // test of palindrome algorithm
    string s="AATTAAGCTTAT";
    vector<int> v=palindrome(s);
    for(auto c:v) cout<<c<<endl;
    cout<<v.size();

}