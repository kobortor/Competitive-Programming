#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int score[16];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < 16; a++){
        cin >> score[a];
    }

    int ans = 0;
    for(int a = 0; a < 16; a++){
        int newscore = score[a] + 300;

        int abv = 0;
        for(int b = 0; b < 16; b++){
            if(score[b] > newscore){
                abv++;
            }
        }

        if(abv <= 3){
            ans++;
        }
    }

    cout << ans;

}
