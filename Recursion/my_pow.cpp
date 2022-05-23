class Solution {
public:
    double powHelper(double x, long long int n) {
        if (n == 0) {
            return 1;
        }
        if (n % 2 == 1) {
                return x * powHelper(x, n - 1);
        }
        else {
            double half = powHelper(x, n/2);
            return half * half;
        }
    }
    
    double myPow(double x, int n) {
        long long large_int = n;
        if (n < 0) {
            large_int *= -1;
        }
        double res = powHelper(x, large_int);
        if (n < 0) {
            res = 1/res;
        }
        return res;
    }  
};