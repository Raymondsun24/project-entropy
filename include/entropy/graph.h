#pragma once

#include "entropy/nodes.h"
#include <string>
#include <vector>
#include <unordered_map>

namespace entropy {

struct SoftwareGraph {
    std::vector<FunctionRecord> functions;
    std::vector<ClassRecord>    classes;
    std::vector<GlobalRecord>   globals;

    // file → included files
    std::unordered_map<std::string, std::vector<std::string>> include_edges;

    // symbol_id → index into functions / classes / globals
    std::unordered_map<std::string, size_t> symbol_index;
};

} // namespace entropy
