# DUMSCPP_l1

_Created for the course "Development using modern C++ standards" V. N. Karazin Kharkiv National University_

"ComandLineArgs" CMake linux program using C++23 standard.

---
## Overview

This C++23 CMake project for linux, titled **"ComandLineArgs"**, is designed to process and analyze file names provided as command-line arguments. The program groups the file names based on their extensions and displays the results. It also contains a test framework to ensure the correctness of its core functionality.

## Features

- **Extension Grouping:** The program groups files based on their extensions and displays a summary of the file types.
- **Command-line Argument Parsing:** Users can provide file names as command-line arguments.
- **Testing Framework:** The program includes a testing function that validates its behavior using different test cases.
- **Support for Various File Extensions:** The program can handle files with different types of extensions, including unusual ones, and files with no extensions.
- **For screening**, you can use the double dot `..` when it occurs, everything before it is considered the name of the file, and everything after it is its extension

## Installation

### Prerequisites

- C++23 compatible compiler
- CMake 3.20 or later
- `std::println` from C++23 or later (Ensure that your environment supports this, or modify the code for a compatible print method.)

### Steps to Build and Run

1. Clone the repository or download the source code.
2. Create a build directory and navigate to it:
   ```bash
   mkdir build && cd build
   ```
3. Generate the build files using CMake:
   ```bash
   cmake ..
   ```
4. Compile the project:
   ```bash
   cmake --build .
   ```
5. Run the executable:
   ```bash
   ./l1 file1.txt file2.pdf image.jpg
   ```

### Example

If you run the program with the following command:
```bash
./l1 myfile.txt mydoc.doc yourdoc.doc otherfile.txt
```

It will output:
```
The number of files: 4
Types of extensions: 2
List of extensions and files:
'.doc' : 2
        mydoc.doc
        yourdoc.doc
'.txt' : 2
        myfile.txt
        otherfile.txt
```

If you run the program with the following command:
```bash
./l1 .Hello.world..example.final.point al mr .txt
```

It will output:
```
The number of files: 4
Types of extensions: 5
List of extensions and files:
'' : 2
        al
        mr
'.example.final.point' : 1
        .Hello.world..example.final.point
'.final.point' : 1
        .Hello.world..example.final.point
'.point' : 1
        .Hello.world..example.final.point
'.txt' : 1
        .txt
```

## Functionality

### `getCountArgs(std::vector<std::string> arguments)`

This function processes a list of file names and groups them by their extensions. If a file has no extension, it is grouped under the empty string (`""`). The function returns a `StringVectorMap`, which maps extension types (like `.txt`, `.pdf`, etc.) to lists of file names.

### `printMapInfo(StringVectorMap countArgs)`

This function prints out a summary of file extensions and the count of files for each extension `StringVectorMap`.

### `test(Func, T)`

A utility function used to test the correctness of the program. It compares two values and prints the results, indicating whether the test passed or failed.

### `testGetCountArgs()`

This function runs a set of predefined tests to verify that the `getCountArgs` function works correctly. It tests various file name and extension combinations to ensure the logic is sound.

### `main(int argc, char *argv[])`

The entry point of the program. If the user provides command-line arguments, it processes them using the `getCountArgs` function and prints the results. If no arguments are provided, it runs the test suite to validate the program's behavior.

## Testing

The project includes automated tests for the core functionality of the program. These tests check if the program correctly groups files based on their extensions.

To run the tests:

1. Build the project (as described above).
2. Run the program without any command-line arguments:
   ```bash
   ./l1
   ```

This will trigger the test cases, and the program will output whether all tests passed or if any tests failed.

## CMake Configuration

The project uses **CMake** for building. The `CMakeLists.txt` file contains the necessary setup to configure the build process.

Key points in `CMakeLists.txt`:
- The project requires C++23 standard.
- It builds an executable called `l1` from the `l1.cpp` source file.
- After building the project, the executable is copied to a specified directory using `rsync` (comment out or change `custom_command` when building it yourself).
