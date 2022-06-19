#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find_paths(
    int current_index, vector<vector<int>> &matches,
    vector<int> &path_lengths, vector<int> &leaf_indexes
)
{
    // return when leaf node reached
	if (matches[current_index].empty()) {
		path_lengths[current_index] = 0;
		leaf_indexes[current_index] = current_index;
		return;
	} 

    // recursively go through other nodes
	for (int i = 0; i < matches[current_index].size(); i++)
		find_paths(matches[current_index][i], matches, path_lengths, leaf_indexes);

	for (int i = 0; i < matches[current_index].size(); i++)
    {
		// if the height of the child node is longer, 		
        if (path_lengths[matches[current_index][i]] > path_lengths[current_index])
        {
            // set all heights along the path to the current node to that value
			path_lengths[current_index] = path_lengths[matches[current_index][i]];
            // indicate the index of the leaf node that the current node leads to
			leaf_indexes[current_index] = leaf_indexes[matches[current_index][i]];
		}
	}

	path_lengths[current_index]++;
}

int main() {
	
	int n, k, p;
	cin >> n >> k;

    // store player scores
	vector<long> players(k);
	for (int i = 0; i < k ; i++)    
		cin >> players[i];
	sort(players.begin(), players.end());

    // store nodes (the indexes of child nodes)
	vector<vector<int>> matches(n, vector<int>());
	for (int i = 1; i < n; i++)
    {
		cin >> p;
		matches[p].push_back(i);		
	}

    // store path length
	vector<int> path_lengths(n, -1);

    // store the indexes which the nodes point to
    vector<int> leaf_indexes(n, -1);
	
    // find the longest path between each node and its leaf
    find_paths(0, matches, path_lengths, leaf_indexes);

    // store the path length of each leaf node
	vector<int> leaf_paths(n, 0);
	for (int i = 0; i < n; i++)
		leaf_paths[leaf_indexes[i]]++;
	sort(leaf_paths.begin(), leaf_paths.end());

    // omit root node
	long long score = -players[k - 1];
	// match highest score to longest path
    for (int i = 0; i < k; i++)
		score += players[i] * leaf_paths[n - k + i];

	cout << score << endl;

	return 0;
}