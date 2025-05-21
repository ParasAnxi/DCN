#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int modInv(int e, int phi) {
  for (int d = 1; d < phi; d++) {
    if ((d * e) % phi == 1) return d;
  }
  return -1;
}
int powMod(int base, int exp, int mod) {
  int ans = 1;
  base %= mod;
  while (exp > 0) {
    if (exp % 2 == 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return ans;
}
int main() {
  int p = 3;
  int q = 11;
  int n = p * q;
  int phi = (p - 1) * (q - 1);
  int e = 7;
  int d = modInv(e, phi);
  if (d == -1) {
    cout << "Modular inverse not found." << endl;
    return 1;
  }
  int message = 9;
  int encrypted = powMod(message, e, n);
  int decrypted = powMod(encrypted, d, n);
  cout << "RSA Parameters:" << endl;
  cout << "p = " << p << ", q = " << q << ", n = " << n << ", phi(n) = " << phi << endl;
  cout << "Public Key (e, n) = (" << e << ", " << n << ")" << endl;
  cout << "Private Key (d, n) = (" << d << ", " << n << ")" << endl;
  cout << "\nOriginal Message: " << message << endl;
  cout << "Encrypted Message: " << encrypted << endl;
  cout << "Decrypted Message: " << decrypted << endl;
  return 0;
}
