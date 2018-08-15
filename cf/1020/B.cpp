#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;
int stu[MAXN];

int incoming[MAXN];

int soln[MAXN];
int dfs(int pos){
    if(incoming[pos] || stu[pos] == pos){
        return soln[pos] = pos;
    }
    if(soln[pos]){
        return soln[pos];
    }
    return soln[pos] = dfs(stu[pos]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> stu[a];
        incoming[stu[a]]++;
    }

    queue<int> q;
    for(int a = 1; a <= N; a++){
        if(!incoming[a]){
            q.push(a);
        }
    }

    while(!q.empty()){
        int fr = q.front();
        q.pop();

        incoming[stu[fr]]--;
        if(!incoming[stu[fr]]){
            q.push(stu[fr]);
        }
    }

    for(int a = 1; a <= N; a++){
        cout << dfs(a) << " ";
    }
}
