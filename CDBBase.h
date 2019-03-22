//
// Created by chenbaiyi on 18-4-24.
// 定义具体数据库管理控制的类
//

#ifndef JF_CDBBASE_H
#define JF_CDBBASE_H

#include "DBBase.h"
//#include "JFCLog.h"

//#include <pthread.h>

#include "include/jdbc/mysql_connection.h"
#include "include/jdbc/mysql_driver.h"
#include "include/jdbc/cppconn/driver.h"
#include "include/jdbc/cppconn/statement.h"


/**************  数据结构定义  ***************/


//mysqlcppconn模型结构定义
typedef struct _tagStruMysqlCppConnObj
{
    sql::mysql::MySQL_Driver* driver;//mysql驱动---对应于机子上是否装有mysql服务
    sql::Connection* conn;//传入登录信息，连接对应的数据库
    sql::Statement* state;//数据库状态
}StruMysqlCppConnObj, *PStruMysqlCppConnObj;

/******************************************/


class JFCDBBase
{
public:
    static JFCDBBase* get_instance();
    ~JFCDBBase();
public://具体功能接口
    bool InitDBBase();//初始化数据库驱动
    bool ConnectDB(const StruConnectDBInfo& conn_db_info);//连接数据库
    bool ExecSql(const char* s_sql, int*& p_result);//执行sql
    void CloseDB();//关闭数据库
    void CheckDBState();//检查数据库状态---如果断开了连接自动重连


private:
    JFCDBBase();
    JFCDBBase(const JFCDBBase &);
    JFCDBBase & operator = (const JFCDBBase &);

    static JFCDBBase* m_db_instance;//全局唯一实力句柄

private:
    StruConnectDBInfo m_conn_info;//保存的连接信息
    StruMysqlCppConnObj m_obj_info;//保存管理控制数据库对应的对象结构

    //pthread_mutex_t m_db_mutex;//用于多线程同步
    //JFCLog m_db_log;//用户输出日志信息
};


#endif //JF_CDBBASE_H
