#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

ll N, Q, A, B, S;

double area[MAXN];
vector<pll> lines, tmpl;

double get_inter(ll X0, ll X1, ll Y1){
    return X1 + (double)(X0 - X1) * (Y1 - S) / Y1;
}

double get_wid(double l, double r){
    if(r < A || l > B){
        return 0;
    }

    return min(r, (double)B) - max(l, (double)A);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> S >> A >> B;

    cin >> N;
    for(int a = 0; a < N; a++){
        int l, r;
        cin >> l >> r;
        tmpl.push_back({l, r});
    }
    tmpl.push_back({1e18, 1e18});

    sort(allof(tmpl));

    lines.push_back({-2e9, -2e9}); //padding
    for(ll a = 1, lbnd = tmpl[0].first, rbnd = tmpl[0].second; a < (int)tmpl.size(); a++){
        if(tmpl[a].first > rbnd){
            lines.push_back({lbnd, rbnd});
            lbnd = tmpl[a].first;
        }
        rbnd = max(rbnd, tmpl[a].second);
    }
    lines.push_back({+2e9, +2e9}); //padding

    for(int a = 1; a < (int)lines.size(); a++){
        area[a] = area[a - 1] + (lines[a].second - lines[a].first);
    }

    cin >> Q;
    while(Q--){
        ll x, y;
        cin >> x >> y;

        int lo = 1, hi = lines.size() - 2;
        int lbnd, rbnd;

        while(lo <= hi){
            int mid = (lo + hi) / 2;
            double xpos = get_inter(lines[mid].first, x, y);
            if(xpos > A){
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        lbnd = lo;

        lo = 1, hi = lines.size() - 2;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            double xpos = get_inter(lines[mid].second, x, y);
            if(xpos < B){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        rbnd = hi;
        
        if(lbnd == 0){
            lbnd = 1;
        }
        if(rbnd == (int)lines.size() - 1){
            rbnd = lines.size() - 2;
        }

        double ans = lbnd <= rbnd ? ((double)(y - S) / y) * (area[rbnd] - area[lbnd - 1]) : 0;

        if(lbnd != 1){
            ans += get_wid(get_inter(lines[lbnd - 1].first, x, y), get_inter(lines[lbnd - 1].second, x, y));
        }
        
        if(rbnd + 1 != lbnd - 1 && rbnd != (int)lines.size() - 1){
            ans += get_wid(get_inter(lines[rbnd + 1].first, x, y), get_inter(lines[rbnd + 1].second, x, y));
        }

        cout << fixed << setprecision(7) << ans << endl;
    }
}
