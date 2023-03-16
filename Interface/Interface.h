#pragma once

#define DISALLOW_COPY_AND_MOVE(type)\
type(const type&) = delete;\
type(const type&&) = delete;\
type operator=(const type&) = delete;\
type operator=(const type&&)=delete;

#define GET_AND_SET_METHOD(type, name, variable)\
const type& get##name() const { return this->variable; }\
void set##name(const type& name) { this->variable = name; }

#define GET_CLASS_NAME(name)\
std::string getClassName() const { return std::string(#name); }