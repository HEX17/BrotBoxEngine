#pragma once

#include <chrono>

namespace bbe
{
	class GameTime
	{
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_gameStartTimestamp;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_lastTickTimestamp;

	public:
		GameTime();

		float tick();
		float timeSinceStartSeconds();
		float timeSinceStartMilliseconds();
		void reset();
	};
}
