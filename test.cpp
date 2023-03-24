#include <bits/stdc++.h>
#include "algo.h"

int main(){
    string s="AAGTCATCT";
    string pat="TCAG";

    int f=KMP(pat,s);
    string tmp="";
    tmp+=s.substr(0,f);
    tmp+="ATC";
    tmp+=s.substr(f+pat.size(),s.size());
    cout<<tmp<<endl;
}