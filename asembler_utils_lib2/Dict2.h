#pragma once
#include <vector>
#include <utility>      // std::pair, std::make_pair
#include <string> 
#include <assert.h>

namespace experis
{

using keyType = std::string;
using valType = int;
using itemType = std::pair<keyType, valType>;

class Dict2
{
public:
	// TODO [ar] uneeded enter
	explicit Dict2();  //todo [ar] explicit...
	Dict2(const Dict2& a_other);  // was needed for the return DICT2 func
	Dict2& operator=(const Dict2& a_other)=delete;
	~Dict2() = default;

	void Append(itemType a_item);
	void Append(keyType a_key, valType a_val);
	valType Val(keyType a_key);
	size_t Size();

private:
	size_t m_size; // TODO [ar] consider change from size_t to int, as it isn't a size but an index, and propriate to append counter used at line 92 at read_assembler.cpp
	std::vector<itemType> m_items;
	// TODO [ar] uneeded enter
};

} //experis namespace