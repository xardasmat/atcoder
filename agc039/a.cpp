#include <iostream>
#include <algorithm>

int main()
{
    std::string s;
    int64_t k;
    std::cin >> s >> k;
    int64_t sn = s.length();
    std::string ss = s+s;
    ss.push_back(255);
    int64_t result = 0;
    char prev = ss[0];
    int64_t count = 1;
    for (int i=1;i<ss.length();++i)
    {
        if (ss[i] == prev)
            ++count;
        else
        {
            int64_t num = k;
            if (i-count == 0 || i == ss.length()-1) num = 1;
            else if (i >= s.length()) num = 0;
            if (i-count <= s.length() && i >= s.length()) num = k-1;
            if (i-count == 0 && i == ss.length()-1) num=k;
            result += count/2*num;
            count = 1;
        }
        prev = ss[i];
    }
    result = std::min(result, sn*k/2);
    std::cout << result;
    return 0;
}
