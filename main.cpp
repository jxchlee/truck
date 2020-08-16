#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;




int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum_weight=0;
    while(truck_weights.size() == 0){
      








      answer++;                         //한 턴이 지날 때 마다 1초 증가
    }
    return answer;
}


int main() {
  
  int leng = 2;
  int weight = 10;
  vector<int> truck = {7,4,5,6};

  solution(leng, weight, truck);
}