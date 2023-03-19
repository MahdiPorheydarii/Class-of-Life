#include <bits/stdc++.h>

using namespace std;

class Genome{
  friend class Cell;
  
  private:
    string DNA, RNA;


  public:
    void RNAtoDNA();
    void shortMut(char a, char b, int c);
    void longMut(string S1, string S2);
    void revMut(string S1);
    void fix();
    
};

class Cell{
  private:
    int cntChromo;
    vector<Genome> r;

  public:
    void setGenomes(int n);
    void Celldie();
};

int main(){

}

void Genome::shortMut(char a, char b, int c){
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

void Genome::fix(){
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

void Genome::longMut(string S1, string S2){
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

void Genome::revMut(string S1){
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

void Genome::RNAtoDNA(){
  string s;
  s += RNA;
  s += '+';
  for(int i = 0; i < RNA.size(); i++){
  if(RNA[i] == 'T') s += 'A';
  if(RNA[i] == 'A') s += 'T';
  if(RNA[i] == 'C') s += 'G';
  if(RNA[i] == 'G') s += 'C';
  }
  cout << "DNA is:" << endl;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '+') cout << endl;
    else cout << s[i];
  }
}

void Cell::setGenomes(int n){
  string s1, s2, fin;
  for(int i = 0; i < n; i++){
    cin >> s1 >> s2;
    fin += s1;
    fin += '+';
    fin += s2;
    Genome last;
    last.DNA = fin;
    r.push_back(last);
  }
}