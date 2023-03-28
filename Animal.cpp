#include "Animal.h"

using namespace std;

void go(){
  int ch;
  cout << "please choose what you want to do:" << endl;
  cout << " 1- Create Animal(s)\n 2- Create a Virus\n 3- perform a similarity check between 2 Animals\n 4- breed check(== operator)\n 5- reproduction by Cell division(Asexual reproduction)"<< endl;
  cout << " 6- Sexual reproduction(operator +)\n 7- perform a virus check\n 8- perform cell die method on a specific Animal\n 9- exit\n";
  x : ;
  cin >> ch;
  if(ch > 9 or ch < 1){
    cout << "wrong number, please try again";
    goto x;
  }
}

int main(){
  go();
}