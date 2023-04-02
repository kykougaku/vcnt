#ifndef _TIMEMEASURE_H_
#define _TIMEMEASURE_H_

#include<chrono>

namespace timer{
	class timemeasurer{
		public:
			timemeasurer() :_isstarted(false) {};
				~timemeasurer () {};

			void timerstart();
			void timerend();
			long long result() const;

		private:
			std::chrono::system_clock::time_point _starttime, _endtime;
			bool _isstarted;
	};
}
#endif
