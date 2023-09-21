import java.math.*;

class Solution {
    public int countOrders(int n) {
        long modulo = (long) Math.pow(10, 9) + 7;
        BigInteger[] factorial = new BigInteger[n * 2 + 1];
        factorial[0] = BigInteger.ONE;
        
        for (int i = 1; i <= (n * 2); i++) {
            factorial[i] = factorial[i - 1].multiply(BigInteger.valueOf(i));
        }
        
        BigInteger divisor = BigInteger.ONE;
        for (int i = 0; i < n; i++) {
            divisor = divisor.multiply(BigInteger.valueOf(2));
        }
        
        factorial[n * 2] = factorial[n * 2].divide(divisor);
                
        
        return (factorial[n * 2].remainder(BigInteger.valueOf(modulo))).intValue();
    }
}