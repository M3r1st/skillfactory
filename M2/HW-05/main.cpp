#include <iostream>
#include "Graph.h"

int main() {
    std::vector<std::string> names = { "Gerald", "Anya", "Malik", "Denas", "Faustus" };
    Graph g = Graph(names, {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 2, 0}
     });
    g.CalcPaths();
    for (std::string s : names) {
        g.PrintFriends(s, 3);
    }
}
