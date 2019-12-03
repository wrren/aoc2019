set_languages("c++17")

target("utils")
    set_kind("static")
    add_files("src/util/*.cpp")

target("day1")
    set_kind("binary")
    add_files("src/day1/*.cpp")
    add_deps("utils")

target("day2")
    set_kind("binary")
    add_files("src/day2/*.cpp")
    add_deps("utils")

target("day3")
    set_kind("binary")
    add_files("src/day3/*.cpp")
    add_deps("utils")