#include "timer_m.hpp"

namespace timer{
	void timemeasurer::timerstart(){
		_starttime = std::chrono::system_clock::now();
		_isstarted = true;
	}
	void timemeasurer::timerend(){
		if(!_isstarted) throw"EXCEPTION!!";

		_endtime = std::chrono::system_clock::now();
		_isstarted = false;
	}
	long long timemeasurer::result() const{
		const auto resulttime = std::chrono::duration_cast<std::chrono::milliseconds >(_endtime - _starttime);
		return resulttime.count();
	}
}
