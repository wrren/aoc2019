#include "input.h"
#include <filesystem>
#include <iostream>

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
        path = path.parent_path() / ".." / ".." / ".." / ".." / "inputs" / filename;
        m_path = path;
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

    bool input_reader::read(std::vector<int>& numbers) {
        int number;
        while(m_in >> number) {
            numbers.push_back(number);
        }
        return true;
    }
}