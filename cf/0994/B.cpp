#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, K;

struct knight {
    int p, c, id;
    bool operator<(const knight &k) const {
        return p < k.p;
    }
} knights[MAXN];

ll out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    for(int a = 0; a < N; a++){
        cin >> knights[a].p;
        knights[a].id = a;
    }

    for(int a = 0; a < N; a++){
        cin >> knights[a].c;
    }

    sort(knights, knights + N);

    ll sum = 0;
    vector<int> others;

    for(int a = 0; a < N; a++){
        out[knights[a].id] = knights[a].c + sum;

        sum += knights[a].c;
        others.push_back(knights[a].c);

        if((int)others.size() > K){
            auto iter = min_element(allof(others));
            sum -= *iter;
            others.erase(iter);
        }
    }

    for(int a = 0; a < N; a++){
        cout << out[a] << " ";
    }
}
