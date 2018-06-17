#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
bool check[10];
int seq[10];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 0; a < N; a++){
        cin >> seq[a];
    }

    for(int a = 0; a < M; a++){
        int x;
        cin >> x;
        check[x] = true;
    }

    for(int a = 0; a < N; a++){
        if(check[seq[a]]){
            cout << seq[a] << " ";
        }
    }
}
