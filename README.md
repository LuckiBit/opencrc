# OpenCRC

OpenCRC is a lightweight, interactive, and cross-platform Command Line Interface (CLI) tool for CRC (Cyclic Redundancy Check) calculations. It supports various standard CRC algorithms and provides a user-friendly terminal experience with features like auto-completion and ANSI art banners.

## Features

- **Multiple Algorithms**: Supports CRC-8, CRC-16 (CCITT, Modbus, USB), CRC-32 (ISO/HDLC), and CRC-64 (ECMA-182, GO-ISO).
- **Interactive CLI**: Powered by `linenoise` for a smooth terminal experience with history and tab-completion.
- **Cross-Platform**: Compatible with macOS, Linux, and Windows (via WSL).
- **Rich Output**: Includes colored console output and custom ANSI art fonts.
- **Flexible Input**: Supports hex input with or without `0x` prefixes.

## Supported CRC Algorithms

| Algorithm | Width | Polynomial | Initial Value | XOR Out |
| :--- | :--- | :--- | :--- | :--- |
| CRC-8/SMBUS | 8 | 0x07 | 0x00 | 0x00 |
| CRC-16/CCITT | 16 | 0x1021 | 0xFFFF | 0x0000 |
| CRC-16/MODBUS | 16 | 0x8005 | 0xFFFF | 0x0000 |
| CRC-16/USB | 16 | 0x8005 | 0xFFFF | 0xFFFF |
| CRC-32/ISO-HDLC | 32 | 0x04C11DB7 | 0xFFFFFFFF | 0xFFFFFFFF |
| CRC-64/ECMA-182 | 64 | 0x42F0... | 0x0000... | 0x0000... |
| CRC-64/GO-ISO | 64 | 0x0000...1B | 0xFFFF... | 0xFFFFFFFF |

## Getting Started

### Prerequisites

- **CMake** (v3.14 or higher)
- **C Compiler** (GCC, Clang, etc.)

### Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/LuckiBit/OpenCRC.git
   cd OpenCRC
   ```

2. Create a build directory and compile:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Run the tool:
   ```bash
   ./bin/crc
   ```

## Usage

Once launched, you will see the `> ` prompt. You can enter hex bytes directly to calculate the CRC using the currently selected algorithm.

### Commands

- `help`: Show available commands and detailed help.
- `mode`: Interactively switch between different CRC algorithms.
- `current`: Show parameters of the currently selected CRC configuration.
- `version`: Show version information.
- `exit` or `q`: Terminate the program.

### Example

```text
> 11 22 33
Input (3 bytes): 11 22 33
CRC Result: 0x9330
```

## License

This project is licensed under the terms provided in the `LICENSE` file.

## Author

**LuckiBit** - [GitHub Profile](https://github.com/LuckiBit)
