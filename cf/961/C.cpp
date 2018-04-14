#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cost1[4];
int cost2[4];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for(int i = 0; i < 4; i++){
        string str;
        for(int a = 0; a < N; a++){
            cin >> str;
            for(int b = 0; b < N; b++){
                if((a^b)%2 != str[b] - '0'){
                    cost1[i]++;
                } else {
                    cost2[i]++;
                }
            }
        }
    }

    int ans = 1e9;
    int tmp = cost1[0] + cost1[1] + cost1[2] + cost1[3];
    for(int a = 0; a < 4; a++){
        for(int b = a + 1; b < 4; b++) {
            ans = min(ans, tmp + cost2[a] + cost2[b] - cost1[a] - cost1[b]);
        }
    }
    cout << ans;
}
