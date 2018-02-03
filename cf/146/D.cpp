#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e6 + 6;

int n4, n7, n47, n74;

int cnt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n4 >> n7 >> n47 >> n74;
    if(abs(n47 - n74) > 1){
        cout << -1;
        return 0;
    }
   
    if(n47 == n74 && n4 > n47){
        for(int a = 0; a < n47; a++){
            cnt[2 * a] = 1;
            cnt[2 * a + 1] = 1;

            n4--;
            n7--;
        }
        cnt[2 * n47] = 1;
        n4--;

        while(n4 > 0){
            cnt[0]++;
            n4--;
        }
        while(n7 > 0){
            cnt[2 * n47 - 1]++;
            n7--;
        }
    } else if (n47 == n74 && n4 <= n47){
        cnt[1] = 1;
        n7--;

        for(int a = 1; a <= n47; a++){
            cnt[2 * a] = 1;
            cnt[2 * a + 1] = 1;

            n4--;
            n7--;
        }

        while(n4 > 0){
            cnt[2]++;
            n4--;
        }
        while(n7 > 0){
            cnt[2 * n47 + 1]++;
            n7--;
        }
    } else if (n47 == n74 + 1){
        //start 4
        for(int a = 0; a < n47; a++){
            cnt[2 * a] = 1;
            cnt[2 * a + 1] = 1;

            n4--;
            n7--;
        }

        while(n4 > 0){
            cnt[0]++;
            n4--;
        }
        while(n7 > 0){
            cnt[2 * n47 - 1]++;
            n7--;
        }
    } else {
        //start 7
        cnt[1] = 1;
        n7--;

        for(int a = 1; a < n74; a++){
            cnt[2 * a] = 1;
            cnt[2 * a + 1] = 1;

            n4--;
            n7--;
        }
        cnt[2 * n74] = 1;
        n4--;

        while(n4 > 0){
            cnt[2]++;
            n4--;
        }
        while(n7 > 0){
            cnt[2 * n74 - 1]++;
            n7--;
        }
    }

    if(n4 < 0 || n7 < 0){
        cout << -1;
        return 0;
    }

    for(int a = 0; a < MAXN; a++){
        while(cnt[a] > 0){
            cout << ((a & 1) ? 7 : 4);
            cnt[a]--;
        }
    }
}
