 unordered_map<string, int> mp;

        for(string &s : arr) {
            mp[s]++;
        }

        int count = 0;
        for(string &s : arr) {
            if(mp[s] == 1) {
                count++;
                if(count == k) {
                    return s;
                }
            }
        }

        return "";