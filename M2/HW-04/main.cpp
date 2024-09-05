#include <iostream>

bool IsKPeriodic(const std::string &s, const int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 1; i + j * k < s.size(); j++) {
            if (s[i] != s[i + j * k]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;
    std::cout << (IsKPeriodic(s, k) ? "Yes" : "No") << std::endl;
}
