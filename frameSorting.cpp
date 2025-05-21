#include<bits/stdc++.h>
using namespace std;

class Frame {
public:
  int seqNo;
  string data;
};

int main() {
  vector<Frame> frames = {
      {3, "Frames"}, {1, "These"}, {2, "are"}, {4, "to"},{6, "sent"},{5,"be"}};

  sort(frames.begin(), frames.end(),
       [](const Frame &a, const Frame &b) { 
        return a.seqNo < b.seqNo; 
    });

  cout << "Frames in order:"<<endl;
  for (auto &frame : frames) {
    cout << "Frame " << frame.seqNo << ": " << frame.data << endl;
  }
  return 0;
}
