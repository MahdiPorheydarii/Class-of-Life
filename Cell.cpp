#include <bits/stdc++.h>

using namespace std;

class Gene{
  private:
    string DNA, RNA;


  public:
    string createDNA();
    string RNAtoDNA();
    void shortMut(char a, char b, int c);
    void longMut(string S1, string S2);
    void revMut(string S1);
    void fix();
    
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
  //RNA
  size_t r = RNA.find(S1);
  string d;
  for(int i = 0; i < r; i++) d+= RNA[i];
  d += S2;
  for(int i = r+S1.size()+S2.size(); i < RNA.size(); i++) d+= RNA[i];
  //RNA

  //DNA
      //DNA here
  //DNA
}

void Gene::revMut(string S1){
  reverse(S1.begin(), S1.end());
  string S2 = S1;
  reverse(S1.begin(), S1.end());
  size_t r = RNA.find(S1);
  for(int i = r; i < S1.size() + r; i++){
    RNA[i] = S2[i];
  }

  if(DNA.find(S1) < DNA.find(S2)){
    size_t t = DNA.find(S1);
    for(int i = t; i < S1.size() + t; i++){
    DNA[i] = S2[i];
    } 
    fix();
  }
  else{
    size_t t = DNA.find(S2);
    for(int i = t; i < S2.size() + t; i++){
    DNA[i] = S2[i];
    } 
    fix();
  }
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

