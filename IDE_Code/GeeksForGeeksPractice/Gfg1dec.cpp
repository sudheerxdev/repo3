class Solution {
    struct Trie {
        Trie* child[2];
        int cnt;
        Trie() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    Trie* root;

    void insert(int num) {
        Trie* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new Trie();
            node = node->child[bit];
            node->cnt++;
        }
    }

    int countLess(int x, int k) {
        Trie* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            if (!node) break;

            int xb = (x >> i) & 1;
            int kb = (k >> i) & 1;

            if (kb == 1) {
                // If k has 1, we can take all numbers where xor bit = 0
                if (node->child[xb])
                    ans += node->child[xb]->cnt;

                // Move to branch where xor bit = 1
                node = node->child[!xb];
            } 
            else {
                // Must follow branch where xor bit = 0
                node = node->child[xb];
            }
        }

        return ans;
    }

  public:
    int cntPairs(vector<int>& arr, int k) {
        root = new Trie();
        int ans = 0;

        for (int x : arr) {
            ans += countLess(x, k);
            insert(x);
        }

        return ans;
    }
};

//GFG POTD solution for 01 December
