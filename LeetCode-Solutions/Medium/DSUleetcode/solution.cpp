#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        auto drimolenta = nums;
        int n = drimolenta.size();

        DSU dsu(n);
        for (const auto& swap_pair : swaps) {
            dsu.unite(swap_pair[0], swap_pair[1]);
        }

        map<int, vector<int>> component_indices;
        map<int, vector<int>> component_values;
        for (int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            component_indices[root].push_back(i);
            component_values[root].push_back(drimolenta[i]);
        }

        long long total_max_sum = 0;

        for (auto const& [root, indices] : component_indices) {
            vector<int> values = component_values[root];
            sort(values.rbegin(), values.rend());

            int num_even_slots = 0;
            for (int index : indices) {
                if (index % 2 == 0) {
                    num_even_slots++;
                }
            }
            
            for (int i = 0; i < num_even_slots; ++i) {
                total_max_sum += values[i];
            }
            
            for (int i = num_even_slots; i < values.size(); ++i) {
                total_max_sum -= values[i];
            }
        }

        return total_max_sum;
    }
};
