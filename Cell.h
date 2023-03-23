#include <bits/stdc++.h>
#include <algo.h>
#include <structures.h>

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
private:
  int cntChromo;
  vc<vc<Genome>> gz;

public:
  Cell(vc<Genome> r);
  void Celldie();
  
};

class Animal : private Cell
{
  friend bool operator ==(Animal a, Animal b);
  friend Animal operator +(Animal a, Animal b);
private:
  vc<Cell> cz;


public:
  double similarityPercentage();

};

dna Genome::RNAtoDNA()
{
  dna duh;
  duh.s1 = RNA;
  for(auto x:RNA){
    duh.s2 += complement(x);
  }
  return duh;
}

Genome::Genome(string rn){
    this->RNA=rn;
}

Genome::Genome(string dn1, string dn2){
    this->DNA.s1=dn1;
    this->DNA.s1=dn2;
}

Genome::Genome(string rn, string dn1, string dn2){
    this->RNA=rn;
    this->DNA.s1=dn1;
    this->DNA.s1=dn2;
}

void Genome::des(){
  ~Genome();
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
    if(DNA.s1[i] == A and c2 != n){
      DNA.s1[i] = C;
      c2++;
    }
  }
  for(auto x:DNA.s1){
    DNA.s2 += complement(x);
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

// fixed with def functions, to be updated with algo.h functions
void Genome::revMut(string S1)
{
  reverse(S1.begin(), S1.end());
  string S2 = S1;
  reverse(S1.begin(), S1.end());
  size_t r = RNA.find(S1);
  for (int i = r; i < S1.size() + r; i++)
    RNA[i] = S2[i];

  if (DNA.s1.find(S1) < DNA.s2.find(S2))
  {
    size_t t = DNA.s1.find(S1);
    for (int i = t; i < S1.size() + t; i++)
      DNA.s1[i] = S2[i];
  }
  else
  {
    size_t t = DNA.s1.find(S2);
    for (int i = t; i < S2.size() + t; i++)
      DNA.s1[i] = S2[i];
  }
  for(auto x:DNA.s1){
    DNA.s2 += complement(x);
  }
}

dna Genome::getDNA(){
  return DNA;
}

string Genome::getRNA(){
  return RNA;
}

Cell ::Cell(vc<Genome> r){
  gz.pb(r);
}

void Cell::Celldie(){

}

bool operator ==(Animal a, Animal b){
  
}

Animal operator +(Animal a, Animal b){

}