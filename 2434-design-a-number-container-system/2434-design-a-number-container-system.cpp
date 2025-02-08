class NumberContainers {
public:
    unordered_map<int, set<int>> numberToIndex;
    unordered_map<int, int> indexToNumber;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indexToNumber.find(index) == indexToNumber.end()){
            indexToNumber[index] = number;
            numberToIndex[number].insert(index);
        } else {
            auto itr = numberToIndex[indexToNumber[index]].find(index);
            if (itr != numberToIndex[indexToNumber[index]].end()){
                numberToIndex[indexToNumber[index]].erase(itr);
            }
            numberToIndex[number].insert(index);
            indexToNumber[index] = number;
        }
    }
    
    int find(int number) {
        if (numberToIndex.find(number) == numberToIndex.end() || numberToIndex[number].size() == 0){
            return -1;
        } else {
            return *numberToIndex[number].begin();
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */