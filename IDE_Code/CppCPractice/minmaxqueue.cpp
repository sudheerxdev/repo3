// class SpecialQueue {
//     int f, r, size;
//     int a[100]; // static array, you can make it dynamic
// public:
//     SpecialQueue() {
//         f = -1;
//         r = -1;
//         size = 100;
//     }

//     void enqueue(int x) {
//         if (r == size - 1) {
//             cout << "Queue is full\n";
//             return;
//         }
//         if (f == -1) f = 0;
//         a[++r] = x;
//     }

//     void dequeue() {
//         if (f == -1 || f > r) {
//             cout << "Queue is empty\n";
//             return;
//         }
//         f++;
//     }

//     int getFront() {
//         if (f == -1 || f > r) {
//             cout << "Queue is empty\n";
//             return -1;
//         }
//         return a[f];
//     }

//     int getMin() {
//         if (f == -1 || f > r) {
//             cout << "Queue is empty\n";
//             return -1;
//         }
//         int mn = a[f];
//         for (int i = f; i <= r; i++) {
//             mn = min(mn, a[i]);
//         }
//         return mn;
//     }

//     int getMax() {
//         if (f == -1 || f > r) {
//             cout << "Queue is empty\n";
//             return -1;
//         }
//         int mx = a[f];
//         for (int i = f; i <= r; i++) {
//             mx = max(mx, a[i]);
//         }
//         return mx;
//     }
// };
class SpecialQueue {
    queue<int> q1;
    deque<int> q2; // for min
    deque<int> q3; // for max
  public:

    void enqueue(int x) {
        q1.push(x);

        // Maintain q2 for minimum
        while (!q2.empty() && q2.back() > x) {
            q2.pop_back();
        }
        q2.push_back(x);

        // Maintain q3 for maximum
        while (!q3.empty() && q3.back() < x) {
            q3.pop_back();
        }
        q3.push_back(x);
    }

    void dequeue() {
        if (q1.empty()) return;

        int frontVal = q1.front();

        // Update min deque
        if (!q2.empty() && frontVal == q2.front()) {
            q2.pop_front();
        }

        // Update max deque
        if (!q3.empty() && frontVal == q3.front()) {
            q3.pop_front();
        }

        q1.pop();
    }

    int getFront() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    int getMin() {
        if (q1.empty()) return -1;
        return q2.front();
    }

    int getMax() {
        if (q1.empty()) return -1;
        return q3.front();
    }
};



//GFG POTD solution for 24 September
