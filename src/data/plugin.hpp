#pragma once
// Keeps track of global state like is enabled
//

using namespace std;
using namespace RE;
using namespace SKSE;
using namespace std::literals;

namespace Gts {
	class Plugin {
		public:
			static bool Enabled();
			static bool InGame();
			static bool Ready();
			static bool Live();
			static void SetInGame(bool value);
			static bool OnMainThread();
			static void SetOnMainThread(bool value);

			static inline constexpr REL::Version VERSION{
				// clang-format off
				2u,
				0u,
				0u,
				// clang-format on
			};

			static inline constexpr auto NAME = "GTSPlugin"sv;

		private:
			[[nodiscard]] static Plugin& GetSingleton();
			std::atomic_bool enabled = std::atomic_bool(true);
			std::atomic_bool ingame = std::atomic_bool(false);
			std::atomic_bool onmainthread = std::atomic_bool(false);
	};
}
