set_project("jyhttp")
add_rules("mode.debug", "mode.release")
set_languages("c++20")
add_includedirs("src/include")

local cpp_files = {
    "src/core/*.cpp",
    "src/socket/*.mpp"
}

target("jyhttp")
    set_kind("shared")
    add_files(cpp_files)

target("example_with_lib")
    set_default(false)
    set_kind("binary")
    add_links("jyhttp")
    add_linkdirs("$(buildir)/linux/x86_64/release")
    add_files("example.cpp")
    add_deps("jyhttp")

target("example")
    set_kind("binary")
    set_symbols("debug")
    add_files("example.cpp")
    add_files(cpp_files)

