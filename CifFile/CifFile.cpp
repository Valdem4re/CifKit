#include "CifFile.h"

using namespace CIF;

string Item::removeESD() const {
    int pos = value_.find('(');
    if (pos != string::npos) {
        return value_.substr(0, pos);
    }
    return value_;
}

double Item::toDouble() const {
    std::stringstream ss(removeESD());
    int res;
    if (!ss >> res) {
        throw std::runtime_error("Invalid double conversation");
    }
    return res;
}

inline bool Item::hasSpaces() const {
    return value_.find(' ') != string::npos ||
    value_.find('\t') != string::npos;
}

inline bool Item::hasLines() const {
    return value_.find('\n') != string::npos;
}

inline bool Item::checkTag(const string& tag) {
    return tag_ == tag;
}

//--------------------------------------------------------------------------------

void Loop::clear() {
    header_.clear();
    data_.clear();
}

string& Loop::operator()(const int i, const int j) {
    return data_[i][j];
}

void Loop::addRow(const vector<string>& row) {
    if (row.size() == 0) {
        vector<string> row(header_.size());
    }
    data_.push_back(row);
}

inline int Loop::rows() const {
    return data_.size();
}

inline int Loop::cols() const {
    return data_.empty() ? 0 : data_[0].size(); 
}

inline vector<string>& Loop::getRow(const int index) {
    return data_[index];
}