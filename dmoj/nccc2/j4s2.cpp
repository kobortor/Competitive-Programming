#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii rect[3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int area = 0;
    for(int a = 0; a < 3; a++){
        cin >> rect[a].first;
        cin >> rect[a].second;
        if(rect[a].first < rect[a].second){
            swap(rect[a].first, rect[a].second);
        }
        area += rect[a].first * rect[a].second;
    }
    int sqlen = sqrt(area);
    if(sqlen * sqlen == area){
        //good, we have a chance
        for(int a = 0; a < 3; a++){
            if(rect[a].first > sqlen){
                cout << "NO";
                return 0;
            }
        }
        sort(rect, rect + 3);
        reverse(rect, rect + 3);

        int len2 = sqlen - rect[0].second;
        if((rect[1].first == len2 || rect[1].second == len2) && (rect[2].first == len2 || rect[2].second == len2)) {
            cout << "YES";
        } else if ((rect[1].first == len2 || rect[1].second == len2) && (rect[2].first == len2 || rect[2].second == len2)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
}
