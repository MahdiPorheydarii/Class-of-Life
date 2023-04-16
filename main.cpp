#include <bits/stdc++.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main(){
  system("cls");
  y : ;
  cout << "which Application do you want to use?" << endl;
  cout << " 1- Cell\n 2- Animal\n 3- exit" << endl;
  char p = getch();
  if(p == '1'){
    system("cd Cell");
    system("c.exe");
  }
  else if(p == '2'){
    system("cd Animal");
    system("a.exe");
  }
  else if(p == '3') cout << "Good Bye!";
  else{
    cout << "wrong number" << endl;
    goto y;
  }
}