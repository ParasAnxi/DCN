#include<bits/stdc++.h>
using namespace std;
string solveXor(const string &a, const string &b) {
  string st = "";
  for (int i = 1; i < b.size(); i++) {
    st += (a[i] == b[i]) ? '0' : '1';
  }
  return st;
}
string solveDiv(string dividend, const string &divisor) {
  int n = divisor.size();
  string st = dividend.substr(0, n);
  while (n < dividend.size()) {
    if (st[0] == '1')
      st = solveXor(divisor, st) + dividend[n];
    else {
      string zeros(divisor.size(), '0');
      st = solveXor(zeros, st) + dividend[n];
    }
    n++;
  }
  if (st[0] == '1')
    st = solveXor(divisor, st);
  else {
    string zeros(divisor.size(), '0');
    st = solveXor(zeros, st);
  }
  return st;
}
int main() {
  string dataSt = "100100";
  string polySt = "1101";
  string newSt = dataSt + string(polySt.size() - 1, '0');
  // cout<<newSt<<endl;
  string remainder = solveDiv(newSt, polySt);
  string transmitted = dataSt + remainder;
  cout<< "Original data "<<dataSt<<endl;
  cout << "Remainder is: " << remainder << endl;
  cout << "Final data to be transmitted: " << transmitted << endl;
  string rec = transmitted;
  string recRem = solveDiv(rec, polySt);
  bool noError = true;
  for (auto c : recRem) {
    if (c != '0') {
      noError = false;
      break;
    }
  }
  if (noError)
    cout << "No error detected." << endl;
  else
    cout << "Error detected." << endl;
  return 0;
}
