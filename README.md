# smp-log

Simple header-only C++20 logger with colored console output and source location support.

`smp-log` is a small logging library for CLI tools, utilities, and personal C++ projects where a full external logging framework would be overkill. It is distributed as a header-only CMake package and exports the `smp::log` target for installed-package use, vendoring, and `FetchContent` integration.

## Features

- Header-only C++20 logger.
- Colored log levels.
- `Debug`, `Info`, `Warning`, `Error`, `Fatal` levels.
- `std::source_location` support.
- Modern CMake package with `smp::log` target.

## Basic usage

```cpp
#include <smp/log.hpp>

int main()
{
    Log_Debug("debug message");
    Log_Info("info message");
    Log_Warning("warning message");
    Log_Error("error message");
    return 0;
}
```

## License

This project is licensed under the GNU GPL-3.0. See [LICENSE](./LICENSE) for details.
