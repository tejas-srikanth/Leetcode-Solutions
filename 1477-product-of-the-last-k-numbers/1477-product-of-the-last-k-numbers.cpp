class ProductOfNumbers {
public:
    vector<int> prefixProd;
    int totalProd = 1;
    int lastZero = -1;
    ProductOfNumbers(): prefixProd(1, 1) {
        
    }
    
    void add(int num) {
        if (num == 0){
            lastZero = prefixProd.size();
            totalProd = 1;
        } else {
            totalProd *= num;
        }
        prefixProd.push_back(totalProd);
    }
    
    int getProduct(int k) {
        if (k >= prefixProd.size() - lastZero){
            return 0;
        }
        return totalProd / prefixProd[prefixProd.size() - k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */