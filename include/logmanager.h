#pragma once
#ifndef BOOKSTORE_2025_LOGMANAGER_H
#define BOOKSTORE_2025_LOGMANAGER_H
#include"bookmanager.h"
#include"usermanager.h"
#include<string>
#include<vector>
struct OperationLog
{
    MakeArray op_id;
    MakeArray op_type;
    MakeArray op_target;
    long long time_cord;

    OperationLog() : time_cord(0) {}
    OperationLog(const std::string& op_id,const std::string& op_type,const std::string& op_target,long long time_cord):
    op_id(op_id),op_type(op_type),op_target(op_target),time_cord(time_cord) {}
    bool operator<(const OperationLog& other) const
    {
         return time_cord < other.time_cord;
    }
    bool operator==(const OperationLog& other) const
    {
        return time_cord == other.time_cord;
    }
    bool operator>(const OperationLog& other) const
    {
        return time_cord > other.time_cord;
    }
    bool operator<=(const OperationLog& other) const
    {
        return time_cord <= other.time_cord;
    }
    bool operator>=(const OperationLog& other) const
    {
        return time_cord >= other.time_cord;
    }
    bool operator!=(const OperationLog& other) const
    {
        return time_cord != other.time_cord;
    }
};

class LogManager
{
private:
    LinkedBlock<MakeArray,OperationLog> op_log_storage;
    BookManager& book_manager;
    UserManager& user_manager;
    long long op_id_count;

    void initOpCount();

public:
    LogManager(BookManager& bm,UserManager& um):
    op_log_storage("data/op_logs.dat"),book_manager(bm),user_manager(um),op_id_count(0)
    {
        initOpCount();
    }
    //记录操作日志的函数
    void logOperation(const std::string& op_id,const std::string& op_type,const std::string& op_target);
    //展示财务情况（必须实现）
    bool Showfinance(int count = 2147483647);
    //手动向助教实现
    bool reportFinance();
    bool reportEmployee();
    bool log();
};
#endif //BOOKSTORE_2025_LOGMANAGER_H