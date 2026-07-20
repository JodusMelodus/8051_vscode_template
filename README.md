# 8051 VS Code Template

This repository is a Visual Studio Code template for building 8051 microcontroller C projects with the SDCC compiler.

## What this template contains

- `.vscode/c_cpp_properties.json` — VS Code C/C++ IntelliSense configuration and include paths.
- `.vscode/tasks.json` — build task definition for compiling the project with SDCC and generating a HEX output file.
- `src/main.c` — example C source file for your 8051 application.
- `src/REG51ATLPRB2.h` — sample device header file for the target 8051 variant.
- `build/` — output directory for generated build artifacts.

## Prerequisites

Before using this template, install the following tools:

- SDCC (Small Device C Compiler): https://sdcc.org
- `packihx` utility for converting Intel HEX output to a final `.hex` file. This may be included with SDCC or installed separately.
- Visual Studio Code with the C/C++ extension for IntelliSense and task support.

## Setup

1. Open this folder in Visual Studio Code.
2. Confirm the SDCC paths in `.vscode/c_cpp_properties.json`:
   - `compilerPath` should point to your installed `sdcc.exe`.
   - `includePath` should include `${workspaceFolder}/**` plus any SDCC or external library header directories.
3. If you need additional header file locations, add them to `includePath` in `.vscode/c_cpp_properties.json`.

Example:

```json
"includePath": [
  "${workspaceFolder}/**",
  "C:/Program Files/sdcc/include",
  "C:/c_libraries"
]
```

## Build task

The build task is defined in `.vscode/tasks.json` as `Build 8051 Project (SDCC)`.

How it works:

- Creates the `build` directory if it does not already exist.
- Collects all `.c` files from the `src` directory.
- Invokes `sdcc` with 8051 options and the selected memory model.
- Writes an Intel HEX output file to `build/output.ihx`.
- Converts `output.ihx` to `build/output.hex` using `packihx`.

The task includes the following user inputs:

- `memoryModel` — SDCC memory model for 8051 code generation.
  - `--model-small` (default): variables live in internal RAM (IRAM).
  - `--model-medium`: variables live in external page RAM (PRAM).
  - `--model-large`: variables live in external RAM (XRAM).
- `iramSize` — internal RAM size in bytes, typically `128` or `256`.
- `xramSize` — external RAM size in bytes for the target board.
- `codeSize` — maximum code size (ROM) in bytes, such as `8192`, `16384`, `32768`, or `65536`.

## How to build

1. Open `src/main.c` or any source file under `src`.
2. Press `Ctrl+Shift+B`.
3. Select `Build 8051 Project (SDCC)` if it is not already selected.
4. Choose the appropriate values for memory model, IRAM size, XRAM size, and code size.
5. The task runs and writes outputs to `build/output.ihx` and `build/output.hex`.

## Adding source files

- Add new `.c` files to the `src` directory.
- If your project uses additional libraries, add their header files to the workspace or external include paths and update `includePath` as needed.
- The build task automatically compiles all `.c` files found under `src`.

## Build outputs

After a successful build, the `build` folder contains:

- `output.ihx` — Intel HEX format file produced by SDCC.
- `output.hex` — final HEX file created by `packihx`; typically the file used for programming the 8051 device.
- Additional SDCC artifacts such as `.lst`, `.rel`, `.asm`, `.mem`, and `.cdb`.

## Customization

- To change the target 8051 variant or compiler options, edit the `sdcc` command in `.vscode/tasks.json`.
- To add compiler flags, modify the command line in the task.
- To use a different output file name, update both the `sdcc` output option and the `packihx` conversion target.

## Notes

- This template is intended for simple 8051 C development with SDCC.
- Verify the memory sizes and code size values match your specific 8051 device.
- If SDCC is installed in a different location, update both `compilerPath` and the include paths in `.vscode/c_cpp_properties.json`.
