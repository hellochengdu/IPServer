#ifndef JF_DBBASE_LIBRARY_H
#define JF_DBBASE_LIBRARY_H

//连接数据库结构定义
typedef struct _tagStruConnectDBInfo
{
    char conn_user_name[50];//用户名
    char conn_password[50];//密码
    char conn_host[50];//主机地址
    char conn_database[50];//数据库名
}StruConnectDBInfo, *PStruConnectDBInfo;

extern "C"
{
    //初始化该模块
    bool InitDBBaseMoudle();

    //释放该模块
    void ReleaseDBBaseMoudle();

    //连接数据库
    bool ConnectDB(const StruConnectDBInfo& conn_info);

    //执行Sql
    bool ExecSql(const char* s_sql,int*& p_result);
}

#endif