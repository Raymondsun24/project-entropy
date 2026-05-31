#include <catch2/catch_test_macros.hpp>

#include "entropy/graph.h"
#include "entropy/metrics.h"
#include "entropy/result.h"
#include "entropy/config.h"

using namespace entropy;

TEST_CASE("FunctionRecord default initializes cleanly") {
    FunctionRecord f;
    REQUIRE(f.cyclomatic    == 0);
    REQUIRE(f.nesting_depth == 0);
    REQUIRE(f.loc           == 0);
    REQUIRE(f.param_count   == 0);
    REQUIRE(f.is_const      == false);
    REQUIRE(f.deps.empty());
}

TEST_CASE("ClassRecord default initializes cleanly") {
    ClassRecord c;
    REQUIRE(c.deps.empty());
    REQUIRE(c.method_symbol_ids.empty());
}

TEST_CASE("GlobalRecord default initializes cleanly") {
    GlobalRecord g;
    REQUIRE(g.is_static == false);
}

TEST_CASE("SoftwareGraph default initializes cleanly") {
    SoftwareGraph graph;
    REQUIRE(graph.functions.empty());
    REQUIRE(graph.classes.empty());
    REQUIRE(graph.globals.empty());
    REQUIRE(graph.include_edges.empty());
    REQUIRE(graph.symbol_index.empty());
}

TEST_CASE("Config default weights are correct") {
    Config cfg;
    REQUIRE(cfg.w_cognitive     == 0.35);
    REQUIRE(cfg.w_structural    == 0.45);
    REQUIRE(cfg.w_combinatorial == 0.20);
    REQUIRE(cfg.w_call          == 1.0);
    REQUIRE(cfg.w_global_write  == 0.9);
    REQUIRE(cfg.w_global_read   == 0.3);
}

TEST_CASE("EntropyResult default initializes to zero") {
    EntropyResult r;
    REQUIRE(r.cognitive     == 0.0);
    REQUIRE(r.structural    == 0.0);
    REQUIRE(r.combinatorial == 0.0);
    REQUIRE(r.composite     == 0.0);
}

TEST_CASE("GraphMetrics default initializes cleanly") {
    GraphMetrics m;
    REQUIRE(m.complexity_scalars.empty());
    REQUIRE(m.in_degrees.empty());
    REQUIRE(m.out_degrees.empty());
    REQUIRE(m.sccs.empty());
    REQUIRE(m.coupling_coefficient == 0.0);
}

TEST_CASE("Dependency edge construction") {
    Dependency d{"sym_123", DepKind::Call};
    REQUIRE(d.symbol_id == "sym_123");
    REQUIRE(d.kind      == DepKind::Call);
}
