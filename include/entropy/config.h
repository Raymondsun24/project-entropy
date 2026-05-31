#pragma once

namespace entropy {

struct Config {
    // Entropy layer weights (should sum to 1.0)
    double w_cognitive     = 0.35;
    double w_structural    = 0.45;
    double w_combinatorial = 0.20;

    // Dependency kind weights
    double w_call         = 1.0;
    double w_type_use     = 0.5;
    double w_inheritance  = 0.8;
    double w_template     = 0.6;
    double w_global_write = 0.9;
    double w_global_read  = 0.3;
};

} // namespace entropy
