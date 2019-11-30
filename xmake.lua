target("utils")
    set_kind("static")
    add_files("src/utils/*.cpp")

target("day1")
    set_kind("binary")
    add_files("src/day1/*.cpp")
    add_deps("utils")