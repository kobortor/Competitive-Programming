#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int gcd(int x, int y){
    while(x % y){
        x %= y;
        swap(x, y); }
    return y;
} 
vector<int> factors[MAXN];

int cnt[8];

int choose2(int x){
    return x * (x - 1) / 2;
}

int choose3(int x){
    return x * (x - 1) * (x - 2) / 6;
}

vector<array<int, 3>> goodmasks;

bool used[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int m0 = 0; m0 < 8; m0++){
        for(int m1 = m0; m1 < 8; m1++){
            for(int m2 = m1; m2 < 8; m2++){
                vector<int> perm = {1, 2, 4};
                do {
                    if((m0 & perm[0]) && (m1 & perm[1]) && (m2 & perm[2])){
                        goodmasks.push_back({m0, m1, m2});
                        break;
                    }
                } while (next_permutation(allof(perm)));
            }
        }
    }

    for(int a = 1; a < MAXN; a++){
        for(int b = 1; b * b <= a; b++){
            if(a % b == 0){
                factors[a].push_back(b);
                if(b * b != a){
                    factors[a].push_back(a / b);
                }
            }
        }
    }


    int T;
    cin >> T;
    while(T--){
        int A, B, C;
        cin >> A >> B >> C;

        vector<int> uniq;

        for(int i : factors[A]){
            if(!used[i]){
                used[i] = true;
                uniq.push_back(i);
            }
        }
        for(int i : factors[B]){
            if(!used[i]){
                used[i] = true;
                uniq.push_back(i);
            }
        }
        for(int i : factors[C]){
            if(!used[i]){
                used[i] = true;
                uniq.push_back(i);
            }
        }

        memset(cnt, 0, sizeof cnt);

        for(int i : uniq){
            used[i] = false;
            int mask = 0;
            if(A % i == 0){
                mask |= 1;
            }
            if(B % i == 0){
                mask |= 2;
            }
            if(C % i == 0){
                mask |= 4;
            }

            cnt[mask]++;
        }

        int ans = 0;

        for(const array<int, 3> &arr : goodmasks){
            int m0 = arr[0];
            int m1 = arr[1];
            int m2 = arr[2];

            if(m0 == m1 && m1 == m2){
                ans += cnt[m0];
                ans += choose2(cnt[m0]) * 2;
                ans += choose3(cnt[m0]);
            } else if (m0 == m1){
                ans += cnt[m0] * cnt[m2];
                ans += choose2(cnt[m0]) * cnt[m2];
            } else if (m0 == m2){
                ans += cnt[m0] * cnt[m1];
                ans += choose2(cnt[m0]) * cnt[m1];
            } else if (m1 == m2){
                ans += cnt[m2] * cnt[m0];
                ans += choose2(cnt[m2]) * cnt[m0];
            } else {
                ans += cnt[m0] * cnt[m1] * cnt[m2];
            }
        }
       
        cout << ans << "\n";
    }
}
