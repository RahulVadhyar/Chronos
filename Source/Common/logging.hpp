/*
Copyright (c) 2024 Rahul Satish Vadhyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include <iostream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
// 0 - nothing
// 1 - additional info on errors
// 2 - basic info
// 3 - verbose
// 4 - includes frame fraw
static inline std::string getFileName(const std::string& path)
{
    std::filesystem::path p(path);
    return p.filename().string();
}

static inline std::string getTimestamp()
{
    auto now = std::chrono::system_clock::now();
    auto now_ns = std::chrono::duration_cast<std::chrono::milliseconds>(
	now.time_since_epoch())
		      .count();
    std::ostringstream oss;
    oss << now_ns;
    return oss.str();
}

#ifdef CHRONOS_ENABLE_LOGGING
#define S1(x) #x
#define S2(x) S1(x)
#define LOCATION __FILE__ ":" S2(__LINE__)
#define LOG(LEVEL, MESSAGE)                                                    \
    if (LEVEL <= CHRONOS_ENABLE_LOGGING) {                                     \
	std::cout << "[Chronos][" << getFileName(LOCATION) << "]" << "["       \
		  << getTimestamp() << "]" << ": " << MESSAGE << std::endl;    \
    }
#else
#define LOG(LEVEL, MESSAGE)
#endif
