#pragma once

#define DISALLOW_COPY_AND_MOVE(type)\
type(const type&) = delete;\
type(const type&&) = delete;\
type operator=(const type&) = delete;\
type operator=(const type&&)=delete;

#define GET_METHOD(type, name, variable)\
const type& get##name() const { return this->variable; }

#define SET_METHOD(type, name, variable)\
void set##name(const type& name) { this->variable = name; }

#define GET_AND_SET_METHOD(type, name, variable)\
GET_METHOD(type, name, variable)\
SET_METHOD(type, name, variable)

#define GET_CLASS_NAME(name)\
std::string getClassName() const { return std::string(#name); }

namespace RenderEngine
{
	template <class T>
	class Single
	{
	public:
		virtual ~Single() {}

		static T& instance()
		{
			static T t;
			return t;
		}
	protected:
		Single() {};
	private:
		DISALLOW_COPY_AND_MOVE(Single)
	};
}

#ifdef GAME_ENGINE_ASSERT_ENABLE
inline void render_engine_assert(bool expression) { if (expression) __debugbreak(); }
#else
inline void render_engine_assert() {}
#endif // GAME_ENGINE_ASSERT_ENABLE
