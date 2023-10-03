#include "StringMan.h"
#include <iostream>
#include <cstring>

const char* StringMan::replace(const char* needle, const char* replace, const char* origin) {
    const char* pos = std::strstr(origin, needle);

    if (pos != nullptr) {
        size_t length = std::strlen(needle);
        size_t newLength = std::strlen(origin) - length + std::strlen(replace);

        char* modifiedShader = new char[newLength + 1];
        strncpy_s(modifiedShader, newLength + 1, origin, pos - origin);
        modifiedShader[pos - origin] = '\0';

        // Use strcat_s instead of strcat
        strcat_s(modifiedShader, newLength + 1, replace);
        strcat_s(modifiedShader, newLength + 1, pos + length);

        return modifiedShader;
    }

    return origin;
}