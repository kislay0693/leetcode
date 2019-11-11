vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        map<int,int> freqMap;
        map<int,int> indexMap;
        set<int> numSet(arr2.begin(),arr2.end());
        
        for(int n : arr1)
            freqMap[n]++;
        for(int i = 0; i < arr2.size(); i++)
            indexMap[i] = arr2[i];
        
        for(auto index : indexMap){
            if(freqMap.count(index.second)){
                for(int i = 0; i < freqMap[index.second]; i++)
                    result.push_back(index.second);
            }
        }
        
        for(auto entry: freqMap){
            if(!numSet.count(entry.first)){
                for(int i = 0; i < entry.second; i++)
                    result.push_back(entry.first);
            }
        }
        
        return result;
    }