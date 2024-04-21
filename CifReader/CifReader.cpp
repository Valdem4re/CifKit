#include "CifReader.h"

CifReader::CifReader(const std::string& path) {
    input_stream_ = new std::ifstream(path);
    remove_ = true;
    if (input_stream_->bad())
        eof_ = true;
    else
        eof_ = false;
};

CifReader::CifReader(std::istream& input) {
    input_stream_ = &input;
    remove_ = false;
    eof_ = false;
};

CifReader::~CifReader() {
    if (input_stream_ && remove_)
        delete input_stream_;
}

void CifReader::open(std::istream& input) {
    close();
    input_stream_ = &input;
    remove_ = false;
    eof_ = false;
}