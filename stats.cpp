#include "stats.h"
#include <limits>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& statsVect) {
    //Implement statistics here
    if (statsVect.empty()) {
        return { std::numeric_limits<double>::quiet_NaN(),
                std::numeric_limits<double>::quiet_NaN(),
                std::numeric_limits<double>::quiet_NaN() };
    }

    double sum_val = 0.0;
    double min_val = std::numeric_limits<double>::max();
    double max_val = std::numeric_limits<double>::min();

    for (double num : statsVect) {
        sum_val += num;
        if (num < min_val) {
            min_val = num;
        }
        if (num > max_val) {
            max_val = num;
        }
    }

    double avg = sum_val / statsVect.size();
    return { avg, max_val, min_val };
}
