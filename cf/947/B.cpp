#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll snow[MAXN];
ll temp[MAXN];
priority_queue<ll, vector<ll>, greater<ll>> pq;
int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> snow[a];
    }
    for(int a = 1; a <= N; a++){
        cin >> temp[a];
        temp[a] += temp[a - 1];
    }

    for(int a = 1; a <= N; a++){
        pq.push(snow[a] + temp[a - 1]);
        ll melted = 0;
        while(!pq.empty() && pq.top() < temp[a]){
            melted += pq.top() - temp[a - 1];
            pq.pop();
        }
        melted += pq.size() * (temp[a] - temp[a - 1]);
        cout << melted << " ";
    }
}
