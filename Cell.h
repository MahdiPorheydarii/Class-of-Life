#include <bits/stdc++.h>
#include <algo.h>
#include <structures.h>

using namespace std;


class Genome
{
  friend class Cell;

private:
  dna DNA; 
  string RNA;

public:
  void RNAtoDNA();  
  Genome(string rn){
    this->RNA=rn;
    RNAtoDNA();
  }
  Genome();
  
  void shortMut(char a, char b, int c);
  void longMut(string S1, string S2);
  void revMut(string S1);
  void fix();
};

class Cell
{
private:
  int cntChromo;
  vector<Genome> r;

public:
  void setGenomes(int n);
  void Celldie();
};

void Genome::RNAtoDNA()
{
  this->DNA.s1=RNA;
  for (auto x:RNA){
    this->DNA.s2+=complement(x);
  }
  cout<<DNA.s1<<endl;
  cout<<DNA.s2<<endl;
}

void Genome::shortMut(char A, char C, int n)
{
  int c1 = 0, c2 = 0;
  for (int i = 0; i < RNA.size(); i++)
  {
    if (RNA[i] == A and c1 != n)
    {
      RNA[i] = C;
      c1++;
    }
    if(DNA[i] == A and c2 != n){
      DNA[i] = C;
      c2++;
    }
  }
  for (auto x:indexes){
    DNA.s2[x]=complement(DNA.s1[x]);
  }
}


// should be completed
void Genome::longMut(string S1, string S2){
  //RNA
  size_t r = KMP(S1,RNA);
  string d;
  for(int i = 0; i < r; i++) d+= RNA[i];
  d += S2;
  for(int i = r+S1.size()+S2.size(); i < RNA.size(); i++) d+= RNA[i];
  //RNA

  //DNA
      //DNA here
  //DNA
}


// next functions should be updated with respect to algo.h and structures.h
void Genome::revMut(string S1)
{
  reverse(S1.begin(), S1.end());
  string S2 = S1;
  reverse(S1.begin(), S1.end());
  size_t r = RNA.find(S1);
  for (int i = r; i < S1.size() + r; i++)
  {
    RNA[i] = S2[i];
  }

  if (DNA.find(S1) < DNA.find(S2))
  {
    size_t t = DNA.find(S1);
    for (int i = t; i < S1.size() + t; i++)
    {
      DNA[i] = S2[i];
    }
    fix();
  }
  else
  {
    size_t t = DNA.find(S2);
    for (int i = t; i < S2.size() + t; i++)
    {
      DNA[i] = S2[i];
    }
    fix();
  }
}

// fixed
void Cell::setGenomes(int n)
{
  string p1, p2;
  for (int i = 0; i < n; i++)
  {
    cin >> p1 >> p2;
    Genome last;
    last.DNA.s1 = p1;
    last.DNA.s2 = p2;
    r.push_back(last);
  }
}