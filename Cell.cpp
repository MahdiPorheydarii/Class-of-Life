#include "Cell.h"
using namespace std;

vector<Genome> g;
vector<Cell> c;
vector<Animal> a;

void GenSet(int n){
  for(int i = 0; i < n; i++){
    string rn1, dn1, dn2;
    cout << "enter number " << i+1 << " Genome's RNA:" << endl;
    cin >> rn1;
    cout << "enter number " << i+1 << " Genome's part 1 DNA:" << endl;
    cin >> dn1;
    cout << "enter number " << i+1 << " Genome's part 2 DNA:" << endl;
    cin >> dn2;
    Genome tmp(rn1, dn1, dn2);
    g.push_back(tmp);
  }
  system("cls");
  cout << "you have succesfully added Genomes to database, please choose your next wish:" << endl;
}

void CellSet(int n, int a){
  vector<Genome> tempo;
  for(int i = 1; i < a+1; i++){
    string dn1, dn2;
    cout << "enter number " << n+1 << " Cell's number " << i << " Genome's part 1 DNA:" << endl;
    cin >> dn1;
    cout << "enter number " << n+1 << " Cell's number " << i << " Genome's part 2 DNA:" << endl;
    cin >> dn2;
    Genome tmp(dn1, dn2);
    tempo.push_back(tmp);
  }
  Cell yum(tempo);
  c.push_back(yum);
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
    int cCount;
    cout << "how many Cells do you want to create?" << endl;
    cin >> cCount;
    for(int i = 0; i < cCount; i++){
      int q;
      cout << "how many Genomes does Cell " << i + 1 << " numbered have?" << endl;
      cin >> q;
      CellSet(i, q);
    }
    system("CLS");
    cout << "you have succesfully added your Cells to database, please choose your next wish:" << endl;
    return;
  }
  if(ch == 3){
    int aCount;
    cout << "how many animals do you want to create?" << endl;
    cin >> aCount;
    for(int i = 0; i < aCount; i++){
      int gzz;
        cout << "how many chromosomes does your " << i+1 <<" numbered animal cell have?" << endl;
        cin >> gzz;
        Animal A1;
        vector<Genome> ttmp;
        for(int i = 0; i < gzz; i++){
          string dn1, dn2;
          cout << "enter number " << i+1 << " Chromosome's part 1 DNA:" << endl;
          cin >> dn1;
          cout << "enter number " << i+1 << " Chromosome's part 2 DNA:" << endl;
          cin >> dn2;
          Genome tomp(dn1, dn2);
          ttmp.push_back(tomp);
        }
        A1.setCell(ttmp);
    }
  }
  if(ch == 4){
    int ch4;
    cout << "please choose the object you want to perform on :" << endl;
    cout << " 1- Genome\n 2- Cell" << endl;
    cin >> ch4;
    if((ch4 == 1 and g.size() == 0) or (ch4 == 2 and c.size() == 0)){
      cout << "You have not added any "; (ch4 == 1) ? cout << "Genome" : cout << "Cell"; cout << " to the database yet, please try again" << endl;
    }
    else if(ch4 == 1){
      int num, nuum;
      char s1, s2;
      cout << "please tell us the Genome's index which you want to perform a short mutation on(1 based):" << endl;
      cin >> num;
      cout << "please tell us the string you want to look for in Genome:" << endl;
      cin >> s1;
      cout << "please tell us the string you want to replace in Genome:" << endl;
      cin >> s2;
      cout << "please tell us the number of times which you want to perform the act(n)" << endl;
      cin >> nuum;
      g[num-1].shortMut(s1, s2, nuum);
      cout << "short mutation has been performed." << endl << "Genome after the performance:" << endl;
      cout << "Genome's RNA:\n" << g[num-1].getRNA() << endl << "Genome's DNA:\n" << g[num-1].getDNA().s1 << endl << g[num-1].getDNA().s2 << endl;
      return;
    }
    else if(ch4 == 2){
    }
  }
  if(ch == 5){
    int ch5;
    cout << "please choose the object you want to perform on :" << endl;
    cout << " 1- Genome\n 2- Cell" << endl;
    cin >> ch5;
    if((ch5 == 1 and g.size() == 0) or (ch5 == 2 and c.size() == 0)){
      cout << "You have not added any "; (ch5 == 1) ? cout << "Genome" : cout << "Cell"; cout << " to the database yet, please try again" << endl;
    }
  }
  if(ch == 6){
    int ch6;
    cout << "please choose the object you want to perform on :" << endl;
    cout << " 1- Genome\n 2- Cell" << endl;
    cin >> ch6;
    if((ch6 == 1 and g.size() == 0) or (ch6 == 2 and c.size() == 0)){
      cout << "You have not added any "; (ch6 == 1) ? cout << "Genome" : cout << "Cell"; cout << " to the database yet, please try again" << endl;
    }
  }
  if(ch == 7){
    int ch7;
    cout << "please tell us the Genome's index which you want to perform a RNA to DNA transform on(1 based):" << endl;
    cin >> ch7;
    cout << g[ch7 - 1].RNAtoDNA().s1 << endl << g[ch7 - 1].RNAtoDNA().s2 << endl;
    return;
  }
}

int main(){
 go();
}