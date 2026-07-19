#pragma once

#include <iostream>
#include <source_location>
#include <sstream>
#include <string>
#include <string_view>

namespace smp::log {

inline constexpr std::string_view reset = "\033[0m";
inline constexpr std::string_view gray = "\033[1;37m";
inline constexpr std::string_view green = "\033[1;32m";
inline constexpr std::string_view yellow = "\033[1;33m";
inline constexpr std::string_view red = "\033[1;31m";

enum class Level {
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};

enum class FatalAction {
    None,
    Exit,
    Abort
};

inline FatalAction &fatal_action()
{
    static FatalAction action = FatalAction::Exit;
    return action;
}

inline void set_fatal_action(FatalAction action) { fatal_action() = action; }

inline void handle_fatal()
{
    switch (fatal_action()) {
    case FatalAction::None:
        break;
    case FatalAction::Exit:
        std::exit(EXIT_FAILURE);
    case FatalAction::Abort:
        std::abort();
    }
}

inline constexpr std::string_view level_color(Level level)
{
    switch (level) {
    case Level::Debug:
        return green;
    case Level::Info:
        return gray;
    case Level::Warning:
        return yellow;
    case Level::Error:
        return red;
    case Level::Fatal:
        return red;
    }
    return reset;
}

inline constexpr std::string_view level_name(Level level)
{
    switch (level) {
    case Level::Debug:
        return "Debug";
    case Level::Info:
        return "Info";
    case Level::Warning:
        return "Warning";
    case Level::Error:
        return "Error";
    case Level::Fatal:
        return "Fatal";
    }
    return "Unknown";
}

inline std::string location_string(const std::source_location &loc)
{
    std::ostringstream oss;
    oss << "\n\t(" << loc.file_name() << ":" << loc.line() << ")";
    return oss.str();
}

template <typename T>
inline void write(Level level, const T &message,
                  const std::source_location &loc = std::source_location::current())
{
    std::ostream &out = (level == Level::Warning || level == Level::Error || level == Level::Fatal)
                            ? std::cerr
                            : std::cout;

    out << "[" << level_color(level) << level_name(level) << reset << "] " << message;

#if !defined(NDEBUG) || defined(SMP_LOG_ENABLE_LOCATION)
    out << gray << location_string(loc) << reset;
#endif

    out << '\n';

    if (level == Level::Fatal) {
        handle_fatal();
    }
}
} // namespace smp::log

#define Log_Debug(message) ::smp::log::write(::smp::log::Level::Debug, (message))
#define Log_Info(message) ::smp::log::write(::smp::log::Level::Info, (message))
#define Log_Warning(message) ::smp::log::write(::smp::log::Level::Warning, (message))
#define Log_Error(message) ::smp::log::write(::smp::log::Level::Error, (message))
#define Log_Fatal(message) ::smp::log::write(::smp::log::Level::Fatal, (message))
