#include "pch.h"
#include "Dict2.h"

namespace experis
{

Dict2::Dict2()
	:m_items{}
	,m_size{}
{
}

void Dict2::Append(itemType a_item)
{
	keyType a_key = a_item.first;
	assert(this->Val(a_key) == -1);
	this->m_items.push_back(a_item);
	++m_size;
}

void Dict2::Append(keyType a_key, valType a_val)
{
	assert(this->Val(a_key) == -1);
	itemType a_item = std::make_pair(a_key, a_val);
	this->m_items.push_back(a_item);
	++m_size;
}

valType Dict2::Val(keyType a_key)
{
	for (itemType corrItem : this->m_items)
	{
		if (corrItem.first == a_key)
		{
			return corrItem.second;
		}
	}
	return -1;
}

size_t Dict2::Size()
{
	return this->m_size;
}

} //experis namespace