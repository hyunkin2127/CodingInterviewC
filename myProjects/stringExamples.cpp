#include <string>
#include <iostream>
using namespace std;

class stringTest{
private:
  string str;

public:

  stringTest(string str):str(str){};

  void showStr() const{
    cout<<str<<endl;
  }

  string getStr() const{
    return str;
  }
};


void findDuplicate(string str){

  char a;
  bool isDuplicated;

  for(int i=0; i<str.length(); i++){
    a = str[i];
    isDuplicated = false; 
    for(int j=i+1; j<str.length() && !isDuplicated; j++){
      if( a == str[j] ){
        cout<<str[j]<<endl;
        isDuplicated = true;
        break;
      }
    }
    cout<<i<<":  break"<<endl;
    if(!isDuplicated) {
      cout<<"This is not duplicated : "<<a<<endl;
      return;
    }
  }
};