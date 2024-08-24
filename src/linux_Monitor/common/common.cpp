#include "common.h"

Common::Common()
{

}

Common::~Common()
{

}

/**
 * 创建文件目录
 */
void Common::create_multilevel_dir(const char* dir)
{
    char command[100] = "mkdir -p ";
    strcat(command,dir);
    system(command);
}

/**
 * 获取当前可执行文件运行的路径
 */
string Common::get_cur_path()
{
    char* current_path;
    current_path = getcwd(NULL,0);
    string str_cur_path(current_path,strlen(current_path));
    return str_cur_path;
}

/**
 * 获取日志的路径
 */
string Common::get_log_path()
{
    string current_path = get_cur_path();
    int index = current_path.find_last_of('/');
    string log_path = current_path.substr(0,index) + "/logs";
    if(access(log_path.c_str(),0))
    {
        cout<<"---->log_path is not exist,create it ..."<<endl;
        create_multilevel_dir(log_path.c_str());
    }
    
    return log_path;
}