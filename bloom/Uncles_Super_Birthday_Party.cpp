#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pair<pii, pii>> lines;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    pii prv;
    cin >> prv.first >> prv.second;

    while(--N){
        pii nxt;
        cin >> nxt.first >> nxt.second;
        lines.push_back({min(prv, nxt), max(prv, nxt)});

        prv = nxt;
    }

    for(int a = 0; a < (int)lines.size(); a++){
        if(lines[a].first == lines[a].second){
            swap(lines[a], lines.back());
            lines.pop_back();
            a--;
        }
    }

    const double eps = 0.000001;

    int ans = 0;
    for(int x = -5; x <= 55; x++){
        for(int y = -5; y <= 55; y++){
            int above = 0;
            for(pair<pii, pii> l : lines){
                if(l.second.first - eps <= x || x + 1 <= l.first.first + eps){
                    continue;
                }

                double m = (double)(l.second.second - l.first.second) / (l.second.first - l.first.first);
                double b = l.first.second - l.first.first * m;

                double y1 = m * x + b;
                double y2 = m * (x + 1) + b;

                if(y1 + eps >= y + 1 && y2 + eps >= y + 1){
                    above++;
                } else if (y1 - eps <= y && y2 - eps <= y){
                    //ok
                } else {
                    //broken
                    above = 0;
                    break;
                }
            }

            if(above % 2 == 1){
                ans++;
            }
        }
    }
    cout << ans;
}
