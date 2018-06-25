#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

pii add(pii p1, pii p2){
    return pii(p1.first + p2.first, p1.second + p2.second);
}

ll dist(pii p){
    return (ll)p.first * p.first + (ll)p.second * p.second;
}

pii operator+(const pii &p1, const pii &p2){
    return pii(p1.first + p2.first, p1.second + p2.second);
}

pii operator-(const pii &p1, const pii &p2){
    return pii(p1.first - p2.first, p1.second - p2.second);
}

pii operator-(const pii &p){
    return pii(-p.first, -p.second);
}

int N;

pii below[2 * MAXN];
int inv[2 * MAXN];
bool out[MAXN];

void dfs(int pos, bool has_inv){
    has_inv ^= inv[pos];
    if(pos <= N){
        out[pos] = has_inv;
        return;
    }

    dfs(below[pos].first, has_inv);
    dfs(below[pos].second, has_inv);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    srand(time(0));

    cin >> N;

    pii vec1, vec2;
    int id1 = 1, id2 = 2;

    cin >> vec1.first >> vec1.second >> vec2.first >> vec2.second;

    for(int a = 3; a <= N; a++){
        pii vec3;
        cin >> vec3.first >> vec3.second;
        int id3 = a;
        int new_id = a + N - 2;

        pii res11 = vec1 + vec2;
        pii res12 = vec1 - vec2;

        pii res21 = vec1 + vec3;
        pii res22 = vec1 - vec3;

        pii res31 = vec2 + vec3;
        pii res32 = vec2 - vec3;

        ll min_dist = 1e18;
        min_dist = min(min_dist, dist(res11));
        min_dist = min(min_dist, dist(res12));
        min_dist = min(min_dist, dist(res21));
        min_dist = min(min_dist, dist(res22));
        min_dist = min(min_dist, dist(res31));
        min_dist = min(min_dist, dist(res32));

        if(dist(res11) == min_dist){
            below[new_id] = pii(id1, id2);

            id1 = new_id;
            id2 = id3;
            vec1 = res11;
            vec2 = vec3;
        } else if (dist(res12) == min_dist){
            below[new_id] = pii(id1, id2);
            inv[id2] = true;

            id1 = new_id;
            id2 = id3;
            vec1 = res12;
            vec2 = vec3;
        } else if (dist(res21) == min_dist){
            below[new_id] = pii(id1, id3);

            id1 = new_id;
            vec1 = res21;
        } else if (dist(res22) == min_dist){
            below[new_id] = pii(id1, id3);
            inv[id3] = true;

            id1 = new_id;
            vec1 = res22;
        } else if (dist(res31) == min_dist){
            below[new_id] = pii(id2, id3);
            
            id2 = new_id;
            vec2 = res31;
        } else if (dist(res32) == min_dist){
            below[new_id] = pii(id2, id3);
            inv[id3] = true;
            
            id2 = new_id;
            vec2 = res32;
        } else {
            assert(false);
        }
    }

    dfs(id1, false);

    if(dist(vec1 - vec2) <= dist(vec1 + vec2)){
        inv[id2] = true;
    }

    dfs(id2, false);

    for(int a = 1; a <= N; a++){
        if(out[a]){
            cout << "-1 ";
        } else {
            cout << "1 ";
        }
    }
}
