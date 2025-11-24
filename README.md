San-Z Shell

A modular, Zsh-inspired shell written from scratch in C.

San-Z Shell is a lightweight and extensible command-line shell built to understand and explore how real shells (like Bash, Zsh, and Fish) work internally.
This project is written completely in C and structured in clean, modular components to make learning, debugging, and extending easy.

⭐ Features

🖥️ Custom Dynamic Prompt
Displays username, hostname, and current working directory.

🔄 REPL Engine (Read–Eval–Print Loop)
Reads input continuously, parses it, and passes it to the executor.

⚙️ Command Execution System
Supports running external programs using fork() + execvp().

🧩 Modular Architecture
Components are split into:

prompt

repl

executor

builtins

🛠️ Built-in Commands (In Progress)

cd

exit

More coming soon.

📦 Fully Extensible
Add new built-ins, features, or modifications without breaking the core.

📁 Project Structure
San-Z-shell/
├── include/
│    ├── prompt.h
│    ├── repl.h
│    ├── executor.h
│    ├── builtins.h
├── src/
│    ├── core/
│    │     ├── prompt.c
│    │     ├── repl.c
│    │     ├── executor.c
│    ├── executor/
│    │     ├── builtins.c
├── CMakeLists.txt
└── README.md


This structure keeps the shell clean and modular, similar to real-world shells.

🏗️ How It Works
🔸 Prompt

Generates a formatted string that shows where you are in the system.

🔸 REPL

Continuously prints the prompt, reads user input, cleans it, and sends it for execution.

🔸 Executor

Splits the input into arguments and launches commands using the Unix process system.

🔸 Built-ins

Some commands like cd can’t run as external programs — they’re built directly into the shell.

🔧 Build & Run
Prerequisites

Make sure you’re on Linux or WSL2 with:

GCC

CMake

Make or Ninja

Build
mkdir build
cd build
cmake ..
make

Run
./San_Z_shell

🚀 Roadmap

Add piping (|)

Add redirection (>, <, >>)

Add command history

Add auto-suggestions

Implement environment variable support

Implement job control (&, fg, bg)

Build a plugin system

Make a themeable prompt

🤝 Contributing

Contributions are welcome!
If you want to improve the shell, fix bugs, or add features, feel free to open an issue or PR.

📜 License

MIT License — free to use, modify, and learn from.

✨ Author

Sanskaar Undale
Aspiring systems programmer & shell enthusiast.