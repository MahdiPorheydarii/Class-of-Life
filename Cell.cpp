#include "Cell.h"
using namespace std;

vc<Genome> g;
vc<Cell> c;
vc<Animal> a;

void GenSet(int n){
  for(int i = 0; i < n; i++){
    string rn1, dn1, dn2;
    cout << "enter number " << i+1 << " Genome's RNA" << endl;
    cin >> rn1;
    cout << "enter number " << i+1 << " Genome's part 1 DNA" << endl;
    cin >> dn1;
    cout << "enter number " << i+1 << " Genome's part 2 DNA" << endl;
    cin >> dn2;
    Genome tmp(rn1, dn1, dn2);
    g.pb(tmp);
  }
  system("cls");
  cout << "you have succesfully added Genomes to database, please choose your next wish" << endl;
}

void go(){
  int ch;
  cout << "please choose what you want to do:" << endl;
  cout << " 1- Create Genome(s)\n 2- Create Cell(s)\n 3- create Animal(s)\n 4- perform a short mutation\n 5-perform a long mutation"<< endl;
  cout << " 6- perform a reverse mutation\n 7- perform RNA to DNA transform\n";
  x : ;
  cin >> ch;
  if(ch > 7 or ch < 1){
    cout << "wrong number, please try again";
    goto x;
  }
  if(ch == 1){
    int gCount;
    cout << "how many Genomes do you want to create?" << endl;
    cin >> gCount;
    GenSet(gCount);
    return;
  }
  if(ch == 2){

  }
  if(ch == 3){

  }
  if(ch == 4){
    int ch4;
    cout << "please choose the object you want to perform on :" << endl;
    cout << " 1- Genome\n 2- Cell" << endl;
    cin >> ch4;
    if((ch4 == 1 and g.size() == 0) or (ch4 == 2 and c.size() == 0)){
      cout << "You have not added any "; (ch4 == 1) ? cout << "Genome" ; cout << "Cell"; cout << " to the database yet, please try again" << endl;
    }
  }
}

int main(){
 go();
}