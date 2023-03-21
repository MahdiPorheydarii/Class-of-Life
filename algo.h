#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector

char complement(char x){
  if (x=='A') return 'T';
  if (x=='T') return 'A';
  if (x=='C') return 'G';
  if (x=='G') return 'C';
}


// this searches for s1 in s2
int KMP(string s1, string s2){
    int m=s1.length();
    int n=s2.length();
    vector<int> lps=LPS(s1);

    int i=0,j=0;

    while(n-i>=m-j){
        if (s2[j]==s1[i]) {
            j++;
            i++;
        }
        if (j==m){
            return i-j;
        }
        else if (i<n and s1[j]!=s2[i]) {
            if (j) j=lps[j-1];
            else ++i;
        }
    }
    return 0;
}

// Least Prefix Search
vector<int> LPS(string s){
    vector<int> lps(s.length());
    int len=0, i=1;
    
    lps[0]=0;

    while (i<s.length()){
        if (s[i]==s[len]){
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
    return lps;
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