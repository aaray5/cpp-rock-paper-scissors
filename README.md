# Rock Paper Scissors Game (C++)

A modular, interactive console-based Rock-Paper-Scissors game built using C++.

## Key Features
* **Interactive UI:** Console color feedback changing dynamically based on match winners.
* **Game Statistics:** Full match breakdown with individual round results and score tracking.
* **Replay Support:** Re-playable game loop with screen resets.

## Technical Concepts Demonstrated
* **Data Abstraction:** Structured state management using `struct` for round info and game results.
* **Type Safety:** Clean logic routing using `enum` for player choices and game outcomes.
* **Memory Efficiency:** Optimized parameter passing using `const reference` (`const Type&`).
* **Modular Design:** Functional decomposition isolating input validation, match logic, and visual output.

## How to Run
Compile using any C++ compiler (Visual Studio, GCC, or Clang):
```bash
g++ ConsoleApplication1.cpp -o RockPaperScissors
./RockPaperScissors
