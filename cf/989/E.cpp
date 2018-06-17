#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;

int gcd(int x, int y){
    x = abs(x);
    y = abs(y);
    if(y == 0){
        return x;
    }
    if(x == 0){
        return y;
    }

    while(x % y){
        x %= y;
        swap(x, y);
    }
    return y;
}

int N;

vector<vector<int>> tmplines;
pii points[MAXN];

struct vec{
    double data[MAXN];

    vec(){
        fill(data, data + MAXN, 0.0);
    }
};

struct mat {
    double data[MAXN][MAXN];
    mat(){
        for(int a = 0; a < MAXN; a++){
            fill(data[a], data[a] + MAXN, 0.0);
        }
    }

    mat operator*(const mat &m) const {
        mat ret;
        for(int a = 0; a < MAXN; a++){
            for(int b = 0; b < MAXN; b++){
                for(int c = 0; c < MAXN; c++){
                    ret.data[a][c] += data[a][b] * m.data[b][c];
                }
            }
        }
        return ret;
    }

    vec operator*(const vec &v) const {
        vec ret;
        for(int a = 0; a < MAXN; a++){
            for(int b = 0; b < MAXN; b++){
                ret.data[b] += v.data[a] * data[a][b];
            }
        }
        return ret;
    }
};

mat precalc[20];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> points[a].first;
        cin >> points[a].second;
    }

    vector<vector<int>> lines;

    for(int a = 1; a <= N; a++){
        map<pii, vector<int>> tmplines;
        for(int b = 1; b <= N; b++){
            if(a == b) continue;

            int dx = points[b].first - points[a].first;
            int dy = points[b].second - points[a].second;

            if(dx == 0){
                tmplines[pii(0, 1)].push_back(b);
            } else {
                if(dx < 0){
                    dx *= -1;
                    dy *= -1;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                tmplines[pii(dx, dy)].push_back(b);
            }
        }

        for(auto &au : tmplines){
            au.second.push_back(a);
            for(int i : au.second){
                precalc[0].data[i][a] += 1.0 / tmplines.size() / au.second.size();
            }
            
            if(au.second[0] > a){
                lines.push_back(au.second);
            }
        }
    }

    for(int a = 1; a < 20; a++){
        precalc[a] = precalc[a - 1] * precalc[a - 1];
    }

    int Q;
    cin >> Q;
    while(Q--){
        int t, m;
        cin >> t >> m;
        m--;

        vec v;
        v.data[t] = 1.0;

        for(int a = 0; a < 20; a++){
            if(m & (1 << a)){
                v = precalc[a] * v;
            }
        }

        double ans = 0;
        for(const vector<int> &vv : lines){
            double tmp = 0;
            for(int i : vv){
                tmp += v.data[i];
            }

            ans = max(ans, tmp / vv.size());
        }

        cout << fixed << setprecision(15) << ans << "\n";
    }
}
