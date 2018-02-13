#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M, K;

int gcd(int a, int b){
    if(!a) return b;
    if(!b) return a;

    while(a % b){
        a %= b;
        swap(a, b);
    }

    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;

    vector<pii> points;
    for(int a = 0; a <= N; a++){
        for(int b = 0; b <= M; b++){
            points.push_back({a, b});
        }
    }

    int ans = 0;
    for(int a = 0; a < (int)points.size(); a++){
        for(int b = a + 1; b < (int)points.size(); b++){
            int dx = abs(points[a].first - points[b].first);
            int dy = abs(points[a].second - points[b].second);

            if(gcd(dx, dy) + 1 == K){
                ans++;
            }
        }
    }
    cout << ans;
}
