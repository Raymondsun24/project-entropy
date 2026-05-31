#pragma once

namespace entropy {

struct EntropyResult {
    double cognitive     = 0.0;  // Shannon:   -Σ p log₂ p
    double structural    = 0.0;  // Graph:     -Σ (d/2m) log₂ (d/2m)
    double combinatorial = 0.0;  // Boltzmann: Σ log(out_degree + 1)
    double composite     = 0.0;  // weighted sum of the three layers
};

} // namespace entropy
