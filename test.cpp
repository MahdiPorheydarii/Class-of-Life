#include <bits/stdc++.h>
#include "cell.h"

int main()
{
    string a = "AATCCGATCCGCCTTA";
    string b = "AATCCGATCCGCCTTA";
    string c = "TTAGGCTAGGCGGAAT";
    Genome g(a, b, c);
    // cout << g.getDNA().s1 << " " << g.getDNA().s2 << endl;
    // g.longMut("CTT", "TGAGA");
    // cout << g.getDNA().s1 << " " << g.getDNA().s2 << endl;
    
    Cell A;
    vector<Genome> g_genomes;
    g_genomes.push_back(g);
    A.setCell(g_genomes);
    for (auto x: A.getGz()){
        cout<< x.getDNA().s1 << " " << x.getDNA().s2 << endl;
    }

    return 0;
}