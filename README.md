# Smokers Problem

This program simulates the Smokers Problem, where three smokers and a bartender interact according to specific rules. Smokers can smoke cigarettes if all the necessary components are on the table. The bartender randomly selects two smokers and places their components on the table.

## Description

- **Smokers:** Each of the three smokers has an infinite supply of one of three components: tobacco, paper, or matches.
- **Bartender:** Each turn, the bartender selects two smokers and places their components on the table.
- **Smoking:** The third smoker, who has the missing component, takes all the components from the table, rolls a cigarette, and starts smoking.

## Project Structure

- `main.cpp` — The main source file of the program.
- `CMakeLists.txt` - cmake file for building the project using CMake.

## Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/st43r/MultithreadedSmoking.git
   cd MultithreadedSmoking
   ```

2. **Build the Project**:
Below are example commands for different build systems:

   **Using `cmake`**:
   
   - Ensure that you have CMake installed.
   - Create a build directory and navigate to it:

     ```bash
     mkdir build
     cd build
     ```

   - Run `cmake` and `make`:

     ```bash
     cmake ..
     make
     ```

   **Using `g++` directly**:

   ```bash
   g++ -o MultithreadedSmoking main.cpp 

## Usage

1. **Run the program**:

   After building, you can run the executable:

   ```bash
   ./MultithreadedSmoking
   ```

   The program will run continuously until you abort it.

2. **To stop the program you can press Ctrl+C.**

