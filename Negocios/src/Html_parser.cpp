#include "../include/Html_parser.h"

std::vector<std::string> Html_parser::extraerLinks(std::string html, std::string baseUrl)
{

    std::vector<std::string> links;

    std::regex Link_regex("<a\\s+[^>]*href=\"([^\"]*)\"[^>]*>", std::regex_constants::icase);

    auto words_begin = std::sregex_iterator(html.begin(), html.end(), Link_regex);

    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string link = match[1].str();

        // Convertir enlaces relativos a absolutos
        if (link.find("http") != 0)
        {
            if (baseUrl.back() != '/')
                baseUrl += '/';
            if (link.front() == '/')
                link = link.substr(1);
            link = baseUrl + link;
        }
        links.push_back(link);
    }

    return links;
}