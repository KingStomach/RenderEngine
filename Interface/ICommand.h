#pragma once

namespace RenderEngine
{
	class Command
	{
	public:
		virtual void doCommand() = 0;
	};
}