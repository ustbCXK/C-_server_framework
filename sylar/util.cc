#include "util.h"

namespace sylar{

//获取线程id的函数
pid_t GetThreadId() {
    return syscall(SYS_gettid);
}

//获取协程id的函数
uint32_t GetFiberId() {
    return 0;//由于暂时没有协程逻辑，所以暂时给0
}
}