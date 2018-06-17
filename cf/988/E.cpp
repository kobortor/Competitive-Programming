#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 20;

int N;
int ans = 1e9;

string str;
int zeros;

void solve(int s1, int s2){
    //cout << "Check " << s1 << " " << s2 << endl;
    if(s1 == N - 2 && s2 == N - 1){
        ans = 0;
        return;
    }

    unordered_map<int, int> dp;

    dp[zeros * 400 + s1 * 20 + s2] = 0;

    queue<pair<int, pii>> q;
    q.push({zeros, {s1, s2}});

    while(!q.empty()){
        int state = q.front().first;
        s1 = q.front().second.first;
        s2 = q.front().second.second;
        int nxtdist = dp[state * 400 + s1 * 20 + s2] + 1;
        
        q.pop();

        for(int a = 0; a + 1 < N; a++){
            int v1 = s1 == a || s1 == a + 1 ? a + a + 1 - s1 : s1;
            int v2 = s2 == a || s2 == a + 1 ? a + a + 1 - s2 : s2;

            int newstate = state & ~(3 << a);

            if(state & (1 << a)){
                newstate |= 2 << a;
            }
            if(state & (2 << a)){
                newstate |= 1 << a;
            }

            if(newstate & 1){
                continue;
            }

            if(newstate == state && v1 == s1 && v2 == s2){
                continue; //no change, no point
            }

            if(!dp.count(newstate * 400 + v1 * 20 + v2)){
                if(v1 == N - 2 && v2 == N - 1){
                    ans = min(ans, nxtdist);
                    return;
                }
                q.push({newstate, {v1, v2}});
                dp[newstate * 400 + v1 * 20 + v2] = nxtdist;
            }
        }
    }
}

void solve00(){
    int s1 = -1, s2 = -1;
    for(int a = 0; a < N; a++){
        if(str[a] == '0'){
            s1 = s2;
            s2 = a;
        }
    }

    if(s1 != -1 && s2 != -1){
        solve(s1, s2);
    }
}

void solve25(){
    int s1 = -1, s2 = -1;
    for(int a = 0; a < N; a++){
        if(str[a] == '2'){
            s1 = a;
        }
        if(str[a] == '5'){
            s2 = a;
        }
    }

    if(s1 != -1 && s2 != -1){
        solve(s1, s2);
    }
}

void solve50(){
    int s1 = -1, s2 = -1;
    for(int a = 0; a < N; a++){
        if(str[a] == '5'){
            s1 = a;
        }
        if(str[a] == '0'){
            s2 = a;
        }
    }

    if(s1 != -1 && s2 != -1){
        solve(s1, s2);
    }
}

void solve75(){
    int s1 = -1, s2 = -1;
    for(int a = 0; a < N; a++){
        if(str[a] == '7'){
            s1 = a;
        }
        if(str[a] == '5'){
            s2 = a;
        }
    }

    if(s1 != -1 && s2 != -1){
        solve(s1, s2);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str;

    N = str.size();

    for(int a = 0; a < N; a++){
        if(str[a] == '0'){
            zeros |= 1 << a;
        }
    }

    solve00();
    solve25();
    solve50();
    solve75();

    if(ans == 1e9){
        cout << -1;
    } else {
        cout << ans;
    }
}
