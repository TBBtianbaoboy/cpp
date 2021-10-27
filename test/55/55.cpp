//@desc malloc 申请的空间能用 delete 释放吗？

//@1 malloc/free 主要为了兼容 c ，new/delete 完全可以取代 malloc/free 
//@2 malloc/free 的操作对象都是必须明确大小的，不能用在动态类上
//@3 new/delete 会自动进行类型检查与计算大小，malloc/free 不能执行构造函数和析构函数
//@4 malloc 申请的空间理论上是可以通过 delete 释放的，不过一般不这么做，不能保证不会出错
