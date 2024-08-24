#include "read_file.h"

namespace linux_Monitor
{
    // 从文件中读取一行并分割成多个单词，存储到向量中。
    bool ReadFile::ReadLine(std::vector<std::string> *args)
    {
        std::string line;
        std::getline(ifs_, line);

        // 检查文件流是否因到达文件末尾或其他错误而结束，或者读取的行是否为空
        if (!ifs_ || line.empty()) // 提升了错误检查的健壮性
        {
            return false;
        }

        std::istringstream line_ss(line);
        std::string word;
        // 使用更健壮的方式从字符串流中提取单词
        while (line_ss >> word)
        {
            args->push_back(word);
        }

        // 只有在实际向 args 中添加了单词时，才返回 true
        return !args->empty();
    }
} // namespace linux_Monitor
