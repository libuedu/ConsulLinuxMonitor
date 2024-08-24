#pragma once

#include <glog/logging.h>
#include <iostream>
#include <mutex>
#include <string>

using namespace std;

class MyLog
{
public:
    MyLog(const string& log_path,const string& log_file_name);
    ~MyLog();

private:
    string log_path_;
    string log_file_name_;
    
};

