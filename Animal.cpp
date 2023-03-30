#include "Animal.h"

using namespace std;

vector<Animal> Az;
vector<Cell> Cz;
vector<Virus> Vz;

void setGz(int a){
  vector<Genome> r;
  Cell c;
  for(int i = 0; i < a; i++){
    string dn1, dn2;
    cout << "enter number " << i+1 << " Chromosome's part 1 DNA:" << endl;
    cin >> dn1;
    cout << "enter number " << i+1 << " Chromosome's part 2 DNA:" << endl;
    cin >> dn2;
    Genome tmp(dn1, dn2);
    r.push_back(tmp);
  }
  c.setCell(r);
  Cz.push_back(c);
}

void go(){
  y : ;
  int ch, tmp;
  cout << "please choose what you want to do:" << endl;
  cout << " 1- Create Animal(s)\n 2- Create a Virus\n 3- perform a similarity check between 2 Animals\n 4- breed check(== operator)\n 5- reproduction by Cell division(Asexual reproduction)"<< endl;
  cout << " 6- Sexual reproduction(operator +)\n 7- perform a virus check\n 8- perform cell die method on a specific Animal\n 9- exit\n";
  x : ;
  cin >> ch;
  if(ch > 9 or ch < 1){
    cout << "wrong number, please try again";
    goto x;
  }
  else if(ch == 1){
    cout << "how many animals do you want to create?" << endl;
    cin >> tmp;
    for(int i =0; i < tmp; i++){
      int gCount;
      cout << "enter your numbered " << i+1 << " animal's Cell size(count of Chromosomes):" << endl;
      cin >> gCount;
      setGz(gCount);
      cout << "you have succesfully added Animal number " << i+1 << " to database" << endl;
    }
    for(auto x:Cz){
      Az.push_back(Animal(x));
    }
    system("CLS");
    goto y;
  }
  else if(ch == 2){
    string r;
    cout << "Please enter the virus RNA:" << endl;
    cin >> r;
    Virus tt(r);
    Vz.push_back(tt);
    cout << "you have succesfully added a Virus to database" << endl;
    goto y;
  }
  else if(ch == 3){
    int f,s;
    cout << "please enter the first Animal's index which you want to compare:(1 based)" << endl;
    cin >> f;
    cout << "please enter the second Animal's index which you want to compare:(1 based)" << endl;
    cin >> s;
    cout << similarityPercentage(Az[f-1], Az[s-1]) << endl;
    goto y;
  }
  else if(ch == 4){
    int f,s;
    cout << "please enter the first Animal's index which you want to compare:(1 based)" << endl;
    cin >> f;
    cout << "please enter the second Animal's index which you want to compare:(1 based)" << endl;
    cin >> s;
    (Az[f-1] == Az[s-1]) ? cout << "Animals are from the same breed(True)" << endl : cout << "Animals are not from the same beed(False)" << endl;
    goto y;
  }
  else if(ch == 5){
    cout << "please enter the Animal's index which you want to reproduct(1 based):" << endl;
    cin >> tmp;
    cout << "reproduction has been performed, new Animal's Cell structure:" << endl;
    Animal temp = Az[tmp - 1].clone();
    for(int i = 0; i < temp.gz.size(); i++){
      cout << "Chromosome " << i+1 << "'s DNA:" << endl;
      cout << temp.gz[i].getDNA().s1 << endl << temp.gz[i].getDNA().s2 << endl;
    }
    goto y;
  }
  else if(ch == 6){
    int f,s;
    cout << "please enter the first Animal's index which you want to use in reproduction:(1 based)" << endl;
    cin >> f;
    cout << "please enter the second Animal's index which you want to use in reproduction:(1 based)" << endl;
    cin >> s;
    if(Az[f - 1].gz.size() != Az[s - 1].gz.size()){ cout << "Cell size of these Animals are different they can't reproduce together." << endl; goto y;}
    if(Az[f - 1].gz.size() % 2){ cout << "Cell size of Animals are odd they can't reproduce together." << endl; goto y;}
    else{
      Animal c = Az[f - 1] + Az[s - 1];
      cout << "reproduciton has been done\nnew Animal's Cell:" << endl;
      int i = 1;
      for(auto x:c.gz){
        cout << "Chromosome's number " << i << "'s DNA:" << endl << x.getDNA().s1 << endl << x.getDNA().s2 << endl;
        i++;
      }
    }
    cout << endl;
    goto y;
  }
  else if(ch == 7){
    int Ac, Vc;
    cout << "please enter the Animal index you want to perform a virus check on(1 based):" << endl;
    cin >> Ac;
    cout << "please enter the Virus index you want to check on choosed Animal(1 based):" << endl;
    cin >> Vc;
    if(Vz[Vc - 1].isBad(Az[Ac - 1])){
      cout << "chosen Virus is dangerous for chosen Animal" << endl;
    }
    else cout << "chosen Virus is not dangerous for chosen Animal" << endl;
    goto y;
  }
  // else if(ch == 8){
  //   int Ap;
  //   cout << "please choose Animal's index which you want to perform cell die method on(1 based):" << endl;
  //   cin >> Ap;
  //   vector<bool> r = Az[Ap - 1].Alive();
  //   cout << "Alive Chromosomes :" << endl << endl;
  //   for(int i = 0; i < Az[Ap - 1].gz.size(); i++){
  //     if(r[i]) cout << "chromosome " << i+1 << "'s DNA : " << "\t" << Az[Ap - 1].gz[i].getDNA().s1 << "\t" << Az[Ap - 1].gz[i].getDNA().s2 << endl << endl;
  //   }
  //   cout << "Dead Chromosomes :" << endl << endl;
  //   for(int i = 0; i < Az[Ap - 1].gz.size(); i++){
  //     if(!r[i]) cout << "chromosome " << i+1 << "'s DNA : " << "\t" << Az[Ap - 1].gz[i].getDNA().s1 << "\t" << Az[Ap - 1].gz[i].getDNA().s2 << endl << endl;
  //   }
  //   goto y;
  // }
  else if(ch == 9) cout << "Good Bye!" << endl;
}

int main(){
  go();
}