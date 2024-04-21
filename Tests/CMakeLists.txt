add_executable(Tests
    reading.cpp
)

target_link_libraries(Tests Private CifReader)