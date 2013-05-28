#ifndef __LIB_I2C_DBG_H__
#define __LIB_I2C_DBG_H__

#ifndef LOG_TAG
# define LOG_TAG   "i2cdev"
#endif

#if defined (ANDROID)
# include <cutils/log.h>
#else
# define SLOGE(msg, args...) \
	do { \
		printf("[%s] " msg, __func__, ##args); \
	} while (0)
# define SLOGI(msg, args...) \
	do { \
		printf("[%s] " msg, __func__, ##args); \
	} while (0)
# define SLOGD(msg, args...) \
	do { \
	} while (0)
#endif

#endif
