#include <iostream>

using std::cout;
using std::endl;

void convert(char *arr, unsigned int head, unsigned int tail) {
  if (tail <= 1) {
    return;
  }

  if (head == tail) {
    for (int i = 0; i <= tail; i++)
      cout << arr[i];
    cout << endl;
  } else {
    for (int j = head; j <= tail; j++) {
      std::swap(arr[j], arr[head]);
      convert(arr, head + 1, tail);
      std::swap(arr[j], arr[head]);
    }
  }
}

int main() {
  char arr[] = "abc";
  convert(arr, 1, 3);
  return 0;
}
