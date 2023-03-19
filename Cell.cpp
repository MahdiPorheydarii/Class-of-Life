#include <bits/stdc++.h>

using namespace std;

class Gene{
  private:
    string DNA, RNA;


  public:
    string createDNA();
    void shortMut(char a, char b, int c);
    void longMut(string S1, string S2);
    void fix();
    string RNAtoDNA();
    
};

class Cell{
  private:
    int cntChromo;
    vector<Gene> r;

  public:
    void Celldie();
};
int main(){

}

void Gene::shortMut(char a, char b, int c){
  int q = 0;
  for(int i = 0; i < RNA.size(); i++){
    if(RNA[i] == b){
      RNA[i] = c;
      q++;
    }
    if(q == c) break;
  }
  q = 0;
  for(int i = 0; i < DNA.size() / 2; i++){
  if(DNA[i] == b){
    DNA[i] = c;
    q++;
  }
  if(q == c) break;
  }
  fix();
}

void Gene::fix(){
  string s;
  for(int i = 0; i < DNA.size() / 2; i++) s += DNA[i];
  s += '+';
  for(int i = 0; i < DNA.size() / 2; i++){
    if(DNA[i] == 'T') s += 'A';
    if(DNA[i] == 'A') s += 'T';
    if(DNA[i] == 'C') s += 'G';
    if(DNA[i] == 'G') s += 'C';
  }
  DNA = s;
}

void Gene::longMut(string S1, string S2){


}

string Gene::RNAtoDNA(){
  string s;
  s += RNA;
  s += '+';
  for(int i = 0; i < RNA.size(); i++){
  if(RNA[i] == 'T') s += 'A';
  if(RNA[i] == 'A') s += 'T';
  if(RNA[i] == 'C') s += 'G';
  if(RNA[i] == 'G') s += 'C';
  }
  return s;
}
/sss