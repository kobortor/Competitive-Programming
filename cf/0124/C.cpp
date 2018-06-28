#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int freq[26];

bool sieve[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;

    int N = str.size();

    for(char c : str){
        freq[c - 'a']++;
    }

    vector<int> spec;
    spec.push_back(1);

    for(int a = 2; a <= N; a++){
        if(!sieve[a]){
            if(2 * a > N){
                spec.push_back(a);
            }

            for(int b = 2 * a; b <= N; b += a){
                sieve[b] = true;
            }
        }
    }

    int nonspec = N - spec.size();

    int maxch = max_element(freq, freq + 26) - freq;

    if(freq[maxch] >= nonspec){
        string ans(N, '-');
        cout << "YES\n";
        for(int a = 1; a <= N; a++){
            if(!sieve[a] && (a == 1 || 2 * a > N)){
                //ignore
            } else {
                ans[a - 1] = char(maxch + 'a');
                freq[maxch]--;
            }
        }

        int idx = 0;
        for(char &c : ans){
            if(c == '-'){
                while(!freq[idx]){
                    idx++;
                }
                freq[idx]--;
                c = char(idx + 'a');
            }
        }
        cout << ans << "\n";
    } else {
        cout << "NO\n";
    }
}
