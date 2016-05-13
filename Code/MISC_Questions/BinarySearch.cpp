// Binary Search
// when duplicated target exist, return the first (or last) one

int searchFirstOccurance(vector<int>& nums, int target) {
    // binary search 'target' for its last occurance
    int i = 0, j = nums.size()-1;
    int mid;

    while (i < j) {
        mid = (i+j)/2;  
        if (nums[mid] < target)
            i = mid+1;
        else
            j = mid;
    }
    if (nums[i] == target)
        return i;
    else
        return -1;
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