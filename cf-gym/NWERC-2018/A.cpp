#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define int ll

struct item {
    int sum, cnt;
    double avg;
    int l, r;

    item (int s, int c, double a, int L, int R) {
        sum = s;
        cnt = c;
        avg = a;
        l = L;
        r = R;
    }
};

const int MN = 100005;

int n, x[MN], y[MN];
double ans = 0.0;

int32_t main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    x[n + 1] = y[n + 1] = (int) 1e9;
    vector<item> v;
    for (int i = 1; i <= n; i++) {
        int sum = x[i], cnt = 1, l = i;
        double avg = (double) sum / cnt;
        while (v.size() && v.back().avg > avg) {
            sum += v.back().sum;
            cnt += v.back().cnt;
            l = v.back().l;
            avg = (double) sum / cnt;
            v.pop_back();
        }
        v.push_back(item(sum, cnt, avg, l, i));
    }
    for (item p : v) {
        for (int i = p.l; i <= p.r; i++) {
            double diff = p.avg - x[i];
            ans += diff * diff;
        }
    }

    v.clear();
    for (int i = 1; i <= n; i++) {
        int sum = y[i], cnt = 1, l = i;
        double avg = (double) sum / cnt;
        while (v.size() && v.back().avg > avg) {
            sum += v.back().sum;
            cnt += v.back().cnt;
            l = v.back().l;
            avg = (double) sum / cnt;
            v.pop_back();
        }
        v.push_back(item(sum, cnt, avg, l, i));
    }
    for (item p : v) {
        for (int i = p.l; i <= p.r; i++) {
            //printf("%.3f\n", p.avg);
            double diff = p.avg - y[i];
            ans += diff * diff;
        }
    }

    printf("%.8f\n", ans);
}
