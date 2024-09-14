#pragma once

#include <vector>
#include <string>

class Graph {
public:
    Graph() = delete;
    Graph(std::vector<std::string> names, std::vector<std::vector<int>> paths);
    void CalcPaths();
    void PrintFriends(std::string name, int depth);
    void PrintFriends(int x, int depth);

private:
    std::vector<std::string> names;
    std::vector<std::vector<int>> paths;
};
