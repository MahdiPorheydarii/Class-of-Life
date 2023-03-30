#include <bits/stdc++.h>
#include "Cell.h"
#include "algo.h"

int main()
{
    string a = "ATCGTAGCATGCGATGAT";
    string b = "CGATGATGATATCGATGAT";
    string c = "CGTAATCGCTAGCGCAGCTGAGGCTCGAT";
    vector<string> v={a,b,c};

    cout<<LongestCommonSubstring(v);
}