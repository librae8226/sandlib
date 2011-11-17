#ifndef __SHM_COM_H__
#define __SHM_COM_H__

#define MEM_SZ	4096
#define BUF_SZ	16

struct shared_use_st {
	int written_by_you;
	char some_text[BUF_SZ];
};

#endif
