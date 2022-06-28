#include <windows.h>

LRESULT CALLBACK mouse_event_callback(int code, WPARAM w, LPARAM l) {
	return 1;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	HHOOK hook = SetWindowsHookEx(WH_MOUSE_LL, mouse_event_callback, GetModuleHandle(0), 0);
	while (1) {
		Sleep(5);
		// Low-level Windows hooks seem to have some sort of undocumented timeout (https://stackoverflow.com/questions/2655278/what-can-cause-windows-to-unhook-a-low-level-global-keyboard-hook).
		// So reinstall the hook every 30 seconds to hopefully stop this from breaking.
		DWORD start_time = GetTickCount();
		while (GetTickCount() < (start_time + 30000)) {
			Sleep(5);
		}
		UnhookWindowsHookEx(hook);
		hook = SetWindowsHookEx(WH_MOUSE_LL, kbhcallback, GetModuleHandle(0), 0);
	}
	return 0;
}
