#include <bits/stdc++.h>
#include "structures.h"
#include "algo.h"
#include "Cell.h"

using namespace std;

class Animal : public Cell
{
  friend class Virus;
public:
  friend double similarityPercentage(Animal A, Animal B);
  friend bool operator==(Animal a, Animal b);
  friend Animal operator+(Animal a, Animal b);
  Animal clone();
  Animal();
  Animal(Cell a);
  vector<bool> alive();
};

class Virus
{
  friend class Animal;
private:
  string RNA;

public:
  Virus(string a);
  bool isBad(Animal A);

};

Animal::Animal(Cell a){
  for(auto x:a.getGz())
    gz.push_back(x);
}
Animal Animal::clone(){
  vector<Genome> r;
  Cell c;
  if (gz.size()<10){
    c.setCell(gz);
    Animal A1(c);
    return A1;
  } else {
    r = gz;
    r.pop_back();
    srand(time(0));
    int rand_id=rand()%gz.size();
    r.push_back(gz[rand_id]);
    c.setCell(r);
    Animal A1(c);
    return A1;
  }
}

double similarityPercentage(Animal A, Animal B)
{
  int num_sim=0;
  for (int i=0; i<min(A.gz.size(), B.gz.size());i++){
    if (A.gz[i].getDNA().s1==B.gz[i].getDNA().s1 and A.gz[i].getDNA().s2==B.gz[i].getDNA().s2){
      ++num_sim;
    }
  }
  return (double)num_sim / ((double)max(A.gz.size(), B.gz.size()))*100.0;
}

bool operator==(Animal a, Animal b)
{
  if (similarityPercentage(a, b) >= 70 and a.gz.size()==b.gz.size())
    return true;
  return false;
}

Animal operator+(Animal a, Animal b)
{
  Animal A = a.clone();
  Animal B = b.clone();
  vector<Genome> res;
  if(A.gz.size() < 10)
    res = A.gz;
  else{
    for(int i = 0; i < (0.7 * A.gz.size()); i++){
      res.push_back(A.gz[i]);
    }
    for(int i = res.size(); i < A.gz.size(); i++){
      srand(time(0));
      int pick = rand() % B.gz.size();
      res.push_back(B.gz[pick]);
    }
  }
  Cell tmp;
  tmp.setCell(res);
  Animal tt(tmp);
  return tt;
}

Virus::Virus(string a){
  RNA = a;
}
bool Virus::isBad(Animal A){
  vector<string> DNAs;
  for(auto x:A.gz){
    DNAs.push_back(x.getDNA().s1);
  }
  string fin = LongestCommonSubstring(DNAs);
  string fin1;
  for(auto x:fin){
    fin1 += complement(x);
  }
  if(KMP(fin1, RNA) != -1 or KMP(fin, RNA) != -1){
    return 1; // is bad
  }
  return 0; // is not bad
}

vector<bool> Animal::alive(){
  Cell tmp;
  tmp.setCell(gz);
  return tmp.alive();
}