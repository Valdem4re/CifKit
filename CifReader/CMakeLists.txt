set(CIF_READER_SRCS
    CifReader.cpp
    CifReader.h
)

add_library(CifReader ${CIF_READER_SRCS})

target_link_directories(CifReader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)