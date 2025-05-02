# EasyLogger
EasyLogger is a simple and lightweight logging utility written in C. It is designed to be easy to integrate into your projects and provides functionality for logging messages with different severity levels, timestamps (including milliseconds), and process IDs.


## Features
* Log Levels: Supports multiple log levels such as DEBUG, TRACE, APPERRO, and SYSERRO.
* Timestamps: Logs include precise timestamps with millisecond accuracy.
* Process Information: Logs include the process ID (PID) for better traceability.
* File Logging: Logs are written to a specified file in append mode to preserve previous logs.
* System Logging: Optionally logs messages to the system log using syslog (Linux only)

## Usage
### Compilation:  
Log Levels: Supports multiple log levels such as DEBUG, TRACE, APPERRO, and SYSERRO.
Timestamps: Logs include precise timestamps with millisecond accuracy.
Process Information: Logs include the process ID (PID) for better traceability.
File Logging: Logs are written to a specified file in append mode to preserve previous logs.
System Logging: Optionally logs messages to the system log using syslog (Linux only) 

To compile the project, use the provided `makefile`. The following commands are available:
* all --> Compile logger library and Main.c for testing 

## Example of main usage 
* ./bin/main logs.txt 0

## Log format
Logs are written in the following format:
* [<LOG_LEVEL>]-->[Pid:<PID>]-->[<TIMESTAMP>]-->[<MESSAGE>]
### Example of entry
* [DEBUG]-->[Pid:12345]-->[2025-04-30 14:23:45.123]-->[This is a debug message]

