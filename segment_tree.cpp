#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree {
private:
    // asssuming 0-based indexing
    vector<ll> seg;
    vector<ll> a;
    int n;
public:
    SegmentTree(vector<ll> a) {
        this->n = a.size();
        seg.assign(4 * n + 4, 0);
        this->a = a;
    }

    ll build(int idx, int low, int high) {
        if (low == high) {
            return seg[idx] = a[low];
        }

        int mid = low + (high - low) / 2;
        ll left = build(2 * idx + 1, low, mid);
        ll right = build(2 * idx + 2, mid + 1, high);

        return seg[idx] = max(left, right);
    }

    ll query(int idx, int low, int high, int l, int r) {
        if (l <= low && high <= r) {
            return seg[idx];
        }
        if (high < l || r < low) {
            return INT64_MIN;
        }
        int mid = low + (high - low) / 2;
        ll leftmax = query(2 * idx + 1, low, mid, l, r);
        ll rightmax = query(2 * idx + 2, mid + 1, high, l, r);

        return max(leftmax, rightmax);
    }
};
