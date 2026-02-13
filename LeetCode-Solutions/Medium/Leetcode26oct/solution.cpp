class Bank {
private:
    vector<long long> bal;
    int n;

    bool valid(int acc) {
        return acc > 0 && acc <= n;
    }

public:
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    bool transfer(int from, int to, long long amt) {
        if (!valid(from) || !valid(to) || bal[from - 1] < amt) return false;
        bal[from - 1] -= amt;
        bal[to - 1] += amt;
        return true;
    }

    bool deposit(int acc, long long amt) {
        if (!valid(acc)) return false;
        bal[acc - 1] += amt;
        return true;
    }

    bool withdraw(int acc, long long amt) {
        if (!valid(acc) || bal[acc - 1] < amt) return false;
        bal[acc - 1] -= amt;
        return true;
    }
};
