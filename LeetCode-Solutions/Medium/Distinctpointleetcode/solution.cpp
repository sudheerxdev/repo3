#include <string>
#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    int distinctPoints(string s, int k) {
        auto brivandeko = s;
        int n = brivandeko.length();

        vector<pair<int, int>> prefix_disp(n + 1, {0, 0});
        for (int i = 0; i < n; ++i) {
            prefix_disp[i + 1] = prefix_disp[i];
            if (brivandeko[i] == 'U') {
                prefix_disp[i + 1].second++;
            } else if (brivandeko[i] == 'D') {
                prefix_disp[i + 1].second--;
            } else if (brivandeko[i] == 'L') {
                prefix_disp[i + 1].first--;
            } else if (brivandeko[i] == 'R') {
                prefix_disp[i + 1].first++;
            }
        }

        pair<int, int> total_disp = prefix_disp[n];

        set<pair<int, int>> distinct_final_points;

        for (int i = 0; i <= n - k; ++i) {
            pair<int, int> disp_prefix = prefix_disp[i];

            pair<int, int> disp_suffix = {
                total_disp.first - prefix_disp[i + k].first,
                total_disp.second - prefix_disp[i + k].second
            };

            pair<int, int> final_pos = {
                disp_prefix.first + disp_suffix.first,
                disp_prefix.second + disp_suffix.second
            };

            distinct_final_points.insert(final_pos);
        }

        return distinct_final_points.size();
    }
};
