#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, storage, opPktSize;
  int inpPktSize, bktSize, sizeRem;
  storage = 0;
  n = 4;
  bktSize = 10;
  inpPktSize = 4;
  opPktSize = 1;
  for (int i = 0; i < n; i++){
    sizeRem = bktSize - storage;
    if (inpPktSize <= sizeRem) {
      storage += inpPktSize;
    } else {
      printf("Packet loss = %d\n", inpPktSize);
    }
    printf("Buffer size= %d out of bucket size= %d\n", storage, bktSize);
    storage -= opPktSize;
  }
  return 0;
}