#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define CHAR 26

string getKeys(string &str) {
  vector<int> count(CHAR, 0);
  for (char c : str) {
    count[c - 'a']++;
  }
  string key = "";
  for (int i = 0; i < CHAR; i++) {
    if (count[i] > 0) {
      key += (char)(i + 'a');
    }
  }
  return key;
}

void wordsWithSameCharSet(string words[], int n) {
  unordered_map<string, vector<int>> mp;

  for (int i = 0; i < n; i++) {
    string k = getKeys(words[i]);
    mp[k].push_back(i);
  }
  for (auto it : mp) {
    for (int i : it.second) {
      cout << words[i] << " ";
    }
    cout << endl;
  }
}
// Driver program to test above function
int main() {

  string words[] = {"may",   "student", "students", "dog", "studentssess",
                    "god",   "cat",     "act",      "tab", "bat",
                    "flow",  "wolf",    "lambs",    "amy", "yam",
                    "balms", "looped",  "poodle"};
  int n = sizeof(words) / sizeof(words[0]);
  wordsWithSameCharSet(words, n);
  return 0;
}
