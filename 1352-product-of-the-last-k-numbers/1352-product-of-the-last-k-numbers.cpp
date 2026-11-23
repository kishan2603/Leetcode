class ProductOfNumbers {
    vector<int> product;
public:
    ProductOfNumbers() {
        product = {1};
    }

    void add(int num) {
        if(num==0) product = {1};
        else product.push_back(num*product[product.size()-1]);
    }
    
    int getProduct(int k) {
        if(k>=product.size()) return 0;
        return product[product.size()-1] / product[product.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */