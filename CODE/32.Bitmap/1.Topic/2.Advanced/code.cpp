#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bitset {
private:
    vector<int> set;
    int size;
    int zeros;
    int ones;
    bool reverse;

public:
    Bitset(int n) {
        set.resize((n + 31) / 32, 0);
        size = n;
        zeros = n;
        ones = 0;
        reverse = false;
    }

    void fix(int i) {
        int index = i / 32;
        int bit = i % 32;
        if (!reverse) {
            if ((set[index] & (1 << bit)) == 0) {
                zeros--;
                ones++;
                set[index] |= (1 << bit);
            }
        } else {
            if ((set[index] & (1 << bit)) != 0) {
                zeros--;
                ones++;
                set[index] ^= (1 << bit);
            }
        }
    }

    void unfix(int i) {
        int index = i / 32;
        int bit = i % 32;
        if (!reverse) {
            if ((set[index] & (1 << bit)) != 0) {
                ones--;
                zeros++;
                set[index] ^= (1 << bit);
            }
        } else {
            if ((set[index] & (1 << bit)) == 0) {
                ones--;
                zeros++;
                set[index] |= (1 << bit);
            }
        }
    }

    void flip() {
        reverse = !reverse;
        int tmp = zeros;
        zeros = ones;
        ones = tmp;
    }

    bool all() {
        return ones == size;
    }

    bool one() {
        return ones > 0;
    }

    int count() {
        return ones;
    }

    string toString() {
        string builder;
        for (int i = 0, k = 0, number, status; i < size; k++) {
            number = set[k];
            for (int j = 0; j < 32 && i < size; j++, i++) {
                status = (number >> j) & 1;
                status ^= reverse ? 1 : 0;
                builder += to_string(status);
            }
        }
        return builder;
    }
};