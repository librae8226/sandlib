#include <curl/curl.h>
#include <stdio.h>
#include <string.h>

CURL *curl;
CURLcode res;
char str[10000000] = {0};

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    if (strlen((char *)stream) + strlen((char *)ptr) > 999999) {
        return 0;
    }
    strcat(stream, (char *)ptr);
    return size*nmemb;
}

int main(int argc, char *argv[])
{
    char url[200];

    curl = curl_easy_init(); //对curl进行初始化

    puts("Input URL:");
    fgets(url, 200, stdin);

    strcpy(str, "");
    curl_easy_setopt(curl, CURLOPT_URL, url); //设置下载地址
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3); //设置超时时间
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); //设置写数据的函数
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, str); //设置写数据的变量
    res = curl_easy_perform(curl); //执行下载

    //判断是否下载成功
    if(CURLE_OK != res) {
        puts("Download failed!");
    }
    else {
        str[9999999] = '\0';

        if (str) {
            puts(str);
        } else {
            puts("Get Error!");
        }
    }

    curl_easy_cleanup(curl); //释放curl资源

    return 0;
}
