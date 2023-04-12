#include "pch.h"
#include "Dict2.h"

namespace experis
{

Dict2::Dict2()
: m_items{}
, m_size{}
{
}

void Dict2::Append(ItemType a_item)
{
	KeyType a_key = a_item.first;
	assert(this->Val(a_key) == "-1");
	this->m_items.push_back(a_item);
	++m_size;
}

Dict2::Dict2(const Dict2& a_other)
: m_size{a_other.m_size}
, m_items{a_other.m_items}
{
}

void Dict2::Append(KeyType a_key, ValType a_val)
{
	assert(this->Val(a_key) == "-1");
	ItemType a_item = std::make_pair(a_key, a_val);
	this->m_items.push_back(a_item);
	++m_size;
}

Dict2::Dict2(const std::vector<ItemType>& a_other)
:m_items{a_other}
,m_size{a_other.size()}
{

}
void Dict2::PrintDict() const
{
	for (ItemType corrItem : this->m_items)
	{
		std::cout<<(corrItem.first)<<"->"<<corrItem.second<< "\n";

	}
}

ValType Dict2::Val(KeyType a_key) const
{
	for (ItemType corrItem : this->m_items)
	{
		if (corrItem.first == a_key)
		{
			return corrItem.second;
		}
	}
	return "-1";
}

size_t Dict2::Size() const
{
	return this->m_size;
}

} //experis namespace