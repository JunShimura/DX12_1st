#include<Windows.h>
#ifdef  _DEBUG
#include <iostream>
#endif

using namespace std;

// @brief コンソール画面にフォーマット付き文字列を表示
// @param format フォーマット（%d とか%f とかの）
// @param 可変長変数
// @remarks この関数はデバッグ用です。デバッグ時にしか動作しません

void DenugOutputFormatString(const char* format, ...) {
#ifdef _DEBUG
	va_list valist;
	va_start(valist, format);
	printf(format, valist);
#endif
}

//面倒だけど書かなければならない関数
LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	// ウィンドウが破棄されたら呼ばれる
	if (msg == WM_QUIT) {
		PostQuitMessage(0);	// OSに対して「もうこのアプリは終わる」と伝える
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);	// 既定の処理を行う
}


#ifdef _DEBUG
int main()
{
#else
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ウィンドウクラスの生成
	WNDCLASSEX w = {};


#endif
	DenugOutputFormatString("Show window test.");
	getchar();
	return 0;
}