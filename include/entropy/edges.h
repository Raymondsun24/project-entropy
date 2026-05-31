#pragma once

#include <string>

namespace entropy {

enum class DepKind {
    Call,
    TypeUse,
    Inheritance,
    Template,
    GlobalWrite,
    GlobalRead,
};

struct Dependency {
    std::string symbol_id;
    DepKind     kind;
};

} // namespace entropy
