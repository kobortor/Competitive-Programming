#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

pii loc[MAXN];
int N;

int gcd(int a, int b){
    if(!a) return b;
    if(!b) return a;

    while(a % b){
        a %= b;
        swap(a, b);
    }
    return b;
}

map<pii, int> lines;

pii get_slope(pii p){
    int g = gcd(p.first, p.second);
    p.first /= g;
    p.second /= g;
    if(p.first < 0) {
        p.first *= -1;
        p.second *= -1;
    }
    return p;
}

void make_lines(int id){
    lines.clear();
    for(int a = 0; a < N; a++){
        if(a == id) continue;

        int dx = loc[a].first - loc[id].first;
        int dy = loc[a].second - loc[id].second;
        lines[get_slope(pii(dx, dy))]++;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    if(N <= 4) {
        cout << "YES";
        return 0;
    }
    for(int a = 0; a < N; a++){
        cin >> loc[a].first;
        cin >> loc[a].second;
    }

    bool good = false;
    for(int a = 0; a < 3 && !good; a++){
        make_lines(a);
        for(auto au : lines){
            if(au.second >= 2){
                good = true;
                pii orig = loc[a];
                for(int b = 0; b < N; b++){
                    int dx = loc[b].first - orig.first;
                    int dy = loc[b].second - orig.second;

                    if(dx == 0 && dy == 0){
                        swap(loc[N-1], loc[b]);
                        N--;
                        b--;
                        continue;
                    }
                    pii slope = get_slope(pii(dx, dy));
                    if(slope == au.first){
                        swap(loc[N-1], loc[b]);
                        N--;
                        b--;
                        continue;                       
                    }
                }
                break;
            }
        }
    }
    if(!good){
        cout << "NO";
        return 0;
    } else if (N == 0){
        cout << "YES";
        return 0;
    }

    make_lines(0);
    if((int)lines.size() <= 1){
        cout << "YES";
    } else {
        cout << "NO";
    }
}
