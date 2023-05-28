#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, br, bc;
vector<vector<int>> out;

void rec(int top, int lft, int bot, int rit, int br, int bc) {
    if (bot == top) return;
    int midr = (top + bot) / 2;
    int midc = (lft + rit) / 2;
    if (br <= midr) {
        if (bc <= midc) {
            out.push_back({midr + 1, midc + 1, -1, -1});
            rec(top, lft, midr, midc, br, bc);
            rec(top, midc + 1, midr, rit, midr, midc + 1);
            rec(midr + 1, lft, bot, midc, midr + 1, midc);
            rec(midr + 1, midc + 1, bot, rit, midr + 1, midc + 1);
        } else {
            out.push_back({midr + 1, midc, -1, 1});
            rec(top, lft, midr, midc, midr, midc);
            rec(top, midc + 1, midr, rit, br, bc);
            rec(midr + 1, lft, bot, midc, midr + 1, midc);
            rec(midr + 1, midc + 1, bot, rit, midr + 1, midc + 1);
        }
    } else {
        if (bc <= midc) {
            out.push_back({midr, midc + 1, 1, -1});
            rec(top, lft, midr, midc, midr, midc);
            rec(top, midc + 1, midr, rit, midr, midc + 1);
            rec(midr + 1, lft, bot, midc, br, bc);
            rec(midr + 1, midc + 1, bot, rit, midr + 1, midc + 1);
        } else {
            out.push_back({midr, midc, 1, 1});
            rec(top, lft, midr, midc, midr, midc);
            rec(top, midc + 1, midr, rit, midr, midc + 1);
            rec(midr + 1, lft, bot, midc, midr + 1, midc);
            rec(midr + 1, midc + 1, bot, rit, br, bc);
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> br >> bc;
    int sz = n;
    int mid = (n + 1) / 2;
    if (__builtin_popcount(sz) != 1) {
        if (br <= mid) {
            if (bc <= mid) {
                int r = n, c = n, len = n - 1;
                while (__builtin_popcount(sz) != 1) {
                    sz--;
                    out.push_back({r, c, -len, -len});
                    r--, c--, len--;
                }
                rec(1, 1, r, c, br, bc);
            } else {
                int r = n, c = 1, len = n - 1;
                while (__builtin_popcount(sz) != 1) {
                    sz--;
                    out.push_back({r, c, -len, len});
                    r--, c++, len--;
                }
                rec(1, c, r, n, br, bc);
            }
        } else {
            if (bc <= mid) {
                int r = 1, c = n, len = n - 1;
                while (__builtin_popcount(sz) != 1) {
                    sz--;
                    out.push_back({r, c, len, -len});
                    r++, c--, len--;
                }
                rec(r, 1, n, c, br, bc);
            } else {
                int r = 1, c = 1, len = n - 1;
                while (__builtin_popcount(sz) != 1) {
                    sz--;
                    out.push_back({r, c, len, len});
                    r++, c++, len--;
                }
                rec(r, c, n, n, br, bc);
            }
        }
    } else {
        rec(1, 1, n, n, br, bc);
    }
    printf("Yes\n");
    printf("%d\n", (int) out.size());
    for (vector<int> vec : out) {
        for (int p : vec) printf("%d ", p);
        printf("\n");
    }

}
