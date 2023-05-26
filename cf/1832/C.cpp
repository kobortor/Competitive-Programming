#include<bits/stdc++.h>

// Created by kobortor On 10:54:40 on 26-05-2023

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec;
        while (n--) {
            int z;
            cin >> z;

            while (vec.size() >= 2) {
                int x = vec[vec.size() - 2];
                int y = vec[vec.size() - 1];
                if (x <= y && y <= z) {
                    vec.pop_back();
                } else if (x >= y && y >= z) {
                    vec.pop_back();
                } else {
                    break;
                }
            }

            if (!vec.empty() && vec.back() == z) {
                vec.pop_back();
            }

            vec.push_back(z);
        }
        cout << vec.size() << "\n";
    }
}
