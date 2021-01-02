#include <limits>
#include <string>
#include <iostream>

using namespace std;

int main(){
  int N, elm;
  int min_value = std::numeric_limits<int>::max();
  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> elm;
    if(elm < min_value){
      min_value = elm;
    }
  }

  string msg = "MinValue: ";
  msg.append(to_string(min_value));
  msg.append("\n");

  cout << msg;

  return 0;
}
