#include <bits/stdc++.h>
#include "structures.h"
#include "algo.h"
#include "Cell.h"

using namespace std;

class Animal : public Cell
{

public:
  friend double similarityPercentage(Animal A, Animal B);
  friend bool operator==(Animal a, Animal b);
  friend Animal operator+(Animal a, Animal b);
  Animal clone();
  Animal();
  Animal(Cell a){
    for(auto x:a.getGz())
      gz.push_back(x);
  }
};

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
  else return false;
}

Animal operator+(Animal a, Animal b)
{

}
