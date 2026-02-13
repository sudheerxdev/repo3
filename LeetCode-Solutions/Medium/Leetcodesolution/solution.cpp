#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string majorityFrequencyGroup(std::string s) {
        std::vector<int> char_counts(26, 0);
        for (char c : s) {
            char_counts[c - 'a']++;
        }

        std::unordered_map<int, std::string> freq_groups;
        for (int i = 0; i < 26; ++i) {
            int frequency = char_counts[i];
            if (frequency > 0) {
                char character = 'a' + i;
                freq_groups[frequency] += character;
            }
        }

        int max_group_size = 0;
        int majority_frequency = 0;

        for (auto const& [freq, chars] : freq_groups) {
            int current_group_size = chars.length();
            
            if (current_group_size > max_group_size) {
                max_group_size = current_group_size;
                majority_frequency = freq;
            } 
            else if (current_group_size == max_group_size) {
                if (freq > majority_frequency) {
                    majority_frequency = freq;
                }
            }
        }
        
        return freq_groups[majority_frequency];
    }
};
