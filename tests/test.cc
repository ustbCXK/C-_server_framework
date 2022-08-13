#include <iostream>
#include <thread>
#include "../sylar/log.h"
#include "../sylar/util.h"

int main(int argc, char** argv){

    sylar::Logger::ptr logger(new sylar::Logger);
    logger->addAppender(sylar::LogAppender::ptr(new sylar::StdoutLogAppender));

    sylar::FileLogAppender::ptr file_appender(new sylar::FileLogAppender("./log.txt"));

    //自己设置formatter
    sylar::LogFormatter::ptr fmt(new sylar::LogFormatter("%d%T%m%n"));
    file_appender->setFormatter(fmt);
    //设置日志级别
    file_appender->setLevel(sylar::LogLevel::ERROR);
    logger->addAppender(file_appender);

    //sylar::LogEvent::ptr event(new sylar::LogEvent(__FILE__, __LINE__, 0, sylar::GetThreadId(), sylar::GetFiberId(), time(0)));
    //event->getSS() << "hello log!";
    //logger->log(sylar::LogLevel::DEBUG, event);

    SYLAR_LOG_INFO(logger) << "define log INFO";
    SYLAR_LOG_DEBUG(logger) << "define log DEBUG";
    SYLAR_LOG_WARN(logger) << "define log WARN";
    SYLAR_LOG_ERROR(logger) << "define log ERROR";
    SYLAR_LOG_FATAL(logger) << "define log FATAL";

    SYLAR_LOG_FMT_DEBUG(logger, "format define log DEBUG %s", "aaa");


    //测试loggers管理类
    auto l = sylar::LoggerMgr::GetInstance()->getLogger("xx");
    SYLAR_LOG_INFO(l) << "xxx";

    return 0;
}