set_project("jyhttp")
add_rules("mode.debug", "mode.release")
set_languages("c++20")
-- add_cxxflags("-fmodules-ts")
-- add_moduledirs("modules")
add_includedirs("src/include")

local cpp_files = {
    "src/core/*.cpp",
}

local mpp_files = {
    "src/socket/*.mpp"
}

target("jyhttp")
    set_kind("shared")
    add_files(cpp_files)
    add_files(mpp_files, {public = true})
target("example_with_lib")
    set_kind("binary")
    add_links("jyhttp")
    add_linkdirs("$(buildir)/linux/x86_64/release")
    add_files("example.cpp")
    add_deps("jyhttp")
target("example")
    set_default(true)
    set_kind("binary")
    set_symbols("debug")
    add_files("example.cpp")
    add_files(cpp_files)
    add_files(mpp_files, {public = true})
