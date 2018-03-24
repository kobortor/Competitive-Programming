#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K, W;
string names[4] = {"Sayori", "Natsuki", "Yuri", "Monika"};
set<string> triggers[4];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> W;
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < W; b++){
            string str;
            cin >> str;
            triggers[a].insert(str);
        }
    }

    for(int a = 0; a < N * K; a++){
        string str;
        cin >> str;
        for(int b = 0; b < 4; b++){
            triggers[b].erase(str);
        }
    }
    int min_sz = 99999;
    for(int b = 0; b < 4; b++){
        min_sz = min(min_sz, (int)triggers[b].size());
    }
    if(min_sz == W){
        return 0;
    }
    for(int b = 0; b < 4; b++){
        if(min_sz == (int)triggers[b].size()){
            cout << names[b] << "\n";
        }
    }   
}
