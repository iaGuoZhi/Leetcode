class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
		int ans = 0;
		for (int i = 0; i < nums1.size(); ++i)
		{
			if (nums1[i] == nums2[i])
			{
				bool valid = false;
				for (int j = 0; j < nums1.size(); ++j)
				{
					if (nums1[i] == nums1[j])
						continue;
					if (nums1[j] == nums2[i] || nums1[i] == nums2[j])
						continue;
					swap(nums1[i], nums1[j]);
					valid = true;
					ans += (i + j);
					break;
				}

				if (valid == false)
					return -1;
			}
		}
		return ans;
    }
};
