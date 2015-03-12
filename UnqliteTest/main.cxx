#include <fstream>
#include <iostream>
#include <string>

extern "C"
{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "unqlite.h"
}

static int VmOutputConsumer(const void *pOutput, unsigned int nOutLen,
		void *pUserData);

int main(int argc, char** argv)
{
	std::cout << "UNQLITE Test." << std::endl;

	int rc;
	unqlite *pDb;
	unqlite_vm *pVm;
	rc = unqlite_open(&pDb, ":mem:", UNQLITE_OPEN_CREATE);
	if(rc != UNQLITE_OK)
	{
		std::cerr << "Cannot open db." << std::endl;
		unqlite_lib_shutdown();
		return 1;
	}

	std::ifstream j9s("j9s.j9", std::ifstream::in);
	std::string line;
	std::string file;
	while(getline(j9s, line))
		file.append(line + '\n');
	file.append("\n");

	j9s.close();

	rc = unqlite_compile(pDb, file.c_str(), sizeof(char)*file.length(), &pVm);
	if(rc != UNQLITE_OK)
	{
		const char* buff;
		int len;
		unqlite_config(pDb, UNQLITE_CONFIG_JX9_ERR_LOG, &buff, &len);
		if(len > 0)
		{
			std::cerr << buff << std::endl;
			unqlite_lib_shutdown();
			return 1;
		}
		else
		{
			std::cerr << "Unqlite fatal error." << std::endl;
			unqlite_lib_shutdown();
			return 1;
		}
	}

	rc = unqlite_vm_config(pVm, UNQLITE_VM_CONFIG_OUTPUT, VmOutputConsumer, 0);
	if(rc != UNQLITE_OK)
	{
		std::cerr << "Fatal Error." << std::endl;
		unqlite_lib_shutdown();
		return 1;
	}

	rc = unqlite_vm_exec(pVm);
	if(rc != UNQLITE_OK)
	{
		std::cerr << "Fatal Error." << std::endl;
		unqlite_lib_shutdown();
		return 1;
	}

	unqlite_vm_release(pVm);
	unqlite_close(pDb);

	return 0;
}

#ifndef STDOUT_FILENO
#define STDOUT_FILENO	1
#endif

static int VmOutputConsumer(const void *pOutput, unsigned int nOutLen,
		void *pUserData)
{
#ifdef __WINNT__
	BOOL rc;
	rc = WriteFile(GetStdHandle(STD_OUTPUT_HANDLE),pOutput,(DWORD)nOutLen,0,0);
	if( !rc )
	{
		/* Abort processing */
		return UNQLITE_ABORT;
	}
#else
	ssize_t nWr;
	nWr = write(STDOUT_FILENO, pOutput, nOutLen);
	if(nWr < 0)
	{
		/* Abort processing */
		return UNQLITE_ABORT;
	}
#endif /* __WINT__ */

	/* All done, data was redirected to STDOUT */
	return UNQLITE_OK;
}
