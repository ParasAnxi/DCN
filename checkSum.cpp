#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &data) {
  int sum = 0;
  for (auto i : data) {
    sum += i;
  }
  while (sum >> 8)
    sum = (sum & 0xFF) + (sum >> 8);
  return ~sum & 0xFF;
}
int main() {
  vector<int> data = {100, 150, 200};
  int n = data.size();
  int checksum = solve(data);
  cout << "Checksum calculated and sent: " << checksum << endl;
  vector<int> received = data;
  received.push_back(checksum);
  int recCheckSum = solve(received);
  if (recCheckSum == 0)
    cout << "No error detected in received data." << endl;
  else
    cout << "Error detected in received data!" << endl;
  return 0;
}
