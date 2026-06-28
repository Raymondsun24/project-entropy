#include "entropy/preset.h"

namespace entropy {

Config config_for_preset(Preset p) {
    Config cfg;
    switch (p) {
        case Preset::EmbeddedSafetyCritical:
            // cyclomatic complexity is a direct safety concern; branching paths kill predictability
            cfg.w_cognitive     = 0.55;
            cfg.w_structural    = 0.35;
            cfg.w_combinatorial = 0.10;
            cfg.w_global_write  = 1.0;   // mutable shared state is especially dangerous
            cfg.w_inheritance   = 0.40;  // OOP is uncommon; don't over-penalise what isn't used
            break;

        case Preset::GameEngine:
            // tight coupling is the dominant risk: perf bottlenecks and impossible refactors
            cfg.w_cognitive     = 0.25;
            cfg.w_structural    = 0.55;
            cfg.w_combinatorial = 0.20;
            cfg.w_inheritance   = 1.0;   // deep hierarchies are the canonical game engine smell
            cfg.w_template      = 0.40;  // heavy TMP is idiomatic; penalise less
            break;

        case Preset::ApplicationService:
            // inter-module coupling dominates; per-function complexity is more tolerable
            cfg.w_cognitive     = 0.25;
            cfg.w_structural    = 0.55;
            cfg.w_combinatorial = 0.20;
            break;

        case Preset::SystemsLibrary:
        default:
            // Config defaults are calibrated for systems libraries; nothing to change
            break;
    }
    return cfg;
}

} // namespace entropy
