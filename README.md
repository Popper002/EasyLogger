

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

## 🚀 Usage

### 🔨 Compilation

To compile the project, use the provided `Makefile`. Available command:

```bash
make all   # Compile logger library and Main.c for testing
```

---

### ▶️ Running the Example [Only ![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black) or on ![macOS](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0)] 

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
