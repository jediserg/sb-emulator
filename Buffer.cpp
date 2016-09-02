//
// Created by serg on 8/29/16.
//

#include "Buffer.h"

Buffer::Buffer() {

}

Buffer::Buffer(uint16_t kop, const char *data, size_t length)
    : _kop(kop), m_buffer(data, data + length)
{
}

uint16_t Buffer::getKop() const {
    return _kop;
}

void Buffer::setKop(uint16_t kop) {
    _kop = kop;
}

char &Buffer::operator[](size_t index) {
    return m_buffer[index];
}

uint16_t Buffer::getWord(size_t index) const {
    return *reinterpret_cast<const uint16_t *>(m_buffer.data() + index * 2);
}

void Buffer::setWord(size_t index, uint16_t word) {
    *reinterpret_cast<uint16_t *>(m_buffer.data() + index * 2) = word;
}

int Buffer::getDword(size_t index) const {
    return *reinterpret_cast<const int*>(m_buffer.data() + index * 4);
}

void Buffer::setDword(size_t index, int dword) {
    *reinterpret_cast<int*>(m_buffer.data() + index * 4) = dword;
}

void Buffer::pushStr(std::string s) {

}

void Buffer::pushByte(char b) {

}

void Buffer::pushWord(uint16_t w) {

}

void Buffer::pushDword(int d) {

}

Buffer::Buffer(uint16_t kop, std::initializer_list<char> data)
    : _kop(kop), m_buffer(data.begin(), data.end())
{

}

Buffer::Ptr createBuffer8(uint16_t kop, char data) {
    return std::make_shared<Buffer>(kop, &data, 1);
}

Buffer::Ptr createBuffer16(uint16_t kop, uint16_t data) {
    return std::make_shared<Buffer>(kop, reinterpret_cast<char*>(&data), 2);
}

Buffer::Ptr createBuffer32(uint16_t kop, uint16_t data) {
    return std::make_shared<Buffer>(kop, reinterpret_cast<char*>(&data), 4);
}

Buffer::Ptr createBuffer(uint16_t kop, std::initializer_list<char> data) {
    return std::make_shared<Buffer>(kop, data);
}

