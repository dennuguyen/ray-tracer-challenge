#include "alphabet.hpp"

namespace alphabet {
Letter::Letter(std::vector<std::pair<uint, uint>> data_) : data(data_) {}
Letter::~Letter() {}
}  // namespace alphabet