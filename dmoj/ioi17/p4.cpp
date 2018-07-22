#include "prize.h"
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;

struct BIT {
    int data[MAXN];
    void update(int pos, int val){
        pos++;
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }

    int query(int pos){
        pos++;
        int ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
};
BIT ds[30];

vector<int> found;
int getid(int x){
    auto iter = find(allof(found), x);
    if(iter == found.end()){
        found.push_back(x);
        return found.size() - 1;
    }

    return iter - found.begin();
}

bool vis[MAXN];
vector<int> remain;

int find_best(int N){
    for(int a = 0; a < N; a++){
        remain.push_back(a);
    }

    while(true){
        int lo = 0, hi = remain.size() - 1;

        vector<pii> to_update;
        int prvcnt = -1;

        while(lo <= hi){
            int mid = (lo + hi) / 2;
            vector<int> res = ask(remain[mid]);
            vis[remain[mid]] = true;
            int tot = res[0] + res[1];
            int id = getid(tot);

            if(res[0] == 0 && res[1] == 0){
                return remain[mid];
            }
            for(int i = 0; i < (int)found.size(); i++){
                if(found[i] < tot){
                    res[0] -= ds[i].query(remain[mid]);
                }
            }
            to_update.push_back({id, remain[mid]});

            if(prvcnt == -1){
                prvcnt = tot;
            }

            if(prvcnt < tot){
                if(res[0] == 0){
                    break;
                } else {
                    hi = mid - 1;
                }
            } else {
                if(res[0] == 0){
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        for(pii p : to_update){
            ds[p.first].update(p.second, 1);
        }

        int removed = 0;
        for(int i = 0; i < (int)remain.size(); i++){
            if(vis[remain[i]]){
                removed++;
            } else {
                remain[i - removed] = remain[i];
            }
        }

        while(removed--){
            remain.pop_back();
        }
    }
}
