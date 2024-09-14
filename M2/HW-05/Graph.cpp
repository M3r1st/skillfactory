#include "Graph.h"

#include <iostream>

Graph::Graph(std::vector<std::string> names, std::vector<std::vector<int>> paths) {
	this->names = names;
	this->paths = paths;
}

void Graph::CalcPaths() {
	for (int left = 0; left < paths.size(); left++) {
		for (int right = 0; right < paths.size(); right++) {
			for (int mid = 0; mid < paths.size(); mid++) {
				if (left != right && left != mid && right != mid && paths[left][mid] != 0 && paths[mid][right] != 0) {
					if (paths[left][right] == 0) {
						paths[left][right] = paths[left][mid] + paths[mid][right];
					} else {
						paths[left][right] = std::min(paths[left][right], paths[left][mid] + paths[mid][right]);
					}
				}
			}
		}
	}
}

void Graph::PrintFriends(std::string name, int depth) {
	int x = -1;
	for (int i = 0; i < names.size(); i++) {
		if (names[i] == name) {
			x = i;
			break;
		}
	}
	PrintFriends(x, depth);
}

void Graph::PrintFriends(int x, int depth) {
	if (x < 0 || x > paths.size()) {
		std::cout << "This person does not exist." << std::endl;
		return;
	}
	bool e = true;
	for (int i = 0; i < paths.size(); i++) {
		if (paths[x][i] != 0 && paths[x][i] <= depth) {
			std::cout << names[x] << " <- " << paths[x][i] << " -> " << names[i] << std::endl;
			e = false;
		}
	}
	if (e) {
		std::cout << names[x] << " has no friends." << std::endl;
	}
}
