#include <bits/stdc++.h>
#include "structures.h"
#include "algo.h"
#include "Cell.h"

using namespace std;

class Animal : protected Cell
{

public:
  friend double similarityPercentage(Animal A, Animal B) ;
  friend bool operator==(Animal a, Animal b);
  friend Animal operator+(Animal a, Animal b);
  Animal clone();
  Animal();
};

Animal clone(){
  Animal res;
  return res;
}

double similarityPercentage(Animal A, Animal B)
{
  double a = 0;
  for (int i = 0; i < min(A.gz.size(),B.gz.size()); i++)
  {
    a += StringSim(A.gz[i].getDNA().s1, B.gz[i].getDNA().s1);
  }
  return a / ((double)(A.gz.size()+B.gz.size())/2);
}

bool operator==(Animal a, Animal b)
{
  if (similarityPercentage(a, b) >= 70)
    return true;
  else return false;
}

Animal operator+(Animal a, Animal b)
{
}
