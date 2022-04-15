#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  //@answer: the best short code
  string s;
  // CTRL-D
  while (cin >> s)
    ;
  cout << s.size() << endl;
  return 0;
}
