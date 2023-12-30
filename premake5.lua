workspace "InfosecLabs"
    configurations { "Debug", "Release" }
    location "build"

project "KeyEncryption"
    kind "ConsoleApp"
    language "C++"
    location "build/key_encryption"
    files {
        "key_encryption/**.h",
        "key_encryption/**.hpp",
        "key_encryption/**.cpp"
    }
    includedirs { "key_encryption/include" }
    links { "ModularMathLib" }

project "KeyFinder"
    kind "ConsoleApp"
    language "C++"
    location "build/key_finder"
    files {
        "key_finder/**.h",
        "key_finder/**.hpp",
        "key_finder/**.cpp"
    }
    includedirs { "key_finder/include" }
    links { "ModularMathLib" }

project "ModularMathLibTests"
    kind "ConsoleApp"
    language "C++"
    location "build/modular_math_lib_tests"
    files { "modular_math_lib_tests/main.cpp" }
    links { "ModularMathLib" }

project "ModularMathLib"
    kind "StaticLib"
    language "C++"
    location "build/modular_math_lib"
    files {
        "modular_math_lib/**.h",
        "modular_math_lib/**.cpp"
    }
    includedirs { "modular_math_lib/include" }
