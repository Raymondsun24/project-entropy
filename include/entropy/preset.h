#pragma once

#include "entropy/config.h"

namespace entropy {

enum class Preset {
    SystemsLibrary,
    ApplicationService,
    EmbeddedSafetyCritical,
    GameEngine,
};

Config config_for_preset(Preset p);

} // namespace entropy
