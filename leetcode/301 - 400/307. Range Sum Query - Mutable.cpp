#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.
*/

// BIT version
class NumArray_BIT {
    vector<int> bit{0};
    vector<int> ori{0};

    int sumFromBegin(int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }

public:
    NumArray(vector<int>& nums) {
        bit.insert(bit.end(), nums.begin(), nums.end());
        ori.insert(ori.end(), nums.begin(), nums.end());
        int n = bit.size();
        for (int i = 1; i < n; i++) {
            auto parent = i + (i & -i);
            if (parent < n)
                bit[parent] += bit[i];
        }
    }

    void update(int i, int val) {
        i++;
        int diff = val - ori[i];
        ori[i] = val;
        while (i < bit.size()) {
            bit[i] = bit[i] + diff;
            i += i & -i;
        }
    }

    int sumRange(int i, int j) {
        return sumFromBegin(j + 1) - sumFromBegin(i);
    }
};

// Segment tree version
class NumArray_ST {
    struct Node {
        int start;
        int end;
        int val;
        Node(int start, int end, int val = 0) : start(start), end(end), val(val) {}
        Node() : Node(0, 0, 0) {}
    };
    vector<Node> tree;
    void Build(vector<int>& nums, int start, int end, int ind) {
        auto& node = tree[ind];
        node.start = start;
        node.end = end;
        if (start == end) {
            node.val = nums[start];
            return;
        }
        auto mid = start + (end - start) / 2, left_ind = ind * 2 + 1, right_ind = ind * 2 + 2;
        Build(nums, start, mid, left_ind);
        Build(nums, mid + 1, end, right_ind);
        node.val = tree[left_ind].val + tree[right_ind].val;
    }
    void UpdateNode(int i, int val, int ind) {
        auto& node = tree[ind];
        auto mid = node.start + (node.end - node.start) / 2, left_ind = ind * 2 + 1, right_ind = ind * 2 + 2;
        if (node.start == i && node.end == i) {
            node.val = val;
            return;
        }
        if (i <= mid)
            UpdateNode(i, val, left_ind);
        else
            UpdateNode(i, val, right_ind);
        node.val = tree[left_ind].val + tree[right_ind].val;
    }
    int GetSum(int i, int j, int ind) {
        const auto& node = tree[ind];
        auto mid = node.start + (node.end - node.start) / 2, left_ind = ind * 2 + 1, right_ind = ind * 2 + 2;
        if (i == node.start && j == node.end)
            return node.val;
        return (i <= mid ? GetSum(i, min(j, mid), left_ind) : 0) + (j > mid ? GetSum(max(i, mid + 1), j, right_ind) : 0);
    }
public:
    NumArray(vector<int> nums) {
        tree = vector<Node>(4 * nums.size(), Node());
        if (nums.size())
            Build(nums, 0, nums.size() - 1, 0);
    }

    void update(int i, int val) {
        UpdateNode(i, val, 0);
    }

    int sumRange(int i, int j) {
        return GetSum(i, j, 0);
    }
};

int main(void) {
    vector<int> nums{ 1, 3, 5 };
    NumArray_BIT obj(nums);
    obj.update(1, 2);
    cout << obj.sumRange(1, 2) << endl;
}