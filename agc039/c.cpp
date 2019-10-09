#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int64_t mod = 998244353;

std::string neg(std::string bits)
{
    for (char& c : bits) c = c=='1'?'0':'1';
    return bits;
}

int64_t pass(const std::string& bits, int k)
{
    std::string a = bits.substr(0, k);
    std::string b = neg(a);
    std::string pattern = a;
    for (int i=k;i<bits.length();i+=2*k)
    {
        pattern += b;
        pattern += a;
    }
    return pattern <= bits ? 1 : 0;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::string bits;
    std::cin >> bits;
    std::reverse(bits.begin(), bits.end());
    while (bits.size() < n) bits.push_back('0');
    std::reverse(bits.begin(), bits.end());

    int64_t result = 0;
    int64_t pref = 0;
    std::map<int, int64_t> S;
    for (int l=1;l<=n;++l)
    {
        pref *= 2;
        pref += bits[l-1] == '1' ? 1 : 0;
        pref %= mod;

        if (n % l == 0 && (n/l) & 1)
        {
            auto& s = S[l];
            s = (pref + pass(bits, l)) % mod;
            for (auto it : S)
            {
                int k = it.first;
                if (k < l && l % k == 0) s = (s + mod - it.second) % mod;
            }
            result = (result+2*s*l) % mod;
        }
    }

    std::cout << result;
    return 0;
}
