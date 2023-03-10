#pragma once

#define DISALLOW_COPY_AND_MOVE(type)\
type(const type&) = delete;\
type(const type&&) = delete;\
type operator=(const type&) = delete;\
type operator=(const type&&)=delete;

#define GET_AND_SET_METHOD(type, name1, name2)\
const type& get##name1() const { return this->name2; }\
void set##name1(const type& name1) { this->name2 = name1; }