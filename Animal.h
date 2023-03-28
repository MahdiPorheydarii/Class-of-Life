#include <bits/stdc++.h>
#include "structures.h"
#include "algo.h"
#include "Cell.h"

using namespace std;

class Animal : protected Cell
{

public:
  friend double similarityPercentage(Animal A, Animal B) ;
  friend Animal clone();
  friend bool operator==(Animal a, Animal b);
  friend Animal operator+(Animal a, Animal b);
  Animal clone();
  Animal();
};

Animal Animal::clone(){
  Animal res;
  if (gz.size()<10){
    res.gz=gz;
    return res;
  } else {
    res.gz=gz;
    res.gz.pop_back();
    srand(time(0));
    int rand_id=rand()%gz.size();
    res.gz.push_back(gz[rand_id]);
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
