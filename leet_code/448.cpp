vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> ret;
    for (int i=1; i <= nums.size(); ++i)
    {
        if (std::find(nums.begin(), nums.end(), i) == nums.end()) ret.push_back(i);
    }
    return ret;
}
