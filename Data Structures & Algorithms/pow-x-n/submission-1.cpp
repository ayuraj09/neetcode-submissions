class Solution {
public:

    double getVal(double x, int n){
        if(n==1){
            return x;
        }
        double val = getVal(x,n/2);
        if(n%2==0){
            return val*val;
        }else{
            return val*val*x;
        }
    }

    double myPow(double x, int n) {
        if(n==0) return 1;
        double val = getVal(x,abs(n));
        if(n<0) return 1.0/val;
        return val;
    }
};
