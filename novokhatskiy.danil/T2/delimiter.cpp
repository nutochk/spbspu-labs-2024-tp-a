#include "delimiter.hpp"

std::istream &novokhatskiy::operator>>(std::istream &in, DelimiterI &&exp)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  char c = 0;
  in >> c;
  if (exp.caseIgnore)
  {
    if (std::tolower(c) != std::tolower(exp.expected))
    {
      in.setstate(std::ios::failbit);
    }
  }
  else if (c != exp.expected)
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}

std::istream &novokhatskiy::operator>>(std::istream &in, StringDelimiterI &&exp)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  for (std::size_t i = 0; exp.expected[i] && in; ++i)
  {
    in >> DelimiterI{exp.expected[i], exp.caseIgnore};
  }
  return in;
}
