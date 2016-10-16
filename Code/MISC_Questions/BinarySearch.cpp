// Binary Search
// when duplicated target exist, return the first (or last) one
int searchFirstOccurance(vector<int>& nums, int target) {
    // binary search 'target' for its last occurance
    int i = 0, j = nums.size()-1;
    int mid;

    // Loop invariant: target >= nums[i] && target <= nums[j], i < j
    while (i < j) {
        mid = (i+j)/2;
        if (nums[mid] < target)
            i = mid+1;
        else
            j = mid;
    }
    // assert i == j
    if (nums[i] == target)
        return i;
    else
        return -1;
}

// this version is from <Programming Pearls> P93
int searchFirstOccurance2(vector<int>& nums, int target) {
    int l = -1, u = nums.size();
    int mid;

    while (l+1 != u) {
        // Loop invariant: nums[l] < target <= nums[u], l < u
        mid = (l+u)/2;
        if (nums[mid] < target)
            l = mid;
        else
            u = mid;
    }
    // asert l+1 = u && nums[l] < target <= nums[u]
    if (u >= nums.size() || nums[u] != target)
        return -1;
    else
        return u;
}

int searchLastOccurance(vector<int>& nums, int target) {
    // binary search 'target' for its last occurance
    int i = 0, j = nums.size()-1;
    int mid;

    while (i < j) {
        // pay attention here, the '+1' is to make sure i-j boundary to shrink in 
        // case of only two element left
        mid = (i+j + 1)/2;  
        if (nums[mid] > target)
            j = mid-1;
        else
            i = mid;
    }
    if (nums[i] == target)
        return i;
    else
        return -1;
}