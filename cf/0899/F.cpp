#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 5e5 + 5;

set<int> chars[256];

int N, M;
string str;

struct BIT {
    int data[MAXN];
    void update(int pos, int val){
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos){
        int ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
    int lower_bound(int sum){
        int idx = 0;
        for(int a = 18; a >= 0; a--){
            int tidx = idx | (1 << a);
            if(tidx >= MAXN){
                return -1;
            }
            if(data[tidx] < sum){
                idx = tidx;
                sum -= data[tidx];
            }
        }
        return idx + 1;
    }
}ds;

void erase_range(int l, int r, int c){
    auto iter = chars[c].lower_bound(l);
    while(iter != chars[c].end() && *iter <= r){
        auto tmp = iter;
        ds.update(*tmp, -1);
        iter++;
        chars[c].erase(tmp);
    }
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;
    string str;
    cin >> str;
    for(int a = 0; a < (int)str.size(); a++){
        chars[(int)str[a]].insert(a + 1);
        ds.update(a + 1, 1);
    }
    ds.update(str.size() + 1, 1);

    while(M--){
        int l, r;
        char c;
        cin >> l >> r >> c;

        int lbnd = ds.lower_bound(l);
        int rbnd = ds.lower_bound(r + 1) - 1;
        erase_range(lbnd, rbnd, c);
    }

    vector<pii> vec;
    for(int a = 0; a < 256; a++){
        for(int i : chars[a]){
            vec.push_back({i, a});
        }
    }
    sort(vec.begin(), vec.end());
    for(pii p : vec){
        cout << char(p.second);
    }
    cout << "\n";
}