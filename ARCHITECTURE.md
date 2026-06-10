# Architecture

## Overview

The project follows a layered architecture that separates hardware-dependent code from portable application logic.

```text
app
 ↓
services
 ↓
core
 ↓
drivers
 ↓
platform
```

---

## Layers

### App

Application entry point.

Responsibilities:

- System initialization
- Component wiring
- Main execution flow

Files:

```text
firmware/app
```

---

### Services

Business logic.

Responsibilities:

- Application behavior
- Feature implementation
- High-level workflows

Rules:

- Can use Core
- Must not access hardware directly

Files:

```text
firmware/services
```

---

### Core

Hardware-independent utilities.

Responsibilities:

- Reusable modules
- Algorithms
- Generic infrastructure

Examples:

- Logger
- RingBuffer

Rules:

- No hardware dependencies
- Fully testable on host

Files:

```text
firmware/core
```

---

### Drivers

Hardware abstraction layer.

Responsibilities:

- Peripheral access
- Hardware interfaces

Examples:

- UART
- GPIO

Rules:

- No business logic
- Minimal processing

Files:

```text
firmware/drivers
```

---

### Platform

Target-specific implementation.

Responsibilities:

- Startup code
- Interrupt handling
- Clock configuration
- Linker script
- Vendor CMSIS files

Files:

```text
firmware/platform
```

---

## Data Flow

```text
Application
    ↓
Service
    ↓
Core
    ↓
Driver
    ↓
Hardware
```

---

## Build Modes

### Firmware Build

```text
ANALYSIS=OFF
```

Builds:

- app
- services
- core
- drivers
- platform

Target:

```text
Embedded device
```

---

### Analysis Build

```text
ANALYSIS=ON
```

Builds:

- core
- services
- tests (optional)

Used for:

- Unit tests
- clang-tidy
- cppcheck
- CodeQL

---

## Testing Strategy

Scope:

```text
core
services
```

Execution:

```text
Host machine
```

Benefits:

- Fast
- Deterministic
- Hardware-independent
- CI-friendly

---

## Static Analysis Strategy

| Tool | Scope |
| -------- | -------- |
| clang-tidy | core, services |
| cppcheck | core, services, tests |
| CodeQL | analysis build |

---

## Dependency Rules

Allowed:

```text
app      → services
services → core
drivers  → platform
```

Forbidden:

```text
core     → drivers
core     → platform
services → platform
services → hardware
```

---

## Goal

Provide a firmware foundation that is:

- Portable
- Testable
- Maintainable
- Scalable
- CI/CD friendly
