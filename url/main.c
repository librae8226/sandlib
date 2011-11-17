#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BD_RET_OK   0
#define BDOS_STRNCPY strncpy

typedef char TCHAR;
typedef unsigned int TUINT32;
typedef int BD_RET_CODE;

int main(int argc, char *argv[])
{
	BD_RET_CODE r = BD_RET_OK;
	char url[1024];
	char host[1024];

	fgets(url, 200, stdin);
	r = solsmpccmdsPickHostname(url, host);
	if (host)
	{
		puts(host);
	}
	else
	{
		puts("error");
	}

	return 0;
}

BD_RET_CODE solsmpccmdsPickHostname(TCHAR *in_url, TCHAR *out_host)
{
	BD_RET_CODE r = BD_RET_OK;
	TUINT32 i = 0;
	TUINT32 cnt_splash = 0;
	TCHAR *ptr1 = in_url;
	TCHAR *ptr2 = NULL;
	TUINT32 len = 0;

	while (ptr1)
	{
		if ('/' == *ptr1)
		{
			cnt_splash += 1;
			if (2 == cnt_splash)
			{
				break;
			}
		}
		ptr1++;
	}

	ptr2 = ++ptr1;
	while (ptr2++)
	{
		if ('/' == *ptr2)
		{
			break;
		}
	}

	len = ptr2 - ptr1;
	BDOS_STRNCPY(out_host, ptr1, len);
	*(out_host + len + 1) = '\0';

	return r;
}

