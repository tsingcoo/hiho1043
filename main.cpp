#include <iostream>
#include <sstream>
#include <vector>

int DP(std::vector<int> &need, std::vector<int> &value, int N, int M) {
    std::vector<int> f(M + 1, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = need[i]; j <= M; ++j) {//这里设置j的起始点可以减少计算次数
            f[j] = std::max(f[j], f[j - need[i]] + value[i]);
        }
    }
    return f[M];
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    int N, M;
    std::istringstream iss(line);
    iss >> N;
    iss >> M;
    std::vector<int> need(N, 0);
    std::vector<int> value(N, 0);
    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> need[i];
        iss >> value[i];
    }
//    for (auto i = need.begin(); i != need.end(); ++i) {
//        std::cout << *i << " ";
//    }

    int res;
    res = DP(need, value, N, M);
    std::cout << res << std::endl;

    return 0;
}