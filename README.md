

# EasyLogger
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Github Pages](https://img.shields.io/badge/github%20pages-121013?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Popper002)

**EasyLogger** is a simple and lightweight logging utility written in C.  
It is designed for easy integration into your projects and provides functionality for logging messages with different severity levels, precise timestamps (including milliseconds), and process IDs.

---

## 🔧 Features

- **Log Levels**: Supports multiple log levels such as `DEBUG`, `TRACE`, `APPERRO`, and `SYSERRO`.
- **Timestamps**: Logs include precise timestamps with millisecond accuracy.
- **Process Information**: Each log includes the process ID (PID) for better traceability.
- **File Logging**: Logs are written to a specified file in append mode, preserving previous entries.
- **System Logging**: Optionally logs messages to the system log using `syslog` (Linux only).


---
## 🛠️ Additional Features

- **Static and Dynamic Library**: EasyLogger can be compiled as both a static library (`.a`) and a dynamic/shared library (`.so`).
- **System Log Integration**: On Linux and macOS, logs are also sent to the system log (`syslog`) for centralized logging.
- **Easy Integration**: Just include the header and link against the library (static or dynamic).
- **Cross-Platform**: Works on both Linux and macOS.
- **Error Handling**: Clear error messages for invalid input or file issues.
- **Example Main**: A sample `main.c` is provided to test and demonstrate the library.
> **Tip:** Check the `Makefile` for all available build and run options, including static and dynamic linking, cleaning, and example execution.

---

## 🚀 Usage

### 🔨 Compilation

To compile the project, use the provided `Makefile`. Available command:

```bash
make all   # Compile logger library and Main.c for testing
```

---
## 🏗️ Building as a Dynamic Library

To build the dynamic library and a dynamically linked executable:

```bash
make liblogger.so      # Build the shared library (.so)
make main_dynamic      # Build the main program linked dynamically
```

To run with the dynamic library:

```bash
make run_dynamic
# or manually:
LD_LIBRARY_PATH=lib:$LD_LIBRARY_PATH ./bin/main_dynamic logs.txt DEBUG
```
---

### ▶️ Running the Example [Only on   ![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)  or  ![macOS](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0)] 

```bash
./bin/main logs.txt DEBUG
```

**Format:**

```bash
<executable> <log_file_path> <log_level>
```

---

## 📄 Log Format

Logs follow the format:

```
[<LOG_LEVEL>]-->[Pid:<PID>]-->[<TIMESTAMP>]-->[<MESSAGE>]
```

**Example:**

```
[DEBUG]-->[Pid:12345]-->[2025-04-30 14:23:45.123]-->[This is a debug message]
```
---
## 📝 Technical Notes

- **Syslog**: On Linux/macOS, logs are also sent to the system log under the `LOG_LOCAL1` facility.
- **Dynamic Library Usage**: When using the `.so`, ensure `LD_LIBRARY_PATH` includes the `lib` directory or install the library system-wide.
- **Input Handling**: The example main accepts input from stdin; type `.exit` to quit.
- **Error Reporting**: Invalid input or file errors are handled with clear messages.

---

## 🤝 Contributing

To contribute:

1. Create a new branch:

    ```bash
    git checkout -b <branch-name>
    ```

2. Make your changes and commit them:

    ```bash
    git add .
    git commit -m "Your commit message"
    ```

3. Push your branch:

    ```bash
    git push origin <branch-name>
    ```

4. Open a **Pull Request** on GitHub.

Or feel free to **fork this project** if you want to implement your own logging logic or add new features.

---
## 📬 License

 GPL-3.0 license

---
