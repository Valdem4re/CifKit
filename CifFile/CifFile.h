#ifndef CIFFILE
#define CIFFILE

#include <string>
#include <vector>
#include <sstream>

#define MAX_ROW_LEN 80

using std::string;
using std::vector;


namespace CIF
{
    
    enum ContentType {
        NONE,
        WORD,
        ROW,
        TEXT,
        TABLE
    };

    class File;
    class Item;
    class Loop;
    class Block;

    class Item {
        /*This class describes a Cif file element (tag - value pair)*/
        public:

        Item() : type_(NONE) {};

        Item(const string& tag, const string& val, const ContentType type) :
         tag_(tag), value_(val), type_(type) {};
        
        string removeESD() const;

        double toDouble() const;

        inline bool hasSpaces() const;

        inline bool hasLines() const;

        inline bool checkTag(const string& tag);

        friend std::ostream& operator<<(std::ostream& out, const Item& item) {
            switch (item.type_) {
                case WORD:
                out << item.tag_ << "\t" << item.value_;
                break;
                case ROW:
                out << item.tag_ << "\t\'" << item.value_ << "\'";
                break;
                case TEXT:
                out << item.tag_ << "\n;\n" << item.value_ << "\n;";
                break;
                default:
                out << item.tag_ << "\t" << item.value_;
                break;
            }
            return out;
        }

        private:
        ContentType type_;
        string tag_;
        string value_;
    };

    class Loop {
    /*This class describes tables under the loop_ tag*/
        public:
        Loop() = default;

        void clear();

        string& operator()(const int i, const int j);

        void addRow(const vector<string>& row);

        inline int rows() const;

        inline int cols() const;

        inline vector<string>& getRow(const int index);

        // TODO: add loop filling functions

        private:
        vector<string> header_;
        vector<vector<string>> data_;
    };

} // namespace CIF
#endif