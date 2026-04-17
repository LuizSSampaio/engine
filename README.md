# Goiaba Engine

A learning game engine focused on merging 2D with 3D graphics, enabling amazing visuals with minimal effort.

## Installation from Source

### Prerequisites

Goiaba Engine requires the following tools and libraries:

- **Meson** (build system)
- **Ninja** (build tool)
- **C++ Compiler** with C++23 support (Clang recommended)

### Linux (Primary Platform)

#### Using Nix Flakes (Recommended)

The easiest way to get started on Linux is using Nix flakes, which provides a reproducible development environment with all dependencies pre-configured.

```bash
# Clone the repository
git clone https://github.com/LuizSSampaio/engine.git
cd engine

# Enter the Nix development environment
nix flake update
nix develop

# You're now ready to build!
```

#### Manual Installation

If you prefer to manage dependencies manually, follow these steps:

**Debian/Ubuntu:**
```bash
# Install build tools
sudo apt-get install meson ninja-build clang
```

**Fedora/RHEL:**
```bash
# Install build tools
sudo dnf install meson ninja-build clang
```

**Arch Linux:**
```bash
# Install build tools
sudo pacman -S meson ninja clang
```

After installing dependencies, clone and prepare the project:
```bash
git clone https://github.com/LuizSSampaio/engine.git
cd engine
```

### macOS

macOS support is available but has not been tested. Using Nix flakes (via NixOS or Determinate Systems' Nix installer) is recommended for consistency:

```bash
git clone https://github.com/LuizSSampaio/engine.git
cd engine
nix flake update
nix develop
```

Alternatively, you can install dependencies via Homebrew:
```bash
brew install meson ninja
```

### Windows

Windows support is available but has not been tested. You can use native Windows with MinGW or Visual Studio's C++ toolchain, though setup may require additional configuration.

## Building

Use the `justfile` task runner to build and run the engine. The `justfile` contains shortcuts for common development tasks.

### Available Tasks

```bash
just setup          # Initialize the build directory
just build          # Compile the engine
just run            # Run the compiled engine
just brun           # Build and run in one command
just docs           # Generate API documentation
just docs-serve     # Serve documentation locally on port 8080
```

### Quick Start

```bash
# First time setup
just setup

# Build and run
just brun
```

To see all available tasks, run:
```bash
just --list
```

## Documentation

Full API documentation and usage guides are available in the [`docs/`](./docs/) folder. To generate and view the documentation locally:

```bash
just docs-serve
```

This will generate the documentation and serve it at `http://localhost:8080`.

## Contributing

We welcome contributions from the community! Whether you're fixing bugs, adding features, or improving documentation, your help is appreciated. Feel free to open issues and pull requests.

---

**Current Status**: Early development stage. The engine is actively evolving with new features and improvements.
