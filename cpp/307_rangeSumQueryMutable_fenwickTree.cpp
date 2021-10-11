class NumArray {
private:
    vector<int> fenwick;
    vector<int> nums;
    int lowbit(int x) {
        return x & -x;
    }
    int prefixSum(int end, int sum) {
        if (end < 1)
            return sum;
        return prefixSum(end-lowbit(end), fenwick[end] + sum);
    }
    void updateFenwick(int f_index, int val_offset) {
        if (f_index >= fenwick.size())
            return;
        fenwick[f_index] += val_offset;
        return updateFenwick(f_index+lowbit(f_index), val_offset);
    }
public:
    NumArray(vector<int>& nums) {
        fenwick = vector(nums.size() + 1, 0);
        for (int i = 1; i < fenwick.size(); i++) {
            for (int j = (i - lowbit(i) + 1)-1; j <= i-1; j++) { // zero base array off-by-1
                fenwick[i] += nums[j];
            }
        }
        this->nums = nums;
    }
    
    void update(int index, int val) {
        int old = nums[index];
        nums[index] = val;
        updateFenwick(index+1, val - old);
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right+1, 0) - prefixSum(left, 0);
    }
};
