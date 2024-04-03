#pragma once

#define CHRONOS_LOG_LEVEL 3
// 0 - nothing
// 1 - additional info on errors
// 2 - basic info
// 3 - verbose
// 4 - includes frame fraw
#ifdef CHRONOS_ENABLE_LOGGING
#define LOG(LEVEL, CLASS, MESSAGE) \
    if (LEVEL <= CHRONOS_LOG_LEVEL) { \
        std::cout << "[Chronos log][" << CLASS "]: " << MESSAGE << std::endl; \
    }
#else
#define LOG(LEVEL, CLASS, MESSAGE)
#endif