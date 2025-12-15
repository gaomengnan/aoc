#include <iostream>
#include <vector>
using namespace std;

string sort(string s) {
  int MAX_CHARS = 26;
  vector<int> cnt(MAX_CHARS, 0);

  for (int i = 0; i < s.size(); i++) {
    cnt[s[i] - 'a']++;
  }

  string res;

  for (int i = 0; i < MAX_CHARS; i++) {
    res.append(cnt[i], 'a' + i);
  }

  return res;
};

int main() {
  string s;
  cin >> s;

  string result = sort(s);
  cout << result << endl;

  return 0;
}
