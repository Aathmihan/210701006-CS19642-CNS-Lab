#include <stdio.h>
#include <math.h>

// Returns gcd of a and b
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to perform modular exponentiation
// It returns (base^exp) % mod
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd, multiply base with result
            result = (result * base) % mod;
        }
        exp = exp >> 1;      // exp = exp / 2
        base = (base * base) % mod;  // Change base to base^2
    }
    return result;
}

int main() {
    // Two random prime numbers (input from user)
    int p, q;
    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    // First part of public key
    int n = p * q;

    // Calculate Euler's Totient
    int phi = (p - 1) * (q - 1);

    // Finding e (public key exponent) (input from user)
    int e;
    printf("Enter public key exponent (e): ");
    scanf("%d", &e);

    // Finding d (private key exponent) (input from user)
    int d;
    printf("Enter private key exponent (d): ");
    scanf("%d", &d);

    // Message to be encrypted (input from user)
    int msg;
    printf("Enter message to encrypt: ");
    scanf("%d", &msg);
    printf("Message data = %d\n", msg);

    // Encryption: c = (msg ^ e) % n
    unsigned long long c = mod_exp(msg, e, n);
    printf("Encrypted data = %llu\n", c);

    // Decryption: m = (c ^ d) % n
    unsigned long long m = mod_exp(c, d, n);
    printf("Original Message Sent = %llu\n", m);

    return 0;
}
