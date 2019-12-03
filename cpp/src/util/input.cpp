#include "input.h"
#include <filesystem>
#include <iostream>
#include <string>

namespace aoc {

    input_reader::input_reader()
    {}

    input_reader::input_reader(const std::string& path)
    {
        open(path);
    }

    input_reader::input_reader(const std::string& cwd, const std::string& filename) {
        open(cwd, filename);
    }

    bool input_reader::open(const std::string& path) {
        m_path = path;
        m_in.open(path.c_str(), std::ios::in);
        return m_in.is_open();
    }

    bool input_reader::open(const std::string& cwd, const std::string& filename) {
        std::filesystem::path path(cwd);
        path = path.parent_path() / ".." / ".." / ".." / ".." / ".." / "inputs" / filename;
        m_path = path.string();
        m_in.open(path.c_str());
        return m_in.is_open();
    }

    const std::string& input_reader::path() const {
        return m_path;
    }

    bool input_reader::can_read() const {
        return m_in.is_open();
    }

    bool input_reader::read(int& val) {
        if(m_in >> val) {
            return true;
        }
        return false;
    }

    bool input_reader::read(std::vector<int>& numbers, const char separator) {
        int number;

        if(separator == '\n') {
            while(m_in >> number) {
                numbers.push_back(number);
            }
        } else {
            std::string value;
            while(std::getline(m_in, value, separator)) {
                number = atoi(value.c_str());
                numbers.push_back(number);
            }
        }
        return true;
    }

    bool input_reader::read_line(std::string& out) {
        return !!(m_in >> out);
    }

    void input_reader::reset() {
        m_in.open(m_path.c_str());
    }
}