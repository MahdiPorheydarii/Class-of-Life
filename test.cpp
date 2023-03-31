#include <bits/stdc++.h>
#include "Cell.h"
#include "algo.h"

int main()
{
    Cell yum;
    vector<Genome> gz;
    Genome g1("","ATCGTCGATCGCTA","GCTAGCTGAGAGAT");
    Genome g2("","GCTAGGTCTAGGCT","ATCGCGCTAGCTAT");
    gz.push_back(g1);
    gz.push_back(g2);
    yum.setCell(gz);
    yum.longMut("CGAT",1,"TAG",2);
    yum.display();
}