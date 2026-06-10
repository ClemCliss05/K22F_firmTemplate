# Embedded Firmware Template

Embedded firmware template focused on:

- Modular architecture
- Hardware abstraction
- Host-based testing
- Static analysis
- Security
- CI/CD automation

---

## Tools

VSCode main extensions:

- C/C++
- CMake Tools
- Cortex-Debug
- GitHub Actions
- SARIF Viewer

---

## Features

- Layered architecture
- Cross-compilation support
- Unit testing with GoogleTest
- clang-format
- clang-tidy
- cppcheck
- CodeQL
- GitHub Actions CI
- ASAN / UBSAN support
- J-Link flashing scripts

---

## Project Structure

```text
firmware/
├── app/        # Application entry point
├── core/       # Hardware-independent modules
├── services/   # Business logic
├── drivers/    # Peripheral drivers
└── platform/   # Target-specific code

tests/          # Host unit tests
scripts/        # Build and analysis scripts
cmake/          # Toolchain files
.github/        # CI/CD workflows
```

See [ARCHITECTURE.md](ARCHITECTURE.md) for details.

---

## Build Firmware

```bash
./scripts/build.sh
```

Generated files:

```text
.elf
.bin
.hex
```

---

## Run Tests

```bash
cmake -B build/tests \
    -DANALYSIS=ON \
    -DTESTS=ON

cmake --build build/tests

ctest --test-dir build/tests
```

---

## Static Analysis

### Format

```bash
./scripts/clang-format.sh
```

### clang-tidy

```bash
./scripts/clang-tidy.sh
```

Scope:

```text
core
services
```

### cppcheck

```bash
./scripts/cppcheck.sh
```

Scope:

```text
core
services
tests
```

### CodeQL

```bash
./scripts/codeql.sh
```

Focus:

```text
Security
Memory safety
Unsafe patterns
```

### Run Everything

```bash
./scripts/static_analysis.sh
```

---

## CI/CD

GitHub Actions automatically runs:

### Analysis

- clang-tidy
- cppcheck
- unit tests
- ASAN
- UBSAN

### Firmware

- cross compilation
- ELF generation
- BIN generation
- HEX generation

### Security

- CodeQL analysis

---

## Design Goals

- Separation of concerns
- Hardware abstraction
- Testability
- Maintainability
- Reproducible builds
- Security by default

---

## License

MIT
