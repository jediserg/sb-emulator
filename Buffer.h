//
// Created by serg on 8/29/16.
//

#ifndef SB_EMULATOR_BUFFER_H
#define SB_EMULATOR_BUFFER_H


#include <vector>
#include <cstdlib>
#include <stdint.h>
#include <memory>
#include <initializer_list>

class Buffer {
public:
    using Ptr = std::shared_ptr<Buffer>;

    Buffer();
    Buffer(uint16_t kop, std::initializer_list<char> data);
    Buffer(uint16_t kop, const char *data, size_t length);

    char& operator[](size_t index);

    uint16_t getWord(size_t index) const;
    void setWord(size_t index, uint16_t word);

    int getDword(size_t index) const;
    void setDword(size_t index, int dword);

    void pushByte(char b);
    void pushWord(uint16_t w);
    void pushDword(int d);
    void pushStr(std::string s);

    int _kop;
    std::vector<char> m_buffer;

    uint16_t getKop() const;

    void setKop(uint16_t kop);
};

Buffer::Ptr createBuffer8(uint16_t kop, char data);
Buffer::Ptr createBuffer16(uint16_t kop, uint16_t data);
Buffer::Ptr createBuffer32(uint16_t kop, uint16_t data);
Buffer::Ptr createBuffer(uint16_t kop, std::initializer_list<char> data);


#endif //SB_EMULATOR_BUFFER_H
