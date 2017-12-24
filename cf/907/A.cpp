#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool can_fit(int person, int car) {
    return person <= car;
}

bool likes(int person, int car){
    return can_fit(person, car) && person * 2 >= car;
}

int main(){
    int V1, V2, V3, VM;
    cin >> V1 >> V2 >> V3 >> VM;

    for(int C1 = 200; C1 >= 0; C1--){
        if(!likes(V1, C1)){
            continue;
        }
        for(int C2 = C1 - 1; C2 >= 0; C2--){
            if(!likes(V2, C2)){
                continue;
            }
            for(int C3 = C2 - 1; C3 >= 0; C3--){
                if(!likes(V3, C3)){
                    continue;
                }
                //can fit everything, but only likes smallest car
                if(can_fit(VM, C3) && likes(VM, C3) && !likes(VM, C2) && !likes(VM, C1)){
                    cout << C1 << "\n";
                    cout << C2 << "\n";
                    cout << C3 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << -1;
}