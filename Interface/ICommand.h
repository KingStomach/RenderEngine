#pragma once
#include <memory>

namespace RenderEngine
{
	enum class CommandType : char { MODULE_COMMAND, RENDER_COMMAND };

	class ICommand
	{
	public:
		explicit ICommand(CommandType type) : m_type(type) {};
		virtual ~ICommand() {};
		virtual std::unique_ptr<ICommand> Clone() const = 0;
		CommandType getType() const { return m_type; }
	private:
		CommandType m_type;
	};

	template <class Derived>
	class Command : public ICommand
	{
	public:
		explicit Command(CommandType type) : ICommand(type) {};
		virtual ~Command() {};
		std::unique_ptr<ICommand> Clone() const override { return static_cast<const Derived*>(this)->CloneImpl(); };
		void doCommand() const { static_cast<const Derived*>(this)->doCommandImpl(); }
	protected:
		using BaseCommand = Command<Derived>;
	};
}