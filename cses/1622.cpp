#include<bits/stdc++.h>

// Created by kobortor On 18:40:50 on 27-01-2024

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<string> ans;
string avail;
string cur;
int cnt[26];
void gen() {
    if (cur.size() == avail.size()) {
        ans.push_back(cur);
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            cnt[i]--;
            cur += char('a' + i);
            gen();
            cur.pop_back();
            cnt[i]++;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> avail;
    for (char c : avail) {
        cnt[c - 'a']++;
    }

    gen();
    cout << ans.size() << "\n";
    for (string s : ans) {
        cout << s << "\n";
    }
}
