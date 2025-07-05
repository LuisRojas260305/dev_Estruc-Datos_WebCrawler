#include "../include/Http_client.h"

// Callback para almacenar contenido descargado
static size_t WriteCallback(void *contenido, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contenido, size * nmemb);
    return size * nmemb;
}

std::string Http_client::dowladUrl(std::string url)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            throw std::runtime_error("Error al descargar: " + std::string(curl_easy_strerror(res)));
        }
        curl_easy_cleanup(curl);
    }
    else
    {
        throw std::runtime_error("Error al inicializar cURL");
    }
    return readBuffer;
}