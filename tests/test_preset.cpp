#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "entropy/preset.h"

using namespace entropy;
using Catch::Matchers::WithinAbs;

TEST_CASE("SystemsLibrary preset matches Config defaults") {
    Config defaults;
    Config preset = config_for_preset(Preset::SystemsLibrary);

    REQUIRE(preset.w_cognitive     == defaults.w_cognitive);
    REQUIRE(preset.w_structural    == defaults.w_structural);
    REQUIRE(preset.w_combinatorial == defaults.w_combinatorial);
    REQUIRE(preset.w_call          == defaults.w_call);
    REQUIRE(preset.w_type_use      == defaults.w_type_use);
    REQUIRE(preset.w_inheritance   == defaults.w_inheritance);
    REQUIRE(preset.w_template      == defaults.w_template);
    REQUIRE(preset.w_global_write  == defaults.w_global_write);
    REQUIRE(preset.w_global_read   == defaults.w_global_read);
}

TEST_CASE("All presets have positive layer weights") {
    for (Preset p : {Preset::SystemsLibrary, Preset::ApplicationService,
                     Preset::EmbeddedSafetyCritical, Preset::GameEngine}) {
        Config cfg = config_for_preset(p);
        REQUIRE(cfg.w_cognitive     > 0.0);
        REQUIRE(cfg.w_structural    > 0.0);
        REQUIRE(cfg.w_combinatorial > 0.0);
    }
}

TEST_CASE("All presets layer weights sum to 1.0") {
    for (Preset p : {Preset::SystemsLibrary, Preset::ApplicationService,
                     Preset::EmbeddedSafetyCritical, Preset::GameEngine}) {
        Config cfg = config_for_preset(p);
        double sum = cfg.w_cognitive + cfg.w_structural + cfg.w_combinatorial;
        REQUIRE_THAT(sum, WithinAbs(1.0, 1e-9));
    }
}

TEST_CASE("EmbeddedSafetyCritical has highest cognitive weight") {
    Config embedded = config_for_preset(Preset::EmbeddedSafetyCritical);
    Config systems  = config_for_preset(Preset::SystemsLibrary);
    Config app      = config_for_preset(Preset::ApplicationService);
    Config game     = config_for_preset(Preset::GameEngine);

    REQUIRE(embedded.w_cognitive > systems.w_cognitive);
    REQUIRE(embedded.w_cognitive > app.w_cognitive);
    REQUIRE(embedded.w_cognitive > game.w_cognitive);
}

TEST_CASE("GameEngine penalises inheritance most") {
    Config game     = config_for_preset(Preset::GameEngine);
    Config systems  = config_for_preset(Preset::SystemsLibrary);
    Config embedded = config_for_preset(Preset::EmbeddedSafetyCritical);
    Config app      = config_for_preset(Preset::ApplicationService);

    REQUIRE(game.w_inheritance > systems.w_inheritance);
    REQUIRE(game.w_inheritance > embedded.w_inheritance);
    REQUIRE(game.w_inheritance > app.w_inheritance);
}

TEST_CASE("EmbeddedSafetyCritical treats global writes as maximally dangerous") {
    Config embedded = config_for_preset(Preset::EmbeddedSafetyCritical);
    REQUIRE(embedded.w_global_write == 1.0);
}
