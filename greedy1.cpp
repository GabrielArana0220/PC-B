#include <stdio.h>  
#include <vector>
#include <algorithm> 

using namespace std;

struct P{
    int money;
    int time;
    
    P(int m, int w){
        money = m;
        time = w;
    }
};

bool comparar(const P &a, const P &b){
        return a.money >= b.money;
}

void queueP(vector<int> &v, P c){
    int i = c.time;
    
    while(i >= 0){
        if(v[i] == 0){
            v[i] = c.money;
            return;
        }  
        i--;
    }
}

int main(){ 

    int N, T, ci, ti;
    int sum = 0;
    int i = 0;
	
    scanf("%d %d", &N, &T);
    

    vector<int> bQueue(T);
    vector<P> money;
    
    for(int i = 0; i < N; i++){
        scanf("%d %d", &ci, &ti);
        P c(ci, ti);
        money.push_back(c); 
    }
    
    sort(money.begin(), money.end(), comparar);

    while(i < money.size()){
        queueP(bQueue, money[i]);
        i++;
    }
    
    for(int i = 0; i < bQueue.size(); i++){
        sum += bQueue[i];
    }
    
    printf("%d", sum); 
    return 0;
}