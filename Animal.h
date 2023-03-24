#include <bits/stdc++.h>
#include "structures.h"
#include "algo.h"
#include "Cell.h"

using namespace std;



class Animal : public Cell
{
  friend bool operator ==(Animal a, Animal b);
  friend Animal operator +(Animal a, Animal b);

public:
  Animal();
  double similarityPercentage();

};

bool operator ==(Animal a, Animal b){
  
}

Animal operator +(Animal a, Animal b){

}

double Animal::similarityPercentage(Animal A, Animal B){
  double a = 0;
  for(int i = 0; i < A.getGz().size(); i++){
    a += StringSim(A.getGz()[i].getDNA().s1, B.getGz()[i].getDNA().s1);
  }
  return a / A.getGz().size();
}