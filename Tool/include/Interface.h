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

#define DECLARE_CLASS(Space, Class) \
namespace Space { class Class; };

#define MATCH_MODULE_AND_COMMAND(Space, Module, Command) \
DECLARE_CLASS(Space, Module) \
namespace RenderEngine { template<> struct is_moudle_command_match<Space::Module, Space::Command> : std::true_type {}; }

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
