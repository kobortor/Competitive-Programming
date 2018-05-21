#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N, M;
string str[MAXN];
int sum[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        cin >> str[a];
        for(int b = 0; b < M; b++){
            if(str[a][b] == '1'){
                sum[b]++;
            }
        }
    }
    for(int a = 0; a < N; a++){
        bool all_good = true;
        for(int b = 0; b < M; b++){
            if(str[a][b] == '1'){
                all_good &= (sum[b] >= 2);
            }
        }
        if(all_good){
            cout << "YES";
            return 0;
        }
    }   
    cout << "NO";
}
