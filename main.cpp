#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>


using namespace std;


void change_truck(int *bridge, int size);


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum_weight=0;                    //다리 위를 지나는 트럭의 무게
    int size = truck_weights.size()/2+1;  //다리 위 트럭들의 이동 거리 배열의 크기
    int *bridge = new int[size];        // 메모리 신경 안쓰고 트럭 개수만큼 줄까하다가 메모리 적게 할 당하는 법 연습하려고 일부러 작은 값으로 줌
    queue<int> truck;
    
    int i;
    for(i=0; i<size; i++){              //배열 초기화
      bridge[i] = 0;
    }
    while(truck_weights.size() > 0){
      for(i=0; i<size; i++){
        if(bridge[i] != 0){
          if(++bridge[i]>bridge_length){   //트럭이 다리를 다 건넜을 경우(새로 들어올 수도 있어서 이미 다리 위에 있는 트럭들 먼저 작업 해줌)
            bridge[i] = 0;              
            sum_weight -= truck.front();
            truck.pop();
          }
        }
      }
      
      if(sum_weight + truck_weights.back() <= weight){
        sum_weight += truck_weights.back();             //트럭 무게 추가(무게합계에 추가)
        truck.push(truck_weights.back());               //트럭 무게 추가22(큐에 추가)
        truck_weights.pop_back();                       //올라간 트럭 배열에서 삭제
        
        for(i=0; i<size; i++){
          if(bridge[i] == 0){       //0이 되는 배열이 있다면 새로운 트럭은 여기에 넣고 탈출
            bridge[i]++;
            break;
          }
          if(i == size-1){          //마지막 배열까지 0이 없으면(=자리가 없으면) 새롭게 더 넓은 배열을 만든다.
            size += 5;
            change_truck(bridge, size);
          }
        }
      }
      answer++;                         //한 턴이 지날 때 마다 1초 증가
      printf("%d\n", truck_weights.back());
      printf("%dgg\n", sum_weight);
    }
    answer += bridge_length;
    printf("%d", answer);
    return answer;
}


int main() {
  
  int leng = 2;
  int weight = 10;
  vector<int> truck = {7,4,5,6};

  solution(leng, weight, truck);
}



void change_truck(int *bridge, int size){
  int *other_truck = new int[size];
  for(int i=0; i<size-5; i++){
    other_truck[i] = bridge[i];
  }
  for(int i=size-3; i<size; i++){
    other_truck[i] = 0;
  }

  delete[] bridge;

  bridge = other_truck;
  
}