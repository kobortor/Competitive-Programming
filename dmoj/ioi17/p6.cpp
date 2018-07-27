#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;
int id[MAXN];
int dist[MAXN];
int best[MAXN];

vector<int> pq[2];

long long minimum_walk(vector<int> p, int s){
    if(is_sorted(allof(p))){
        return 0;
    }

    memset(id, -1, sizeof id);

    int n = p.size();
    ll walk = 0;
    vector<pii> tmp;
    for(int a = 0; a < n; a++){
        dist[a] = INT_MAX;
        best[a] = INT_MAX;
        if(id[a] != -1 || p[a] == a){
            continue;
        }

        ll added = 0;
        int lft = MAXN, rht = -1;
        int cur = a;

        do{
            id[cur] = tmp.size();
            lft = min(lft, cur);
            rht = max(rht, cur);

            added += abs(cur - p[cur]);
            cur = p[cur];
        }while(cur != a);

        do{
            cur = p[cur];
        }while(cur != a);

        tmp.push_back({lft, rht});
        walk += added;
    }

    tmp.push_back({INT_MAX, n});

    vector<pii> segments;
    for(int a = 1, front = tmp[0].first, back = tmp[0].second; a < (int)tmp.size(); a++){
        if(tmp[a].first > back){
            segments.push_back({front, back});
            front = tmp[a].first;
        }

        back = max(back, tmp[a].second);
    }

    tmp.pop_back();

    ll gaps = 0;
    for(int a = 1; a < (int)segments.size(); a++){
        gaps += 2 * (segments[a].first - segments[a - 1].second);
    }

    int init = 0;
    if(segments[0].first >= s){
        init = 2 * (segments[0].first - s);
    } else if (segments.back().second <= s){
        init = 2 * (s - segments.back().second);
    } else {
        pii cover = {-1, -1};
        for(int a = 0; a < (int)segments.size(); a++){
            if(segments[a].first <= s && s <= segments[a].second){
                cover = segments[a];
                break;
            }
        }

        int curdist = 0;
        pq[0].push_back(s);
        dist[s] = 0;

        set<int> unseen;
        for(int a = 0; a < n; a++){
            unseen.insert(a);
        }

        while(!pq[0].empty() || !pq[1].empty()){
            if(pq[0].empty()){
                curdist++;
                pq[0].swap(pq[1]);
            }

            int pos = pq[0].back();
            pq[0].pop_back();
            unseen.erase(pos);

            if(pos != 0 && dist[pos - 1] > curdist + 1){
                dist[pos - 1] = curdist + 1;
                pq[1].push_back(pos - 1);
            }
            if(pos != n - 1 && dist[pos + 1] > curdist + 1){
                dist[pos + 1] = curdist + 1;
                pq[1].push_back(pos + 1);
            }

            int minp = min(pos, p[pos]);
            int maxp = max(pos, p[pos]);

            auto iter = unseen.lower_bound(minp);
            while(iter != unseen.end() && *iter <= maxp){
                if(dist[*iter] > curdist){
                    dist[*iter] = curdist;
                    pq[0].push_back(*iter);
                }

                unseen.erase(iter++);
            }
        }

        for(int a = 0; a < n; a++){
            if(a != p[a]){
                best[id[a]] = min(best[id[a]], dist[a]);
            }
        }
        
        for(int a = 0; a < (int)tmp.size(); a++){
            if(cover.first <= tmp[a].first && tmp[a].second <= cover.second){
                init = max(init, best[a] * 2);
            }
        }
    }

    return walk + gaps + init;
}
