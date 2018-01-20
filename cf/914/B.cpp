#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int freq[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        freq[x]++;
    }
    for(int a = 0; a < MAXN; a++){
        if(freq[a] % 2 == 1){
            cout << "Conan";
            return 0;
        }
    }
    cout << "Agasa";
}
