class FirstUnique {
    int pos;
    set< pair < int, pair<int,int> > > S;
    unordered_map<int,pair<int,int> > cp; // count and position
public:
    
    FirstUnique(vector<int>& nums) {
        pos = -1;
        for(int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            if(cp.count(curr)) {
                cp[curr].first ++;// = {cp[curr].first + 1, cp[curr].second};
            } else {
                cp[curr] = { 1 , ++pos };
            }
        }
        for(auto i : cp) S.insert({i.second.first, {i.second.second,i.first}});
    }
    
    int showFirstUnique() {
        auto x = S.begin();
        // cout << x->first << " " << (*x).second.first << " " << (*x).second.second << endl;
        if(x->first == 1) return (*x).second.second;
        return -1;
    }
    
    void add(int value) {
        // {occurences count , {first position, number}}
        if(!cp.count(value)) {
            cp[value] = {1,++pos};
            S.insert({cp[value].first, {cp[value].second,value}});
        } else {
            S.erase({cp[value].first, {cp[value].second,value}});
            cp[value].first ++;
            S.insert({cp[value].first, {cp[value].second,value}});
            
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */