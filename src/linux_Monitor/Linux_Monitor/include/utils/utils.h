#pragma once

#include <boost/chrono.hpp>

namespace linux_Monitor
{
    // 工具类，提供时间计算等功能。
    class Utils
    {
    public:
        // 计算两个时间点之间的秒数差。
        static double SteadyTimeSecond(
            const boost::chrono::steady_clock::time_point &t1,
            const boost::chrono::steady_clock::time_point &t2)
        {
            boost::chrono::duration<double> time_second = t1 - t2;
            return time_second.count();
        }
    };
} // namespace linux_Monitor