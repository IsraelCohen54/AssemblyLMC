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

	Dict2();
	Dict2(const Dict2& a_other) = delete;
	Dict2& operator=(const Dict2& a_other)=delete;
	~Dict2() = default;

	void Append(itemType a_item);
	void Append(keyType a_key, valType a_val);
	valType Val(keyType a_key);
	size_t Size();

private:
	size_t m_size;
	std::vector<itemType> m_items;

};

} //experis namespace