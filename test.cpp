//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int nCr(int n, int r) {
        if (r > n)
            return 0;

        int mod = 1e9 + 7;

        // Calculate factorial of n
        int factN = 1;
        for (int i = 1; i <= n; i++) {
            factN = (factN * i) % mod;
        }

        // Calculate modular inverse of factorial of r
        int factRInverse = 1;
        for (int i = 1; i <= r; i++) {
            factRInverse = (factRInverse * i) % mod;
        }
        factRInverse = modInverse(factRInverse, mod);

        // Calculate modular inverse of factorial of (n-r)
        int factNRInverse = 1;
        for (int i = 1; i <= n - r; i++) {
            factNRInverse = (factNRInverse * i) % mod;
        }
        factNRInverse = modInverse(factNRInverse, mod);

        // Calculate nCr using modular arithmetic
        int nCr = (factN * ((factRInverse * factNRInverse) % mod)) % mod;

        return nCr;
    }

    // Function to calculate modular inverse using extended Euclidean algorithm
    int modInverse(int a, int m) {
        int m0 = m;
        int y = 0, x = 1;

        if (m == 1)
            return 0;

        while (a > 1) {
            int q = a / m;
            int t = m;

            m = a % m;
            a = t;
            t = y;

            y = x - q * y;
            x = t;
        }

        if (x < 0)
            x += m0;

        return x;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends