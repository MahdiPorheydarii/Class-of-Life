#include <bits/stdc++.h>
#include "structures.h"
#include "algo.h"

#ifndef CELL_H
#define CELL_H

using namespace std;

class Genome
{
protected:
  dna DNA;
  string RNA;

public:
  dna RNAtoDNA();
  Genome(string rn);
  Genome(string dn1, string dn2);
  Genome(string rn, string dn1, string dn2);
  Genome(){};
  void shortMut(char a, char b, int c);
  void longMut(string S1, string S2);
  void revMut(string S1);
  dna getDNA();
  string getRNA();
  void cellDie();
};

class Cell
{
  friend void CellSet(int n, int a);
  friend void go();

protected:
  bool isAlive = 1;
  vector<Genome> gz;

public:
  void shortMut(char a, char b, int n, int index);
  void longMut(string S1, int n, string S2, int b);
  void revMut(string S, int n);
  void setCell(vector<Genome> r);
  vector<Genome> getGz();
  void Alive();
  void cellDie();
  void display();
  void alive();
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

void Genome::shortMut(char A, char C, int n)
{
  int c1 = 0, c2 = 0;
  for (int i = 0; i < RNA.size(); i++)
  {
    if (RNA[i] == A and c1 != n and RNA.size() > 0)
    {
      RNA[i] = C;
      c1++;
    }
  }
  for (int i = 0; i < DNA.s1.size(); i++){
    if (DNA.s1[i] == A and c2 != n)
    {
      this->DNA.s1[i] = C;
      c2++;
      this->DNA.s2[i] = complement(DNA.s1[i]);
    }
    if (DNA.s2[i] == A and c2 != n)
    {
      this->DNA.s2[i] = C;
      c2++;
      this->DNA.s1[i] = complement(DNA.s2[i]);
    }
  }
}

void Genome::longMut(string S1, string S2)
{
  // RNA
  size_t r = KMP(S1, RNA);
  if(r != -1){
  string d;
  for (int i = 0; i < r; i++)
    d += RNA[i];
  d += S2;
  for (int i = r + S1.size(); i < RNA.size(); i++)
    d += RNA[i];
  RNA = d;
  }
  // RNA

  // DNA
  size_t s1id = KMP(S1, DNA.s1);
  size_t s2id = KMP(S1, DNA.s2);
  if (s2id==-1 or (s1id<=s2id and s1id!=-1)){
    string dna1=DNA.s1;
    dna1.replace(s1id,S1.size(),S2);
    this->DNA.s1 = dna1;
    string dna2;
    for (auto x:DNA.s1) dna2+=complement(x);
    this->DNA.s2=dna2;
  } else {
    DNA.s2.replace(s1id,S1.size(),S2);
    string dna1;
    for (auto x:DNA.s2) dna1+=complement(x);
    this->DNA.s1=dna1;
  }
  // DNA
}

void Genome::revMut(string S1)
{
  string temp;
  reverse(S1.begin(), S1.end());
  string S2 = S1;
  reverse(S1.begin(), S1.end());
  size_t r = KMP(S1, RNA);
  if(r != -1){
    for (int i = r; i < S1.size() + r; i++)
      RNA[i] = S2[i - r];
  }
  int s1id = KMP(S1, DNA.s1);
  int s2id = KMP(S1, DNA.s2);
  if(s1id + s2id > -2){
    if (s2id == -1 or (s1id < s2id and s1id != -1))
    {
      size_t t = s1id;
      for (int i = t; i < S1.size() + t; i++)
        DNA.s1[i] = S2[i - t];
      for (auto x : DNA.s1)
        temp += complement(x);
      DNA.s2 = temp;
    }
    else
    {
      size_t t = s2id;
      for (int i = t; i < S1.size() + t; i++)
        DNA.s2[i] = S2[i - t];
      for (auto x : DNA.s2)
        temp += complement(x);
      DNA.s1 = temp;
    }
  }
}

dna Genome::getDNA()
{
  return DNA;
}

string Genome::getRNA()
{
  return RNA;
}

void Genome::cellDie(){
  delete this;
}

void Cell::setCell(vector<Genome> r)
{
  gz = r;
}

void Cell::Alive(){
  for(int i = 0; i < gz.size(); i++){
    int d = 0, AT = 0, CG = 0;
    for (int j = 0; j < gz[i].getDNA().s1.size(); j++)
    {
      if (gz[i].getDNA().s1[j] != complement(gz[i].getDNA().s2[j]))
        d++;
    }
    for(int j = 0; j < gz[i].getDNA().s1.size(); j++){
      if(gz[i].getDNA().s1[j] == 'A' and gz[i].getDNA().s2[j] == 'T' or (gz[i].getDNA().s1[j] == 'T' and gz[i].getDNA().s2[j] == 'A')) AT++;
      if(gz[i].getDNA().s1[j] == 'G' and gz[i].getDNA().s2[j] == 'C' or (gz[i].getDNA().s1[j] == 'C' and gz[i].getDNA().s2[j] == 'G')) CG++;
    }
    if(d > 5 or AT/CG > 3){
      isAlive = 0; cellDie();
    }
  }
}

vector<Genome> Cell::getGz()
{
  return gz;
}

void Cell::revMut(string S, int n)
{
  gz[n].revMut(S);
}

void Cell::shortMut(char a, char b, int n, int index)
{
  gz[index].shortMut(a, b, n);
}

void Cell::longMut(string S1, int a, string S2, int b)
{
  this->gz[a - 1].longMut(S1, S2);
  this->gz[b - 1].longMut(S2, S1);
}

void Cell::cellDie(){
  gz.clear();
  delete this;
}

void Cell::display(){
  for (int i = 0; i <gz.size(); i++){
    cout<<i+1<<endl;
    cout<<gz[i].getRNA()<<endl<<gz[i].getDNA().s1<<endl<<gz[i].getDNA().s2<<endl;
  }
}

void Cell::alive(){
  for(int i = 0; i < gz.size(); i++){
    int d = 0, AT = 0, CG = 0;
    for (int j = 0; j < gz[i].getDNA().s1.size(); j++)
    {
      if (gz[i].getDNA().s1[j] != complement(gz[i].getDNA().s2[j]))
        d++;
    }
    for(int j = 0; j < gz[i].getDNA().s1.size(); j++){
      if(gz[i].getDNA().s1[j] == 'A' and gz[i].getDNA().s2[j] == 'T' or (gz[i].getDNA().s1[j] == 'T' and gz[i].getDNA().s2[j] == 'A')) AT++;
      if(gz[i].getDNA().s1[j] == 'G' and gz[i].getDNA().s2[j] == 'C' or (gz[i].getDNA().s1[j] == 'C' and gz[i].getDNA().s2[j] == 'G')) CG++;
    }
    if(d > 5 or AT/CG > 3){
      gz[i].cellDie();
    }
  }
}
#endif