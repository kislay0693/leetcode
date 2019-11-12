vector<string> commonChars(vector<string>& A) {
        
        vector<string> result;
        map<string,int> freqMap;
        
        for(char c = 'a'; c <= 'z'; c++)
            freqMap[string(1,c)] = INT_MAX;
        
        for(int i = 0; i < A.size(); i++){
            string s = A[i];
            map<string, int> m;
            for(char c : s)
                m[string(1,c)]++;
            for(char c = 'a'; c <= 'z'; c++)
                freqMap[string(1,c)] = min(freqMap[string(1,c)], m[string(1,c)]);
        }
        
        for(auto entry : freqMap){
            for(int i = 0; i < entry.second; i++)
                result.push_back(entry.first);
        }
        return result;
    }
