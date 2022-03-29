#pragma once
#include <string>
#include <vector>
#include "json/json.h"


inline bool json_from_str(int& i, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || root.isArray())
		return false;
	if (root.isInt())
	{
		i = root.asInt();
		return true;
	}
	else
		return false;
}


inline bool json_from_str(unsigned int& ui, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || root.isArray())
		return false;
	if (root.isUInt())
	{
		ui = root.asUInt();
		return true;
	}
	else
		return false;
}


inline bool json_from_str(double& d, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || root.isArray())
		return false;
	if (root.isDouble())
	{
		d = root.asDouble();
		return true;
	}
	else
		return false;
}


inline bool json_from_str(bool& b, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || root.isArray())
		return false;
	if (root.isBool())
	{
		b = root.asBool();
		return true;
	}
	else
		return false;
}


inline bool json_from_str(std::string& str, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || root.isArray())
		return false;
	if (root.isString())
	{
		str = root.asString();
		return true;
	}
	else
		return false;
}


inline bool json_from_str(std::vector<int>& is, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || !root.isArray())// || 0 == root.size())
		return false;
	for (unsigned int i = 0; i < root.size(); ++i)
	{
		if (!root[i].isInt())
			return false;
		is.emplace_back(root[i].asInt());
	}
	return true;
}


inline bool json_from_str(std::vector<unsigned int>& uis, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || !root.isArray())// || 0 == root.size())
		return false;
	for (unsigned int i = 0; i < root.size(); ++i)
	{
		if (!root[i].isUInt())
			return false;
		uis.emplace_back(root[i].asUInt());
	}
	return true;
}


inline bool json_from_str(std::vector<double>& ds, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || !root.isArray())// || 0 == root.size())
		return false;
	for (unsigned int i = 0; i < root.size(); ++i)
	{
		if (!root[i].isDouble())
			return false;
		ds.emplace_back(root[i].asDouble());
	}
	return true;
}


inline bool json_from_str(std::vector<bool>& bs, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || !root.isArray())// || 0 == root.size())
		return false;
	for (unsigned int i = 0; i < root.size(); ++i)
	{
		if (!root[i].isBool())
			return false;
		bs.emplace_back(root[i].asBool());
	}
	return true;
}


inline bool json_from_str(std::vector<std::string>& strs, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || !root.isArray())// || 0 == root.size())
		return false;
	for (unsigned int i = 0; i < root.size(); ++i)
	{
		if (!root[i].isString())
			return false;
		strs.emplace_back(root[i].asString());
	}
	return true;
}


template <typename T>
inline bool json_from_str(std::vector<T>& v1, const Json::Value& root)
{
	if (root.isNull() || root.isObject() || !root.isArray()) //|| 0 == root.size())
		return false;
	for (unsigned int i = 0; i < root.size(); ++i)
	{
		T t;
		if (!json_from_str(t, root[i]))
			return false;
		v1.emplace_back(t);
	}
	return true;
}


inline Json::Value json_to_str_imp(int i)
{
	Json::Value root = i;
	return std::move(root);
}


inline Json::Value json_to_str_imp(unsigned int ui)
{
	Json::Value root = ui;
	return std::move(root);
}


inline Json::Value json_to_str_imp(double d)
{
	Json::Value root = d;
	return std::move(root);
}


inline Json::Value json_to_str_imp(bool b)
{
	Json::Value root = b;
	return std::move(root);
}


inline Json::Value json_to_str_imp(const std::string& str)
{
	Json::Value root = str;
	return std::move(root);
}


inline Json::Value json_to_str_imp(const std::vector<int>& is)
{
	Json::Value root = Json::ValueType::arrayValue;
	if (is.empty())
		root.resize(0);
	else
	{
		for (auto value : is)
		{
			root.append(value);
		}
	}
	return std::move(root);
}


inline Json::Value json_to_str_imp(const std::vector<unsigned int>& uis)
{
	Json::Value root = Json::ValueType::arrayValue;
	if (uis.empty())
		root.resize(0); 
	else
	{
		for (auto value : uis)
		{
			root.append(value);
		}
	}
	return std::move(root);
}


inline Json::Value json_to_str_imp(const std::vector<double>& ds)
{
	Json::Value root = Json::ValueType::arrayValue;
	if (ds.empty())
		root.resize(0);
	else
	{
		for (auto value : ds)
		{
			root.append(value);
		}
	}
	return std::move(root);
}


inline Json::Value json_to_str_imp(const std::vector<bool>& bs)
{
	Json::Value root = Json::ValueType::arrayValue;
	if (bs.empty())
		root.resize(0);
	else
	{
		for (auto value : bs)
		{
			bool b = value;
			root.append(b);
		}
	}
	return std::move(root);
}


inline Json::Value json_to_str_imp(const std::vector<std::string>& strs)
{
	Json::Value root = Json::ValueType::arrayValue;
	if (strs.empty())
		root.resize(0);
	else
	{
		for (auto value : strs)
		{
			root.append(value);
		}
	}
	return std::move(root);
}


template <typename T>
inline Json::Value json_to_str_imp(const std::vector<T>& v1)
{
	Json::Value root = Json::ValueType::arrayValue;
	if (v1.empty())
		root.resize(0);
	else
	{
		for (int i = 0; i < v1.size(); ++i)
		{
			Json::Value value = json_to_str_imp(v1[i]);
			root.append(value);
		}
	}
	return std::move(root);
}
