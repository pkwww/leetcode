class NumArray {
private:
    vector<int> tree;
    int len;

    int getMid(int start, int end) { return (start + end) / 2; }
    int getLeft(int i) { return 2*i+1; }
    int getRight(int i) { return 2*i+2; }
    int buildTree(vector<int>& t, int curr, vector<int>& nums, int start, int end) {
        if (start == end) {
            t[curr] = nums[start];
            return t[curr];
        }
        int mid = getMid(start, end);
        int left_sum = buildTree(t, getLeft(curr), nums, start, mid);
        int right_sum = buildTree(t, getRight(curr), nums, mid+1, end);
        t[curr] = left_sum + right_sum;
        return t[curr];
    }

    int updateRecur(int tree_i, int start, int end, int index, int val) {
        if (start == end) {
            int old = tree[tree_i];
            tree[tree_i] = val;
            return old;
        }
        int mid = getMid(start, end);
        int old = index <= mid ? updateRecur(getLeft(tree_i), start, mid, index, val)
                               : updateRecur(getRight(tree_i), mid + 1, end, index, val);
        tree[tree_i] = tree[tree_i] - old + val;
        return old;
    }

    int sumRangeRecur(int i, int start, int end, int left, int right) {
        if (start >= left && end <= right) {
            return tree[i];
        }
        if (end < left || start > right) {
            return 0;
        } else {
            int mid = getMid(start, end);
            int left_sum = sumRangeRecur(getLeft(i), start, mid, left, right);
            int right_sum = sumRangeRecur(getRight(i), mid + 1, end, left, right);
            return left_sum + right_sum;
        }
    }
    
    void printLeaves(int i) {
        if (getLeft(i) >= tree.size()) {
            cout << tree[i] << ",";
            return;
        }
        if (tree[getLeft(i)] == INT_MIN && tree[getRight(i)] == INT_MIN){
            cout << tree[i] << ",";
            return;
        }
        printLeaves(getLeft(i));
        printLeaves(getRight(i));
    }
public:
    NumArray(vector<int>& nums) {
        len = nums.size();
        int tree_height = (int) ceil(log2(len));
        int node_num = (1 << (tree_height + 1)) - 1;
        tree = vector<int>(node_num, INT_MIN);
        buildTree(tree, 0, nums, 0, len-1);
    }
    
    void update(int index, int val) {
        updateRecur(0, 0, len-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRangeRecur(0, 0, len-1, left, right);
    }
}; 
