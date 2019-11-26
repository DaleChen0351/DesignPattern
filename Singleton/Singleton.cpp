#include "pch.h"


Singleton* Singleton::m_instance=nullptr;// 类的静态成员变量必须在类的外面先定义

//线程非安全版本： 单线程的话已经足够用了
Singleton* Singleton::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}






//线程安全版本，但锁的代价过高。 但是如果对性能要求不高的场合，该解决方案也是可行的，是安全的
//Singleton* Singleton::getInstance() {
//    Lock lock;
//    if (m_instance == nullptr) {
//        m_instance = new Singleton();
//    }
//    return m_instance;
//}









//双检查锁，但由于内存读写reorder不安全
//Singleton* Singleton::getInstance() {
//    
//    if(m_instance==nullptr){
//        Lock lock;
//        if (m_instance == nullptr) {
//            m_instance = new Singleton(); // new 语句有三个步骤 1 分配一片内存空间 2 调用构造函数 3 返回内存空间的首地址
//        }                                          
//    }
//    return m_instance; // 由于编译器自动优化的功能，在汇编层面（指令层面） 可能顺序会变成 1 3 2 ，这样的话，返回的instance 可能并没有完成ctor的调用
//}








//C++ 11版本之后的跨平台实现 (volatile)
//std::atomic<Singleton*> Singleton::m_instance;
//std::mutex Singleton::m_mutex;
//
//Singleton* Singleton::getInstance() {
//    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
//    std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
//    if (tmp == nullptr) {
//        std::lock_guard<std::mutex> lock(m_mutex);
//        tmp = m_instance.load(std::memory_order_relaxed);
//        if (tmp == nullptr) {
//            tmp = new Singleton;
//            std::atomic_thread_fence(std::memory_order_release);//释放内存fence
//            m_instance.store(tmp, std::memory_order_relaxed);
//        }
//    }
//    return tmp;
//}








