#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.
*/

class NumArray {
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
    NumArray obj(nums);
    obj.update(1, 2);
    cout << obj.sumRange(1, 2) << endl;
}