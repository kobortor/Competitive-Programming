#include <bits/stdc++.h>

using namespace std;

bool canGetExactChange(int targetMoney, vector<int>& denominations){
    vector<bool> vec(targetMoney + 1, 0);
    vec[0] = true;

    for (int coin : denominations) {
        for (int i = coin; i <= targetMoney; i++) {
            vec[i] = vec[i] | vec[i - coin];
        }
    }

    return vec[targetMoney];
}

