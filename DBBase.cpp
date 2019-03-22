#include "DBBase.h"
#include "CDBBase.h"


//初始化该模块
bool InitDBBaseMoudle()
{
    //检测本机是否装有mysql服务；如果没有直接返回false
    return JFCDBBase::get_instance()->InitDBBase();
}

//释放该模块
void ReleaseDBBaseMoudle()
{
    JFCDBBase::get_instance()->CloseDB();
}

//连接数据库
bool ConnectDB(const StruConnectDBInfo& conn_info)
{
    return JFCDBBase::get_instance()->ConnectDB(conn_info);
}

//执行Sql
bool ExecSql(const char* s_sql,int*& p_result)
{
    return JFCDBBase::get_instance()->ExecSql(s_sql, p_result);
}