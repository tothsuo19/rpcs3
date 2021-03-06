#pragma once

class LogWriter
{
	rFile m_logfile;

	void WriteToLog(const std::string& prefix, const std::string& value, u8 lvl);

public:
	LogWriter();

	template <typename ...Arg>
	void Write(const std::string &fmt, Arg... args)
	{
		std::string frmt = fmt::Format(fmt, std::forward<Arg>(args)...);
		WriteToLog("!", frmt, 2);
	}

	template <typename ...Arg>
	void Error(const std::string &fmt, Arg... args)
	{
		std::string frmt = fmt::Format(fmt, std::forward<Arg>(args)...);
		WriteToLog("E", frmt, 4);
	}

	template <typename ...Arg>
	void Warning(const std::string &fmt, Arg... args)
	{
		std::string frmt = fmt::Format(fmt, std::forward<Arg>(args)...);
		WriteToLog("W", frmt, 3);
	}

	template <typename ...Arg>
	void Success(const std::string &fmt, Arg... args)
	{
		std::string frmt = fmt::Format(fmt, std::forward<Arg>(args)...);
		WriteToLog("S", frmt, 1);
	}

	virtual void SkipLn();
};


extern LogWriter ConLog;
