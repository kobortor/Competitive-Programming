#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define mask(x,y,z) ((x) * 9 + (y) * 3 + (z))

string want;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int mov[27][6][4];
int whereto[27][6][4];
int okdir[6];

int path[100];

ostream& operator<<(ostream& os, array<int, 3> arr) {
    return os << "(" << arr[0] << "," << arr[1] << "," << arr[2]<<")";
}

array<int,3> frommask(int vv) {
    array<int,3> tr;
    for (int i = 2; i >= 0; i--) {
        tr[i] = vv % 3;
        vv /= 3;
    }
    return tr;
}

int sgn(int x) {
    return (x < 0 ? -1 : 1);
}

void print(vector<array<int,3>> ans);
void brute(int cpos, int dir, int clen, int vis, int ptr, const int &turn) {

    path[ptr] = cpos;
    if (clen >= 27) {
        vector<array<int,3>> res;

        for (int i = 0; i < ptr; i++) {
            array<int,3> cv = frommask(path[i]);
        }

        res.push_back(frommask(path[0]));
        for (int i = 1; i < ptr; i++) {
            
            array<int,3> pv = frommask(path[i - 1]);
            array<int,3> cv = frommask(path[i]);
            
            array<int,3> diff = {0, 0, 0};
            int mag = 0;

            if (pv[0] != cv[0]) {
                mag = abs(cv[0] - pv[0]);
                diff = {sgn(cv[0] - pv[0]), 0, 0};
            }
            if (pv[1] != cv[1]) {
                mag = abs(cv[1] - pv[1]);
                diff = {0, sgn(cv[1] - pv[1]), 0};
            }
            if (pv[2] != cv[2]) {
                mag = abs(cv[2] - pv[2]);
                diff = {0, 0, sgn(cv[2] - pv[2])};
            }

            for (int x = 1; x <= mag; x++) {
                array<int,3> hpos;
                for (int y = 0; y < 3; y++) {
                    hpos[y] = pv[y] + x * diff[y];
                }        
                res.push_back(hpos);
            }

        }

        vector<array<int,3>> cdup = res;
        sort(cdup.begin(), cdup.end());
        cdup.resize(unique(cdup.begin(), cdup.end()) - cdup.begin());

        /*
        cout << "have " << res.size() << " " << cdup.size() << endl;
        for (auto aa : res)
            cout << aa << endl;
        */

        print(res);
        exit(0);

    }
    
    int wosf = turn & ((~0) ^ ((1 << (clen + 1)) - 1));
    int nturn = __builtin_ctz(wosf);

    // cout << clen << " -> " << nturn << endl;

    int lneed = nturn - clen;
    for (int ndir = 0; ndir < 6; ndir++) {
        if (okdir[dir] & (1 << ndir)) {
            int nmask = mov[cpos][dir][lneed - 1];
            if (nmask == -1) {
                //cout << "bad mask\n";
                continue;
            }
            if (nmask & vis) {
                //cout << "seen mask\n";
                continue;
            }

            int nvis = nmask | vis;
            int npos = whereto[cpos][dir][lneed - 1];
            int nlen = nturn;

            path[ptr + 1] = npos;

            npos = whereto[npos][ndir][1];

            if (npos == -1 && nlen != 27) continue;
            if (nlen != 27 && (nvis & (1 << npos))) continue;

            int nptr = ptr + 2;

            //cout << "from " << frommask(cpos) << " go to " << frommask(npos) << " nlen " << nlen << endl;

            brute(npos, ndir, nlen, nvis, nptr, turn);
        } else {
            //cout << "bad dir\n";
        }
    }
}

void prepare() {

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if ((i >> 1) == (j >> 1)) {
                continue;
            }
            okdir[i] ^= (1 << j);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                    
                for (int d = 0; d < 6; d++) {
                    int sf = 0;
                    for (int x = 0; x <= 3; x++) {
                        
                        int nx = i + dx[d] * x;
                        int ny = j + dy[d] * x;
                        int nz = k + dz[d] * x;

                        if ((0 <= nx && nx < 3) &&
                            (0 <= ny && ny < 3) &&
                            (0 <= nz && nz < 3)) {
                            sf ^= (1 << mask(nx, ny, nz));
                            whereto[mask(i, j, k)][d][x] = mask(nx, ny, nz);
                        }
                        else {
                            sf = -1;
                            whereto[mask(i, j, k)][d][x] = -1;
                        }

                        mov[mask(i, j, k)][d][x] = sf;

                    }
                }

            }
        }
    }

}

int read_and_parse() {

    for (int i = 'A'; i <= 'M'; i++) {
        want.push_back(i);
        want.push_back(i + ('a' - 'A'));
    }
    want.push_back('N');

    vector<string> grid(15);
    for (string &s : grid) {
        cin >> s;
    }

    vector<pair<int,int>> pos;
    int fold = 0;

    for (int i = 0; i < want.size(); i++) {
        int wr = -1, wc = -1;
        for (int j = 0; j < grid.size(); j++) {
            auto v = grid[j];
            auto it = find(v.begin(), v.end(), want[i]);
            if (it != v.end()) {
                wr = j;
                wc = it - v.begin();
            }
        }
        pos.push_back({wr, wc});
    }

    for (int i = 2; i < want.size(); i++) {
        pair<int,int> cd = {pos[i].first - pos[i - 1].first, pos[i].second - pos[i - 1].second};
        pair<int,int> pd = {pos[i - 1].first - pos[i - 2].first, pos[i - 1].second - pos[i - 2].second};
        if (cd != pd) {
            fold ^= (1 << i);
        }
    }

    return fold;

}

void print(vector<array<int,3>> ans) {

    int wi = 0;
    
    char res[3][3][3];
    
    for (auto [i, j, k] : ans) {
        res[i][j][k] = want[wi++];
    }

 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << res[i][j][k];
            }
            cout << " \n"[j == 2];
        }
    }

    /*
    for (char &c : out) {
        if (c == '?') {
            c = want_tot - out_tot;
        }
    }
    for (int i = 0; i < out.size(); i++) {
        cout << out[i];
        if (i % 9 == 8) {
            cout << "\n";
        } else if (i % 3 == 2) {
            cout << ' ';
        }
    }
    */
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);

    prepare();
    int turns = read_and_parse() ^ (1 << 27);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int x = 0; x < 6; x++) {
                    brute(mask(i, j, k), x, 0, 0, 0, turns);
                }
            }
        }
    }

}
