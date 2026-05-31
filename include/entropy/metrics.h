#pragma once

#include <vector>
#include <cstddef>

namespace entropy {

struct GraphMetrics {
    std::vector<double> complexity_scalars;  // one per function, same order as SoftwareGraph::functions
    std::vector<double> in_degrees;          // weighted in-degree per function
    std::vector<double> out_degrees;         // weighted out-degree per function
    std::vector<std::vector<size_t>> sccs;   // Tarjan output: groups of function indices
    double coupling_coefficient = 0.0;
};

} // namespace entropy
