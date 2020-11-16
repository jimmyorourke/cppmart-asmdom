#pragma once

#include <iomanip>
#include <sstream>
#include <type_traits>

// Format to a number of decimal places -- fmtlib would also work well
template <typename T>
inline std::string to_fixed_precision_str(T num, int decimalPlaces = 2) {
    static_assert(std::is_arithmetic<T>::value, "Integral required.");
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << num;
    return stream.str();
}