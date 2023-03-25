#include <bits/stdc++.h>
#include "cell.h"

int main()
{
    string a = "AATCCGATCCGCCTTA";
    string b = "AATCCGATCCGCCTTA";
    string c = "TTAGGCTAGGCGGAAT";
    Genome g(a, b, c);
    cout << g.getDNA().s1 << " " << g.getDNA().s2 << endl;
    g.longMut("CTT", "TGAGA");
    cout << g.getDNA().s1 << " " << g.getDNA().s2 << endl;

    return 0;
}