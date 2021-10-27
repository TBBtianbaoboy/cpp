//@desc new and delete realization principle

//@class new 
//@1 new 简单类型：直接调用 operator new 分配内存
//@2 new 复杂类型：先调用operator new 分配内存，然后在分配的内存上调用复杂类型的构造函数
//@3 new[]简单类型：new[] 计算好大小后直接调用operator new 分配内存
//@4 new[]复杂类型：new[] 计算好大小n 后直接调用operator new 分配内存，然后在返回地址p 的前4个字节p-4 写入数组大小，
//然后调用n 次构造函数，针对复杂类型，new[] 会额外存储数组大小

//@class delete 
//@1 delete 简单类型：直接调用 operator delete 释放内存
//@2 delete 复杂类型：先调用析构函数，然后调用 operator delete
//@3 delete[]简单类型：直接调用 operator delete[] 释内存
//@4 delete[]复杂类型：delete[]实际释放的就是返回地址 p-4 指向的内存，然后根据 p-4 指向的内存地址中的数字 n 调用 n 次析构函数,
//然后调用 operator delete[] 释放内存

