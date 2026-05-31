#pragma once

#include "entropy/edges.h"
#include <string>
#include <vector>

namespace entropy {

struct FunctionRecord {
    std::string symbol_id;
    std::string name;
    std::string file;
    int         line          = 0;
    int         cyclomatic    = 0;
    int         nesting_depth = 0;
    int         loc           = 0;
    int         param_count   = 0;
    bool        is_const      = false;
    std::vector<Dependency> deps;
};

struct ClassRecord {
    std::string symbol_id;
    std::string name;
    std::string file;
    int         line = 0;
    std::vector<Dependency>  deps;
    std::vector<std::string> method_symbol_ids;
};

struct GlobalRecord {
    std::string symbol_id;
    std::string name;
    std::string file;
    int         line      = 0;
    bool        is_static = false;
};

} // namespace entropy
