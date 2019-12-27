string longestPalindrome(string s) {
        int len = s.size();
        int maxLength = 1;
        int start = 0;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for(int i = 0; i < len; i++)
            dp[i][i] = 1;
        
        for(int i = 0 ; i < len-1; i++){
            if(s[i] == s[i+1]){ 
                dp[i][i+1] =1;
                maxLength = 2;
                start = i;
            }
        }
        
        for(int k = 3; k <= len; k++){
            
            for(int i = 0; i < len-k+1; i++){
                int j = i+k-1;
                
                if(dp[i+1][j-1] == 1 && s[i] == s[j]){
                    dp[i][j] = 1;
                    
                    if( k > maxLength){
                        maxLength = max(k, maxLength);
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
