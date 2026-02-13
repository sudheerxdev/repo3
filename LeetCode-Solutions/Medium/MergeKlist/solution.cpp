class Solution {
  public:
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;  // min-heap
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> pq;

        // Push the head of each list into the heap
        for (auto head : arr) {
            if (head) pq.push(head);
        }

        Node* dummy = new Node(-1);
        Node* tail = dummy;

        while (!pq.empty()) {
            Node* node = pq.top();
            pq.pop();

            // Attach the smallest node
            tail->next = node;
            tail = tail->next;

            // If next exists, push into heap
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
