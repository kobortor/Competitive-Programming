#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<string> words;
vector<vector<string>> source;
vector<vector<string>> query;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    while (N--) {
        int k;
        cin >> k;
        source.emplace_back();
        while (k--) {
            string str;
            cin >> str;
            words.push_back(str);
            source.back().push_back(str);
        }
    }

    int M;
    cin >> M;
    while (M--) {
        int k;
        cin >> k;
        query.emplace_back();
        while (k--) {
            string str;
            cin >> str;
            words.push_back(str);
            query.back().push_back(str);
        }
    }

    sort(allof(words));
    words.erase(unique(allof(words)), words.end());

    map<vector<int>, int> cnt;
    for (vector<string> v : source) {
        vector<int> vv;
        for (string s : v) {
            int idx = lower_bound(allof(words), s) - words.begin();
            vv.push_back(idx);
        }
        sort(allof(vv));

        for (int a = 0; a < (1 << vv.size()); a++) {
            vector<int> tmp;
            for (int b = 0; b < (int)vv.size(); b++) {
                if (a & (1 << b)) {
                    tmp.push_back(vv[b]);
                }
            }
            cnt[tmp]++;
        }
    }

    for (vector<string> v : query) {
        vector<int> vv;
        for (string s : v) {
            int idx = lower_bound(allof(words), s) - words.begin();
            vv.push_back(idx);
        }
        sort(allof(vv));

        cout << cnt[vv] << "\n";
    }
}
