set(CIF_FILE_SOURCES
    CifFile.cpp
    CifFile.h
)

add_library(CifFile ${CIF_FILE_SOURCES})

target_link_directories(CifFile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)