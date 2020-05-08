//
// Created by jojo on 2020/5/3.
//

#include "Buffer.h"

Buffer::Buffer():
	_buffer(BUFFER_SIZE),
	_reader_index(0),
	_writer_index(0)
{
	assert(Readable_Bytes() == 0);
	assert(Writable_Bytes() == BUFFER_SIZE);
}


Buffer::~Buffer()
{
}

