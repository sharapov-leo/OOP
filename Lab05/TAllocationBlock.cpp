/* 
 * File:   TAllocationBlock.cpp
 * Author: dvdemon
 * 
 * Created on July 28, 2015, 9:17 AM
 */

#include "TAllocationBlock.h"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size,size_t count): _size(size),_count(count)  {
    _used_blocks = (char*)malloc(_size*_count);
	for (size_t i = 0; i < _count; ++i)
		_free_blocks.push(_used_blocks + i * _size);

    _free_count = _count;
      std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void *TAllocationBlock::allocate() {
    void *result = nullptr;
    
    if(_free_count>0)
    {
		TIteratorStack it(_free_blocks.begin());
		for (size_t i = 0; i < _free_count - 1; ++i) {
			++it;
		}
		result = *it;

        _free_count--;
        std::cout << "TAllocationBlock: Allocate " << (_count-_free_count) << " of " << _count << std::endl;
    } else
    {
        std::cout << "TAllocationBlock: Memory exception" << std::endl;
        throw 1;
    }
    
    return result;
}

void TAllocationBlock::deallocate(void *pointer) {
  std::cout << "TAllocationBlock: Deallocate block "<< std::endl;
    
  TIteratorStack it(_free_blocks.begin());
  for (size_t i = 0; i < _free_count; ++i)
	  ++it;
  it = pointer;

  _free_count ++;

}

bool TAllocationBlock::has_free_blocks() {
    return _free_count>0;
}

TAllocationBlock::~TAllocationBlock() {
    
    if(_free_count<_count) std::cout << "TAllocationBlock: Memory leak" << std::endl;
                    else  std::cout << "TAllocationBlock: Memory freed" << std::endl;
    delete _used_blocks;
}




