#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;

ll len[MAXN];
char type[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> len[a];
    }

    ll totG = 0, totW = 0, totL = 0;
    vector<pll> water, grass, lava;
    for(int a = 1; a <= N; a++){
        cin >> type[a];

        if(type[a] == 'G') {
            totG += len[a];
            grass.push_back({a, len[a]});
        }
        if(type[a] == 'W') {
            totW += len[a];
            water.push_back({a, len[a]});
        }
        if(type[a] == 'L') {
            totL += len[a];
            lava.push_back({a, len[a]});
        }
    }

    ll tm = totL + totW * 2 + totG * 3;

    vector<pll> remainG, remainW, remainL;
    int first_water = find(type + 1, type + N + 1, 'W') - type;

    while(!water.empty()){
        while(!lava.empty() && lava.back().first > water.back().first){
            remainL.push_back(lava.back());
            lava.pop_back();
        }

        while(!remainL.empty() && water.back().second != 0){
            ll diff = min(water.back().second, remainL.back().second);
            tm += diff;
            water.back().second -= diff;
            remainL.back().second -= diff;

            if(remainL.back().second == 0) remainL.pop_back();
        }

        if(water.back().second != 0) remainW.push_back(water.back());

        water.pop_back();
    }

    while(!lava.empty()) {remainL.push_back(lava.back()); lava.pop_back();}
    lava.swap(remainL);
    reverse(allof(lava));

    while(!grass.empty()){
        while(!lava.empty() && lava.back().first > grass.back().first){
            remainL.push_back(lava.back());
            lava.pop_back();
        }

        while(!remainL.empty() && grass.back().second != 0){
            ll diff = min(grass.back().second, remainL.back().second);
            tm += diff * 2;
            grass.back().second -= diff;
            remainL.back().second -= diff;

            if(remainL.back().second == 0) remainL.pop_back();
        }

        if(grass.back().second != 0) remainG.push_back(grass.back());

        grass.pop_back();
    }

    water.swap(remainW);
    grass.swap(remainG);

    reverse(allof(water));
    reverse(allof(grass));
    
    while(!water.empty()){
        while(!grass.empty() && grass.back().first > water.back().first){
            remainG.push_back(grass.back());
            grass.pop_back();
        }

        while(!remainG.empty() && water.back().second != 0){
            ll diff = min(water.back().second, remainG.back().second);
            tm -= diff;
            water.back().second -= diff;
            remainG.back().second -= diff;

            if(remainG.back().second == 0) remainG.pop_back();
        }

        water.pop_back();
    }

    while(!lava.empty()) {remainL.push_back(lava.back()); lava.pop_back();}

    for(pll p : remainL){
        if(p.first < first_water){
            tm += p.second * 5;
        } else {
            tm += p.second * 3;
        }
    }

    cout << tm;
}
