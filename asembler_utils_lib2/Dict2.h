#pragma once
#include <vector>
#include <utility>      // std::pair, std::make_pair
#include <string> 
#include <assert.h>
#include <iostream>

namespace experis
{

using keyType = std::string;
using valType = size_t;
using itemType = std::pair<keyType, valType>;

class Dict2
{
public:
	explicit Dict2();
	Dict2(const Dict2& a_other);  // was needed for the return DICT2 func
	Dict2& operator=(const Dict2& a_other)=delete;
	Dict2(const std::vector<itemType>& a_other);  //for OP dict
	~Dict2() = default;

	void Append(itemType a_item);
	void Append(keyType a_key, valType a_val);
	void PrintDict() const;
	valType Val(keyType a_key) const;
	size_t Size() const;

private:
	size_t m_size;
	std::vector<itemType> m_items;
};

} //experis namespace