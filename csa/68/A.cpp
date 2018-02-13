#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N;
string str[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> str[a];
    }
    for(int a = 0; a < N; a++){
        bool good = false;
        for(int b = 0; b < N; b++){
            for(int c = 0; c < N; c++){
                if(b != c && str[b] + str[c] == str[a]){
                    good = true;
                    break;
                }
            }
        }
        if(good){
            cout << a + 1 << " ";
        }
    }
}
