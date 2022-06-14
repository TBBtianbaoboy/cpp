//@author aico
//@desc unique_ptr
//是一个类模板，在其内封装了指针，当实例化对象是，需要传入其他对象的指针作为参数，unique_ptr
//没有采用引用计数的方式，故有如下两个 private 函数用做限制
#include <iostream>
#include <memory>
#include <string>
#include <utility>

using std::cout;
using std::endl;

std::unique_ptr<std::string> getUniquePtr() {
  std::unique_ptr<std::string> a(new std::string("i love you!"));
  return std::move(a);
}

int main() {
  std::unique_ptr<std::string> ps1(new std::string("unique_ptr"));
  cout << *ps1 << endl;

  // @brief: unique_ptr的 unique_ptr& operator=(const unique_ptr &)=delete
  // @des : error
  /* std::unique_ptr<std::string> ps2; */
  /* ps2 = std::move(ps1); */

  // @brief: unique_ptr的 unique_ptr& operator=(unique_ptr &&)==default
  // @des : success
  std::unique_ptr<std::string> ps3;
  ps3 = std::move(ps1);

  // @brief: unique_ptr的 unique_ptr(const unique_ptr&)=delete
  // @des: error
  /* std::unique_ptr<std::string> ps4(p3); */
  /* std::unique_ptr<std::string> ps5 = ps3; */

  std::unique_ptr<std::string> returnValue = getUniquePtr();
  cout << *returnValue << endl;

  return 0;
}
