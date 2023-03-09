#pragma once
#define Interface class

#define DISALLOW_COPY_AND_MOVE(type)\
type(const type&) = delete;\
type(const type&&) = delete;\
type operator=(const type&) = delete;\
type operator=(const type&&)=delete;