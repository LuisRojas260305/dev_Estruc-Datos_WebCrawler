#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include <vector>
#include <string>
#include <regex>

class Html_parser
{
public:
    static std::vector<std::string> extraerLinks(std::string html, std::string url);
};

#endif // HTML_PARSER_H