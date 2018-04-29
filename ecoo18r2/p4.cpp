#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int top_line;
vector<pii> points;

ll range(const map<int, int> &st){
    return (ll)prev(st.end())->first - (ll)st.begin()->first;
}

vector<int> sweep_pos;
unordered_map<int, vector<pii>> add, rem;
bool check(ll len){
    sweep_pos.clear();
    add.clear();
    rem.clear();

    for(const pii &p : points){
        if(p.second <= top_line + len){
            sweep_pos.push_back(p.first);
        }
    }
    sort(allof(sweep_pos));
    sweep_pos.erase(unique(allof(sweep_pos)), sweep_pos.end());

    for(const pii &p : points){
        if(p.second <= top_line + len){
            ll xpos = *lower_bound(allof(sweep_pos), p.first - len);
            add[xpos].push_back(p);

            rem[p.first].push_back(p);
        }
    }

    int bottom_line = INT_MIN;
    int left_line = INT_MAX;
    map<int, int> availX, availY;

    //case 1: initial block
    for(const pii &p : points){
        if(p.first > sweep_pos[0] + len || p.second > top_line + len){
            //outside the top box
            bottom_line = max(bottom_line, p.second);
            left_line = min(left_line, p.first);
        }
    }

    int new_lft = INT_MAX;
    int new_rht = INT_MIN;
    int new_top = INT_MAX;
    int new_bot = INT_MIN;

    for(const pii &p : points){
        if(p.first > sweep_pos[0] + len || p.second > top_line + len){
            if(p.first > left_line + len || bottom_line > p.second + len){
                new_lft = min(new_lft, p.first);
                new_rht = max(new_rht, p.first);

                new_top = min(new_top, p.second);
                new_bot = max(new_bot, p.second);
            }
        }
    }

    if(new_lft == INT_MAX || max(new_rht - new_lft, new_bot - new_top) <= len){
        return true;
    }

    //case 2: fixed bottom left block
    for(pii p : points){
        left_line = min(left_line, p.first);
    }

    new_lft = INT_MAX;
    new_rht = INT_MIN;
    new_top = INT_MAX;
    new_bot = INT_MIN;
    
    for(pii p : points){
        if(p.first > left_line + len || bottom_line > p.second + len){
            availX[p.first]++;
            availY[p.second]++;
        }
    }

    for(const int &x : sweep_pos){
        for(const pii &p : add[x]){
            if(p.first > left_line + len || bottom_line > p.second + len){
                //outside bottom left

                auto ix = availX.find(p.first);
                auto iy = availY.find(p.second);

                ix->second--;
                iy->second--;

                if(!ix->second){
                    availX.erase(ix);
                }
                if(!iy->second){
                    availY.erase(iy);
                }
            }
        }

        if(availX.empty()){
            return true;
        }

        int lft = min(new_lft, availX.begin()->first);
        int rht = max(new_rht, prev(availX.end())->first);
        int top = min(new_top, availY.begin()->first);
        int bot = max(new_bot, prev(availY.end())->first);

        if(max(bot - top, rht - lft) <= len){
            return true;
        }

        for(const pii &p : rem[x]){
            if(p.first > left_line + len || bottom_line > p.second + len){
                //outside bottom left

                new_lft = min(new_lft, p.first);
                new_rht = max(new_rht, p.first);

                new_top = min(new_top, p.second);
                new_bot = max(new_bot, p.second);
            }
        }
    }
    return false;
}

ll solve(){
    ll lo = 1, hi = 2e9;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void testcase(){
    top_line = INT_MAX;
    points.clear();
    cin >> N;

    for(int a = 1; a <= N; a++){
        pii p;
        cin >> p.first >> p.second;
        top_line = min(top_line, p.second);
        points.push_back(p);
    }
    ll ans = solve();
    for(pii &p : points){
        p.first *= -1;
    }
    ans = min(ans, solve());
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    const int MAX_CASE = 10;
    for(int a = 1; a <= MAX_CASE; a++){
        testcase();
    }
}
