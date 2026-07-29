class Solution {
public:
    void merge(vector<int>& nums, int s, int e) {
        int mid = s + (e - s) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        vector<int> left(len1);
        vector<int> right(len2);

   
        for (int i = 0; i < len1; i++)
            left[i] = nums[s + i];


        for (int i = 0; i < len2; i++)
            right[i] = nums[mid + 1 + i];

        int i = 0, j = 0;
        int k = s;

        while (i < len1 && j < len2) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }

        while (i < len1)
            nums[k++] = left[i++];

        while (j < len2)
            nums[k++] = right[j++];
    }

    void mergeSort(vector<int>& nums, int s, int e) {
        if (s >= e)
            return;

        int mid = s + (e - s) / 2;

        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);

        merge(nums, s, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};