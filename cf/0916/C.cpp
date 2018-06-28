#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool is_prime(int x){
    if(x <= 1){
        return false;
    }

    for(int a = 2; a * a <= x; a++){
        if(x % a == 0){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<pair<pii, int>> edges;

    for(int a = 1; a + 1 < N; a++){
        edges.push_back({{a, a + 1}, 1});
    }

    int last_edge = 1;
    while(!is_prime(N + last_edge - 2)){
        last_edge++;
    }

    edges.push_back({{N - 1, N}, last_edge});

    for(int a = 1; a <= N && (int)edges.size() < M; a++){
        for(int b = a + 2; b <= N && (int)edges.size() < M; b++){
            edges.push_back({{a, b}, 1000000000});
        }
    }

    cout << N - 2 + last_edge << " " << N - 2 + last_edge << "\n";
    for(pair<pii, int> p : edges){
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
    }
}
