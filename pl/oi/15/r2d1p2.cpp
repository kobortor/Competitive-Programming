#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
const int MAXL = 105;
const int MAXM = 100005;

const ll mod = 1e9 + 7;

int N, L, M;

int train[MAXN][MAXL];
unordered_map<ll, vector<int>> ump;

int best[MAXN];

ll get_hash(int id){
    ll hsh = 0;
    for(int a = 1; a <= L; a++){
        hsh = hsh * mod + train[id][a];
    }
    return hsh;
}

void add(int id){
    vector<int> &vec = ump[get_hash(id)];
    vec.push_back(id);
    for(int i : vec){
        best[i] = max(best[i], (int)vec.size());
    }
}

void remove(int id){
    auto iter = ump.find(get_hash(id));
    swap(*find(allof(iter->second), id), iter->second.back());
    iter->second.pop_back();
    if(iter->second.empty()){
        ump.erase(iter);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> L >> M;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= L; b++){
            char ch;
            cin >> ch;
            train[a][b] = ch - 'a';
        }
        add(a);
    }

    for(int a = 1; a <= M; a++){
        int p1, w1, p2, w2;
        cin >> p1 >> w1 >> p2 >> w2;

        if(train[p1][w1] == train[p2][w2]) continue;

        if(p1 == p2){
            remove(p1);
        } else {
            remove(p1);
            remove(p2);
        }

        swap(train[p1][w1], train[p2][w2]);

        if(p1 == p2){
            add(p1);
        } else {
            add(p1);
            add(p2);
        }
    }
    for(int a = 1; a <= N; a++){
        cout << best[a] << "\n";
    }
}
