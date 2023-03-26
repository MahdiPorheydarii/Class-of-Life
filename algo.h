#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector

char complement(char x){
  if (x=='A') return 'T';
  if (x=='T') return 'A';
  if (x=='C') return 'G';
  if (x=='G') return 'C';
  if (x=='#') return '#';
  return '?';
}


// this searches for s1 in s2
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

// this function returns Longest Common Substring 
int LCS(string s1,string s2,int m,int n){
    if (m==0 or n==0) return 0;
    if (s1[m-1]==s2[n-1]) return 1+LCS(s1,s2,m-1,n-1);
    else return max(LCS(s1,s2,m,n-1),LCS(s1,s2,m-1,n));
}

// Calculates the similarity percentage between two strings
double StringSim(string s1,string s2){
    int lenLCS=0;
    lenLCS=LCS(s1,s2,s1.length(),s2.length());
    return 100 * lenLCS/double(max(s1.length(),s2.length()));
}

// calculates sum of a vector members(shall be needed for calculating similarity percentage of two Animals)
int sum(vector<int> a){
    int b = 0;
    for(auto x:a) b += x;
    return b;
}

// palindrome algorithm

void palindrome(string t) {
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
    for (int i=1;i<manc.size()-1;i++){
        if (manc[i]>3){
            for (int j=i-manc[i]+2;j<=i+manc[i];j++){
                if (s[j]!='#') cout<<s[j];
            }
            cout<<endl;
        }
    }

}
