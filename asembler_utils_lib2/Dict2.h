#pragma once
#include <vector>
#include <utility>      // std::pair, std::make_pair
#include <string> 
#include <assert.h>
#include <iostream>

namespace experis
{

using KeyType = std::string;
using ValType = std::string;
using ItemType = std::pair<KeyType, ValType>;

class Dict2
{
public:
	explicit Dict2();
	Dict2(const Dict2& a_other);  // was needed for the return DICT2 func
	Dict2& operator=(const Dict2& a_other)=delete;
	Dict2(const std::vector<ItemType>& a_other);  //for OP dict
	~Dict2() = default;

	void Append(ItemType a_item);
	void Append(KeyType a_key, ValType a_val);
	void PrintDict() const;
	ValType Val(KeyType a_key) const;
	size_t Size() const;

private:
	size_t m_size;
	std::vector<ItemType> m_items;
};

} //experis namespace