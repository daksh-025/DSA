class TimeMap {
public: 
    //Approach : Hashmap + Vector + Binary Search

    //Time Complexity = O(logn) =>
    /* 1. set() → O(1) average
    * HashMap lookup → O(1) average.
    * Append (timestamp, value) to vector → O(1) amortized.
    * Total = O(1) average (amortized).

    2. get() → O(log n) average
    * Find key in HashMap → O(1) average.
    * Binary Search on n timestamps → O(log n).
    * Total = O(log n) average.
    */

    //Space Complexity = O(N + K) =>
    /* N = Total number of timestamp-value pairs stored.
    * K = Total number of unique keys in HashMap.
    1. set() → O(1) auxiliary space (amortized)
    * Stores one new (timestamp, value) pair in the vector.

    2. get() → O(1) auxiliary space
    * Uses only left, right, mid, and ans variables.
    * Binary Search requires no extra data structure.
    */

    //Hashmap to store key -> vector of {timestamp, value}
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() { //this is non-parameterized constructor
        //you don't have to write anything in this block.
    }
 
    void set(string key, string value, int timestamp) {  //Time Complexity = O(1)
        // Step-1: Store timestamp and value for the given key
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) { //Time Complexity = O(logn)
        
        //Step-2: Check if key already exists in hash map
        if(mp.find(key) == mp.end()){
            return "";
        }

        //Step-3: Get the vector for the given key
        auto& vec = mp[key];
        
        //Step-4: Initialize two pointers for binary search
        int left = 0;
        int right = vec.size() - 1;

        int ans = -1;

        //Step-5: Apply binary search
        while(left <= right){

            int mid = left + (right - left)/2;

            // Case-1: Current timestamp <= requested timestamp
            if(vec[mid].first <= timestamp){
                
                ans = mid;//store current ans
                left = mid+1; //move to right for larger valid timestamp
            }
            else{ //vec[mid].first > timestamp

                right = mid-1;//move to left for smaller 
            }
        }

        //finally return the value
        if(ans == -1){
            return "";
        }

        return vec[ans].second;//{timestamp, value} value is second column

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */