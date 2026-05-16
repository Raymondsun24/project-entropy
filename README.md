# Project Entropy

> *Measuring the drift from crystal toward gas.*

---

## Inspiration

In high school, I had a physics teacher who changed the way I see everything. Charming, endlessly curious, and impossibly enthusiastic — he didn't just teach us the subject, he taught us how to look at the world. I attended the physics contest camp, spending hours and hours on problems, late into evenings, surrounded by others who felt the same pull toward something they couldn't quite name. Those were some of the happiest moments of my life.

On the physics contests, I never went as far as I would have liked — more problems left me stumped than I'd like to admit. But what those years gave me was something harder to grade: a lens. The universe, for all its apparent complexity, operates on remarkably simple principles. Gravitational force, mass-energy, angular momentum — each a compact expression that encodes enormous explanatory power. The simpler the law, the deeper it cuts. I hold the deepest gratitude to that teacher for giving me that view.

This shaped how I think about the universe — that beneath every apparent complexity lies a simpler truth waiting to be uncovered. In my idealistic world, code should work the same way. A function should do one thing completely. A system should be expressible in a handful of principles. The best software, like the best physics, shouldn't require a manual.

But software doesn't stay that way. I've read widely on complexity — clean architecture, design principles, systems thinking. What struck me is that while we have no shortage of opinions, we have no universal measurement. We can argue about whether a system is "too complex," but we can't point to a number. We have no thermometer.

Then it clicked: **entropy**.

In thermodynamics, entropy measures the degree of disorder in a closed system. The second law is unsparing — entropy never decreases on its own. Left to itself, order dissolves. This maps almost perfectly onto how software evolves. Every hasty commit, every undocumented shortcut, every patch on a patch raises the entropy. The codebase drifts from crystal toward gas. Project Entropy exists to measure that drift — and to make it visible before it becomes irreversible.

There's something I've always found beautiful about indeterminism — even if it complicates the picture. Quantum mechanics traded certainty for probability. Chaos theory showed that even tidy deterministic systems can spiral beyond prediction. And now AI adds its own layer — models that don't give the same answer twice, code written by something that doesn't quite understand what it's writing.

And yet — the macro world holds. Newton's laws didn't disappear when Heisenberg published the uncertainty principle. Maxwell's equations still govern every radio wave. Thermodynamics still predicts every engine. The classical formulas work not despite quantum indeterminism but alongside it — emergent order arising from the statistical averaging of a trillion uncertain events. The uncertainty is real at the bottom. The bridge is still real at the top.

That is what grounds this project. The principles of good software didn't disappear when AI arrived. Simple functions, clear interfaces, low coupling — these are the macro laws of software. They held before neural networks, and they hold now. If anything, in a world where AI can write ten thousand lines faster than a human can review ten, measuring order and disorder matters more than ever.

So we reach for a thermometer. Not to stop the drift, but to see it clearly — to write something a little simpler, a little more honest, a little more beautiful. To reduce the entropy of this world by a little.

*No matter how unbelievable that seems.*

---

## What It Does

Project Entropy is a static analysis tool for C++ codebases that produces a unified entropy score — a single number (and its breakdown) representing the degree of disorder in a software system. It draws from three complementary entropy formulations:

| Layer | Formula | What it sees |
|---|---|---|
| **Cognitive** | Shannon: H = -Σ p log₂ p | How unevenly complexity is distributed across functions |
| **Structural** | Graph: H = -Σ (dᵢ/2m) log₂ (dᵢ/2m) | How disordered the dependency and call graph topology is |
| **Combinatorial** | Boltzmann: S = k · ln(Ω) | How many valid structural arrangements exist (approximated) |

The final score is a weighted composite: `E = α·H_cognitive + β·H_structural + γ·S_boltzmann`

---

## Output

- **CLI** — terminal report with entropy score, per-file breakdown, and hot spots
- **HTML report** — interactive visualizations: entropy heatmap, dependency graph, complexity distribution charts

---

## Building

**Prerequisites**
- CMake 3.14+
- LLVM 17+ with libclang (see below)
- A C++17-capable compiler
**1. Install LLVM**

| Platform | Command |
|---|---|
| macOS (Apple Silicon) | `brew install llvm` |
| macOS (Intel) | `brew install llvm` |
| Ubuntu / Debian | `sudo apt install llvm-17 libclang-17-dev` |

**2. Set `LLVM_ROOT`**

Point `LLVM_ROOT` at your LLVM installation before configuring. This is the only setup step required — no paths are hardcoded in the build system.

```bash
# macOS Apple Silicon
export LLVM_ROOT=/opt/homebrew/opt/llvm

# macOS Intel
export LLVM_ROOT=/usr/local/opt/llvm

# Linux
export LLVM_ROOT=/usr/lib/llvm-17
```

**3. Build**

```bash
cmake --preset default      # configure (Debug)
cmake --build --preset default
ctest --preset default      # run tests
```

For a release build:

```bash
cmake --preset release
cmake --build --preset release
```

---

## Status

> Early design phase. Architecture and metric design in progress.
