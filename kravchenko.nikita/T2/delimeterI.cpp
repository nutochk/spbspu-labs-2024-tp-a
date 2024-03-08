#include "delimeterI.hpp"

std::istream& kravchenko::delimeterI::operator>>(std::istream& in, delimeterI::DelimeterI&& exp)
{
	std::istream::sentry sentry(in);
	if (!sentry)
	{
		return in;
	}
	char c = 0;
	in >> c;
	if (c != exp.expected)
	{
		in.setstate(std::ios::failbit);
	}
	return in;
}