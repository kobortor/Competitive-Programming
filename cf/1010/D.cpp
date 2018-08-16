#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N;

/*
0 - AND
1 - OR
2 - XOR
3 - NOT
4 - IN
*/
int tp[MAXN];
pii child[MAXN];

bool ans[MAXN];
int val[MAXN];

int predfs(int pos){
    if(tp[pos] == 0){
        return val[pos] = predfs(child[pos].first) & predfs(child[pos].second);
    } else if (tp[pos] == 1){
        return val[pos] = predfs(child[pos].first) | predfs(child[pos].second);
    } else if (tp[pos] == 2){
        return val[pos] = predfs(child[pos].first) ^ predfs(child[pos].second);
    } else if (tp[pos] == 3){
        return val[pos] = !predfs(child[pos].first);
    } else { //tp[pos] == 4
        return val[pos] = child[pos].first;
    }
}

void dfs(int pos, int v0, int v1){
    if(tp[pos] == 0){
        dfs(child[pos].first, v0, val[child[pos].second] ? v1 : v0);
        dfs(child[pos].second, v0, val[child[pos].first] ? v1 : v0);
    } else if (tp[pos] == 1){
        dfs(child[pos].first, val[child[pos].second] ? v1 : v0, v1);
        dfs(child[pos].second, val[child[pos].first] ? v1 : v0, v1);
    } else if (tp[pos] == 2){
        dfs(child[pos].first, val[child[pos].second] ? v1 : v0, val[child[pos].second] ? v0 : v1);
        dfs(child[pos].second, val[child[pos].first] ? v1 : v0, val[child[pos].first ] ? v0 : v1);
    } else if (tp[pos] == 3){
        dfs(child[pos].first, v1, v0);
    } else { //tp[pos] == 4
        if(child[pos].first){
            ans[pos] = v0;
        } else {
            ans[pos] = v1;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        string str;
        cin >> str;
        if(str == "AND"){
            tp[a] = 0;
            cin >> child[a].first >> child[a].second;
        } else if (str == "OR"){
            tp[a] = 1;
            cin >> child[a].first >> child[a].second;
        } else if (str == "XOR"){
            tp[a] = 2;
            cin >> child[a].first >> child[a].second;
        } else if (str == "NOT"){
            tp[a] = 3;
            cin >> child[a].first;
        } else {
            tp[a] = 4;
            cin >> child[a].first;
        }
    }

    predfs(1);
    dfs(1, 0, 1);

    for(int a = 1; a <= N; a++){
        if(tp[a] == 4){
            cout << ans[a];
        }
    }
}
