#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define until(x) while(!(x))

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        string s;
        cin >> s;

        cout << "Case #" << i << ": ";

        if (s.back() == 'E') {
            if (s[0] == 'S') {
                cout << string(N - 1, 'E') << string(N - 1, 'S') << endl;
            } else {
                int idx = 0;
                int down = 0;
                until (s[idx] == 'S' && s[idx + 1] == 'S') {
                    if (s[idx] == 'S') {
                        down++;
                    }
                    idx++;
                }

                cout << string(down + 1, 'S') << string(N - 1, 'E') << string(N - 1 - (down + 1), 'S') << endl;
            }
        } else {
            if (s[0] == 'E') {
                cout << string(N - 1, 'S') << string(N - 1, 'E') << endl;
            } else {
                int idx = 0;
                int rht = 0;
                until (s[idx] == 'E' && s[idx + 1] == 'E') {
                    if (s[idx] == 'E') {
                        rht++;
                    }
                    idx++;
                }

                cout << string(rht + 1, 'E') << string(N - 1, 'S') << string(N - 1 - (rht + 1), 'E') << endl;
            }
        }
    }
}
