#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class modint final {
    public:
        const static long long mod = 998244353;

        constexpr modint () : x{0} {};
        constexpr explicit modint (long long _x) : x{_x % mod} { if (x < 0) x += mod; }
        constexpr modint (const modint &m) : x{m.x} {}

        constexpr modint& operator= (modint other) {
            if (this != &other) x = other.x;
            return *this;
        }

        constexpr bool operator== (modint other) const {
            return x == other.x;
        }

        constexpr bool operator!= (modint other) const {
            return !(*this == other);
        }

        constexpr modint operator+ (modint other) const {
            if (x + other.x >= mod) return modint{x + other.x - mod};
            else return modint{x + other.x};
        }

        constexpr modint operator- (modint other) const {
            if (x - other.x < 0) return modint{x - other.x + mod};
            else return modint{x - other.x};
        }

        constexpr modint operator* (modint other) const {
            return modint{x * other.x % mod};
        }

        constexpr modint operator^ (modint other) const {
            modint ans{1};
            modint mult = *this;
            while (other.x) {
                if (other.x & 1) {
                    ans = ans * mult;
                }

                mult = mult * mult;
                other.x /= 2;
            }

            return ans;
        }

        constexpr modint operator/ (modint other) const {
            return (*this) * (other^modint{-2});
        }

        constexpr modint& operator+= (modint other) {
            return *this = *this + other;
        }

        constexpr modint& operator-= (modint other) {
            return *this = *this - other;
        }

        constexpr modint& operator*= (modint other) {
            return *this = *this * other;
        }

        constexpr modint& operator/= (modint other) {
            return *this = *this / other;
        }

        constexpr modint& operator++() {
            return *this = *this + modint{1};
        }
        constexpr modint operator++(int) {
            long long old = x;
            *this = *this + modint{1};
            return modint{old};
        }
        
        constexpr modint& operator--() {
            return *this = *this - modint{1};
        }
        constexpr modint operator--(int) {
            long long old = x;
            *this = *this - modint{1};
            return modint{old};
        }

        constexpr long long value() const { return x; }

    private:
        friend istream& operator>>(istream&, modint&);
        friend ostream& operator<<(ostream&, const modint&);
        long long x;
};

modint operator"" _mi (unsigned long long mi) {
    return modint{static_cast<long long>(mi)};
}

istream& operator>>(istream &is, modint &mi) {
    return is >> mi.x;
}

ostream& operator<<(ostream &os, const modint &mi) {
    return os << mi.x;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<modint> presents(1000001, 0_mi);
    vector<modint> counter(1000001, 0_mi);

    for (int i = 1; i <= n; i++) {
        int ki;
        cin >> ki;
        for (int j = 1; j <= ki; j++) {
            int a_ij;
            cin >> a_ij;

            presents[a_ij] += 1_mi / (modint(n) * modint(ki));
            counter[a_ij]++;
        }
    }

    modint answer{0};

    for (int i = 1; i <= 1000000; i++) {
        answer += presents[i] * counter[i];
    }

    cout << answer / modint{n};
}
