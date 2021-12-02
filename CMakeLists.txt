cmake_minimum_required (VERSION 3.8)

project ("advent_of_code")

add_executable (advent_of_code "main.c"  "collections/int_stack.c")
include_directories("week_one")
include_directories("collections")
include_directories("collections/templates")
