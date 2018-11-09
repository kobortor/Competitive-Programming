#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
pii point[MAXN];

bool good(double rad){
    vector<pair<double, bool>> sweep;
    for(int a = 0; a < N; a++){
        if(point[a].second > 2 * rad){
            return false;
        } else {
            double dy = rad - point[a].second;
            double dx = sqrt(rad - dy) * sqrt(rad + dy); //same as sqrt(rad * rad - dy * dy), but gives more precision
            sweep.push_back({point[a].first - dx, true});
            sweep.push_back({point[a].first + dx, false});
        }
    }

    sort(allof(sweep));

    int cnt = 0;
    for(pair<double, bool> p : sweep){
        if(p.second){
            cnt++;
            if(cnt == N){
                return true;
            }
        } else {
            cnt--;
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> point[a].first;
        cin >> point[a].second;
    }

    bool has_pos = false, has_neg = false;
    for(int a = 0; a < N; a++){
        if(point[a].second > 0){
            has_pos  = true;
        } else {
            has_neg  = true;
        }
    }

    if(has_pos && has_neg){
        cout << -1 << endl;
        return 0;
    } else {
        for(int a = 0; a < N; a++){
            point[a].second = abs(point[a].second);
        }
        double lo = 0, hi = 1e15;
        for(int a = 0; a < 80; a++){
            double mid = (lo + hi) / 2;
            if(good(mid)){
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << fixed << setprecision(15) << lo << endl;
    }
}
