#include "genogrove/datatype/Interval.hpp"

namespace genogrove::datatype {
    Interval::Interval() : start(std::string::npos), end(std::string::npos) {}
    Interval::Interval(size_t start, size_t end) : start(start), end(end) {}
    Interval::~Interval() {}

    std::strong_ordering Interval::operator<=>(const Interval& other) const {
        if(this->getStart() == other.getStart()) {
            return this->getEnd() <=> other.getEnd();
        } else {
            return this->getStart() <=> other.getEnd();
        }
    }

    std::string Interval::toString() const {
        return std::to_string(this->start) + "-" + std::to_string(this->end);
    }

    // getter & setter
    size_t Interval::getStart() const { return this->start; }
    void Interval::setStart(size_t start) { this->start = start; }
    size_t Interval::getEnd() const { return this->end; }
    void Interval::setEnd(size_t end) { this->end = end; }

    bool Interval::leftOf(const Interval& other) const {
        return other->getStart() < this->start;
    }

    static bool Interval::overlap(const Interval& intvl1, const Interval& intvl2) const {
        Interval intvl = {std::max(intvl1.getStart(), intvl2.getStart()),
                          }

    }



}
