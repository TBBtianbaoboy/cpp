#include <iostream>
#include <thread>

using std::cout;
using std::thread;
void start();

int main(){
    thread t(start);
    cout << t.get_id()<<std::endl;
    t.join();
    cout << "thread over" << std::endl;
    return 0;
}

void start(){
    cout << "this is another thread" << std::endl;
}
