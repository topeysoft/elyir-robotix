// #include <Arduino.h>
// #include "Config.h"
// #include "Logger.h"


// template <class T>
// void log(String type, String tag, T message)
// {
//     Serial.print(type);
//     Serial.print("  [:>");
//     Serial.print(tag);
//     Serial.print("<:]  ");
//     Serial.print(message);
// }
// template <class T>
// void logln(String type, String tag, T message)
// {
//     log(type, tag, message);
//     Serial.println();
// }
// template <class T>
// void append(T message)
// {
//     Serial.print(message);
// }
// template <class T>
// void appendln(T message)
// {
//     Serial.println(message);
// }

// Logger::Logger()
// {
// }
// Logger::Logger(String tag)
// {
//     this->setTag(tag);
// }
// Logger::Logger(String tag, int level)
// {
//     this->setLevel(level);
//     this->setTag(tag);
// }
// // template <class T>
// void Logger::log(T message)
// {
//     if (this->level <= LOG_LEVEL_INFO)
//     {
//         log("INFO", this->tag, message);
//     }
// }
// // template <class T>
// void Logger::logln(T message)
// {
//     if (this->level <= LOG_LEVEL_INFO)
//     {
//         logln("INFO", this->tag, message);
//     }
// }
// // template <class T>
// void Logger::info(T message)
// {
//     this->log(message);
// }
// // template <class T>
// void Logger::infoln(T message)
// {
//      this->logln(message);
// }

// // template <class T>
// void Logger::debug(T message)
// {
//     if (this->level <= LOG_LEVEL_DEBUG)
//     {
//         logln("DEBUG", this->tag, message);
//     }
// }
// // template <class T>
// void Logger::debugln(T message)
// {
//      this->debug(message);
//      this->appendln("");
// }

// // template <class T>
// void Logger::warn(T message)
// {
//     if (this->level <= LOG_LEVEL_WARNING)
//     {
//         logln("WARNING", this->tag, message);
//     }
// }
// // template <class T>
// void Logger::warnln(T message)
// {
//      this->warn(message);
//      this->appendln("");
// }

// // template <class T>
// void Logger::error(T message)
// {
//     if (this->level <= LOG_LEVEL_ERROR)
//     {
//         logln("ERROR", this->tag, message);
//     }
// }
// // template <class T>
// void Logger::errorln(T message)
// {
//      this->error(message);
//      this->appendln("");
// }





// void Logger::setLevel(int level)
// {
//      this->level = level;
// }

// void Logger::setTag(String tag)
// {
//      this->tag = tag;
// }