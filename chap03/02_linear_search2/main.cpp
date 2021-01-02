/*
 * 線形探索法2
 * 特定の要素の存在する添字も取得する
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
  int N, v, elm, index;
  bool isExist = false;

  // 入力の受け取り
  cin >> N >> v;

  for(int i = 0; i < N; i++){
    cin >> elm;

    if(elm == v){
      isExist = true;
      index = i;
    }
  }

  string msg;
  if(isExist){
    msg.append("Yes: index: ");
    msg.append(to_string(index));
    msg.append("\n");
    cout << msg;
  } else {
    cout << "No\n";
  }

  return 0;
}
