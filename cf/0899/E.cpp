#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

struct segment {
    int col, l, r, len;
    segment(int c, int _l, int _r, int _len){
        col = c;
        l = _l;
        r = _r;
        len = _len;
    }
    bool operator<(const segment &seg) const {
        return l < seg.l;
    }
};

int color[MAXN];
set<pii> lengths;
set<segment> segments;

int main() {
    int N;
    cin >> N;

    color[0] = -1;
    color[N + 1] = 0x3f3f3f3f;

    for(int a = 1; a <= N; a++){
        cin >> color[a];
    }

    segments.insert({-1, 0, 0, 0});
    segments.insert({0x3f3f3f3f, N + 1, N + 1, 0});

    for(int a = 1; a <= N;){
        int idx = a;
        while(idx + 1 <= N && color[idx + 1] == color[a]){
            idx++;
        }

        lengths.insert({idx - a + 1, -a});
        segments.insert({color[a], a, idx, idx - a + 1});

        a = idx + 1;
    }

    int ans = 0;
    while(!lengths.empty()){
        ans++;
        pii p = *prev(lengths.end());
        lengths.erase(p);

        auto iter = segments.lower_bound({0, -p.second, 0, 0});
        if(prev(iter)->col == next(iter)->col){
            int new_len = prev(iter)->len + next(iter)->len;

            segment ins_seg = {prev(iter)->col, prev(iter)->l, next(iter)->r, new_len};
            pii ins_pii = {new_len, -prev(iter)->l};

            lengths.erase({prev(iter)->len, -prev(iter)->l});
            lengths.erase({next(iter)->len, -next(iter)->l});

            lengths.insert(ins_pii);

            segments.erase(prev(iter));
            segments.erase(next(iter));

            segments.insert(ins_seg);
        }
        segments.erase(iter);
    }
    cout << ans << "\n";
}