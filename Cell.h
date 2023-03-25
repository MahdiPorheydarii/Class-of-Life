#include <bits/stdc++.h>
#include "structures.h"
#include "algo.h"

using namespace std;

class Genome
{
private:
  dna DNA;
  string RNA;

public:
  dna RNAtoDNA();
  Genome(string rn);
  Genome(string dn1, string dn2);
  Genome(string rn, string dn1, string dn2);
  Genome();
  void des();
  void shortMut(char a, char b, int c);
  void longMut(string S1, string S2);
  void revMut(string S1);
  dna getDNA();
  string getRNA();
};

class Cell : private Genome
{
  friend void CellSet(int n, int a);
  friend void go();
private:
  int cntChromo;
  vector<Genome> gz;

public:
  void setCell(vector<Genome> r);
  void Celldie();
  vector<Genome> getGz();
};

dna Genome::RNAtoDNA()
{
  dna duh;
  duh.s1 = RNA;
  for (auto x : RNA)
  {
    duh.s2 += complement(x);
  }
  return duh;
}

Genome::Genome(string rn)
{
  this->RNA = rn;
}

Genome::Genome(string dn1, string dn2)
{
  this->DNA.s1 = dn1;
  this->DNA.s2 = dn2;
}

Genome::Genome(string rn, string dn1, string dn2)
{
  this->RNA = rn;
  this->DNA.s1 = dn1;
  this->DNA.s2 = dn2;
}

void Genome::des()
{
  // Genome::~Genome();
}

void Genome::shortMut(char A, char C, int n)
{
  int c1 = 0, c2 = 0;
  vector<int> p1, p2;
  for (int i = 0; i < RNA.size(); i++)
  {
    if (RNA[i] == A and c1 != n)
    {
      RNA[i] = C;
      c1++;
    }
    if (DNA.s1[i] == A and c2 != n)
    {
      DNA.s1[i] = C;
      p1.push_back(i);
      c2++;
    }
    if (DNA.s2[i] == A and c2 != n)
    {
      DNA.s2[i] = C;
      p2.push_back(i);
      c2++;
    }
  }
  for (auto x : p1)
  {
    DNA.s2[x] = complement(DNA.s1[x]);
  }
  for (auto x : p2)
  {
    DNA.s1[x] = complement(DNA.s2[x]);
  }
}

// should be completed
void Genome::longMut(string S1, string S2)
{
  // RNA
  size_t r = KMP(S1,RNA);
  string d;
  for(int i = 0; i < r; i++) d+= RNA[i];
  d += S2;
  for(int i = r+S1.size(); i < RNA.size(); i++) d += RNA[i];
  RNA = d;
  // RNA

  // DNA
  size_t f = min(KMP(S1,DNA.s1), KMP(S1,DNA.s2));
  if(KMP(S1,DNA.s1) <= KMP(S1,DNA.s2)){
    string ttmpp, q;
    for(int i = 0; i < f; i++){
      ttmpp += DNA.s1[i];
    }
    ttmpp += S2;
    for(int i = r+S1.size(); i < DNA.s1.size(); i++) ttmpp += DNA.s1[i];
    DNA.s1 = ttmpp;
    for(auto x:DNA.s1){
      q += complement(x);
    }
    DNA.s2 = q;
  }
  else{
    string ttmpp, q;
    for(int i = 0; i < f; i++){
      ttmpp += DNA.s2[i];
    }
    ttmpp += S2;
    for(int i = r+S1.size(); i < DNA.s2.size(); i++) ttmpp += DNA.s2[i];
    DNA.s2 = ttmpp;
    for(auto x:DNA.s2){
      q += complement(x);
    }
    DNA.s1 = q;
  }
  // DNA
}

// next functions should be updated with respect to algo.h and structures.h

// fixed with def functions, to be updated with algo.h functions
void Genome::revMut(string S1)
{
  string temp;
  reverse(S1.begin(), S1.end());
  string S2 = S1;
  reverse(S1.begin(), S1.end());
  size_t r = KMP(S1, RNA);
  for (int i = r; i < S1.size() + r; i++)
    RNA[i] = S2[i];

  if (KMP(S1, DNA.s1) < KMP(S2, DNA.s2))
  {
    size_t t = KMP(S1, DNA.s1);
    for (int i = t; i < S1.size() + t; i++)
      DNA.s1[i] = S2[i];
  }
  else
  {
    size_t t = KMP(S2, DNA.s1);
    for (int i = t; i < S2.size() + t; i++)
      DNA.s1[i] = S2[i];
  }
  for (auto x : DNA.s1)
  {
    temp += complement(x);
  }
  DNA.s2 = temp;
}

dna Genome::getDNA()
{
  return DNA;
}

string Genome::getRNA()
{
  return RNA;
}

void Cell::setCell(vector<Genome> r)
{
  for(auto x:r) gz.push_back(x);
}

void Cell::Celldie()
{
  for (int j = 0; j < gz.size(); j++)
  {
    int die = 0;
    for (int i = 0; i < gz[j].getDNA().s1.size(); i++)
    {
      if (gz[j].getDNA().s1[i] != complement(gz[j].getDNA().s2[i]))
        die++;
    }
    if (die > 4)
    {
      gz[j].des();
      j -= 1;
    }
  }
}

vector<Genome> Cell::getGz()
{
  return gz;
}
