#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 30;

int Ci, Wi, So, Oo;
int Si, Oi, Co, Wo;

//C O W S
bool good[MAXN][MAXN][MAXN][MAXN];
void dfs(int c, int o, int w, int s){
    if(c < 0 || o < 0 || w < 0 || s < 0){
        return;
    }
    if(good[c][o][w][s]){
        return;
    }
    good[c][o][w][s] = true;
    
    //use plant
    dfs(c - Ci, o + Oo, w - Wi, s + So);

    //use fish
    dfs(c + Co, o - Oi, w + Wo, s - Si);
}

void testcase(){
    memset(good, false, sizeof good);

    int C, O, W, S;
    cin >> C >> O >> W >> S;
    cin >> Ci >> Wi >> So >> Oo;
    cin >> Si >> Oi >> Co >> Wo;
    dfs(C, O, W, S);

    int best = 0;
    for(int c = 0; c < MAXN; c++){
        for(int o = 0; o < MAXN; o++){
            for(int w = 0; w < MAXN; w++){
                for(int s = 0; s < MAXN; s++){
                    if(good[c][o][w][s]){
                        best = max(best, o);
                    }
                }
            }
        }
    }
    cout << best << endl;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    const int MAX_CASE = 10;
    for(int a = 1; a <= MAX_CASE; a++){
        testcase();
    }
}
