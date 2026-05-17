#pragma once
#include <fstream>
#include <string>

// ── Write helpers ─────────────────────────────────────────────────────────────

inline void writeString(std::ofstream& out, const std::string& s) {
    size_t len = s.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(s.data(), static_cast<std::streamsize>(len));
}

template<typename T>
inline void writePOD(std::ofstream& out, const T& value) {
    out.write(reinterpret_cast<const char*>(&value), sizeof(T));
}

// ── Read helpers ──────────────────────────────────────────────────────────────

inline std::string readString(std::ifstream& in) {
    size_t len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    std::string s(len, '\0');
    in.read(s.data(), static_cast<std::streamsize>(len));
    return s;
}

template<typename T>
inline T readPOD(std::ifstream& in) {
    T value{};
    in.read(reinterpret_cast<char*>(&value), sizeof(T));
    return value;
}
