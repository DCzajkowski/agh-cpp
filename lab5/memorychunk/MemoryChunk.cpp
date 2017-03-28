//
// Created by Dariusz Czajkowski on 28/03/2017.
//

#include "MemoryChunk.h"

using memorychunk::MemoryChunk;

MemoryChunk::MemoryChunk(size_t sz) {
    pointer = (sz == 0) ? nullptr : new int8_t[sz];
}

int8_t * MemoryChunk::MemoryAt(size_t offset) const {
    return (pointer != nullptr && offset != 0) ? pointer + offset : nullptr;
}

size_t MemoryChunk::ChunkSize() const {
    return (pointer != nullptr) ? sizeof(*pointer) : 0;
}

MemoryChunk::~MemoryChunk() {
    if (pointer != nullptr) delete pointer;
}