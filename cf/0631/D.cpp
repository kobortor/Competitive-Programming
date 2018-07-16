#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, M;

pair<char, ll> orig[MAXN];
pair<char, ll> tofind[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        string str;
        cin >> str;
        int idx = str.find('-');
        char ch = str[idx + 1];
        int cnt = stoi(str.substr(0, idx));

        if(ch == orig[a - 1].first){
            orig[a - 1].second += cnt;
            a--;
            N--;
        } else {
            orig[a] = {ch, cnt};
        }
    }

    for(int a = 1; a <= M; a++){
        string str;
        cin >> str;
        int idx = str.find('-');
        char ch = str[idx + 1];
        int cnt = stoi(str.substr(0, idx));

        if(ch == tofind[a - 1].first){
            tofind[a - 1].second += cnt;
            a--;
            M--;
        } else {
            tofind[a] = {ch, cnt};
        }
    }

    ll ans = 0;

    if(M == 1){
        char ch = tofind[1].first;
        ll cnt = tofind[1].second;

        for(int a = 1; a <= N; a++){
            if(orig[a].first == ch && orig[a].second >= cnt){
                ans += orig[a].second - cnt + 1;
            }
        }
    } else if (M == 2) {
        char ch1 = tofind[1].first;
        ll cnt1 = tofind[1].second;

        char ch2 = tofind[2].first;
        ll cnt2 = tofind[2].second;

        for(int a = 1; a + 1 <= N; a++){
            if(orig[a].first == ch1 && orig[a + 1].first == ch2 && orig[a].second >= cnt1 && orig[a + 1].second >= cnt2){
                ans++;
            }
        }
    } else {
        vector<int> kmp(M - 2);
        for(int a = 1, b = 0; a <= M - 3;){
            if(tofind[a + 2] == tofind[b + 2]){
                b++;
                kmp[a] = b;
                a++;
            } else if(b == 0){
                kmp[a] = 0;
                a++;
            } else {
                b = kmp[b - 1];
            }
        }

        for(int a = 0, b = 0; a <= N - 1;){
            if(orig[a + 1] == tofind[b + 2]){
                b++;

                if(b == M - 2){
                    if( orig[a - M + 3].first == tofind[1].first && orig[a - M + 3].second >= tofind[1].second &&
                        orig[a + 2].first == tofind[M].first && orig[a + 2].second >= tofind[M].second){
                        ans++;
                    }

                    b = kmp[b - 1];
                }
                a++;
            } else if (b != 0) {
                b = kmp[b - 1];
            } else {
                a++;
            }
        }
    }

    cout << ans;
}
