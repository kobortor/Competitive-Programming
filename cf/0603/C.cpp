#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K;

int hardcode[11] = {0, 1, 0, 1, 2, 0, 2, 0, 1, 0, 1};

int get_sprague_1(int val){
    int tmp = val;
    while(tmp % 4 == 0){
        tmp /= 4;
    }

    if(val <= 10){
        return hardcode[val];
    } else if(tmp == 6 || (val % 4 == 0 && tmp % 2 == 1 && tmp != 3)){
        return 2;
    } else {
        return (val + 1) % 2;
    }
}

int get_sprague_2(int val){
    if(val == 1){
        return 1;
    } else if(val == 2){
        return 2;
    } else {
        return (val + 1) % 2;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    int xorv = 0;
    if(K % 2 == 1){
        for(int a = 1; a <= N; a++){
            int x;
            cin >> x;
            xorv ^= get_sprague_1(x);
        }
    } else {
        for(int a = 1; a <= N; a++){
            int x;
            cin >> x;
            xorv ^= get_sprague_2(x);
        }
    }

    if(xorv == 0){
        cout << "Nicky";
    } else {
        cout << "Kevin";
    }
}
