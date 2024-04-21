#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
    
class CifReader {
    public:

        CifReader() : input_stream(0), remove_(false), eof_(false){};

        CifReader(const std::string& path);

        CifReader(const std::istream& input);

        ~CifReader();


        void open(const std::istream& input);

        void open(const std::string& path);

        void close();
    private:
        std::queue<std::string> buffer_;
        bool eof_;
        bool remove_;
        std::istream* input_stream;
};


class Item {

};

class Loop {

};

class Block {
    
};

class File {

};
