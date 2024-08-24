#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace linux_Monitor
{
    // 文件读取工具类，用于从文件中读取数据。
    class ReadFile
    {
    public:
        explicit ReadFile(const std::string &name) : ifs_(name) {}
        ~ReadFile() { ifs_.close(); }

        // 读取一行数据并分割为多个字符串。
        bool ReadLine(std::vector<std::string> *args);

        // 读取指定行数的数据。
        static std::vector<std::string> GetStatsLines(const std::string &stat_file,
                                                      const int line_count)
        {
            std::vector<std::string> stats_lines;
            std::ifstream buffer(stat_file);
            for (int line_num = 0; line_num < line_count; ++line_num)
            {
                std::string line;
                std::getline(buffer, line);
                if (line.empty())
                {
                    break;
                }
                stats_lines.push_back(line);
            }
            return stats_lines;
        }

    private:
        std::ifstream ifs_; // 输入文件流。
    };
} // namespace linux_Monitor
