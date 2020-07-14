#include<Windows.h>
#ifdef  _DEBUG
#include <iostream>
#endif

using namespace std;

// @brief �R���\�[����ʂɃt�H�[�}�b�g�t���������\��
// @param format �t�H�[�}�b�g�i%d �Ƃ�%f �Ƃ��́j
// @param �ϒ��ϐ�
// @remarks ���̊֐��̓f�o�b�O�p�ł��B�f�o�b�O���ɂ������삵�܂���

void DenugOutputFormatString(const char* format, ...) {
#ifdef _DEBUG
	va_list valist;
	va_start(valist, format);
	printf(format, valist);
#endif
}

//�ʓ|�����Ǐ����Ȃ���΂Ȃ�Ȃ��֐�
LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	// �E�B���h�E���j�����ꂽ��Ă΂��
	if (msg == WM_QUIT) {
		PostQuitMessage(0);	// OS�ɑ΂��āu�������̃A�v���͏I���v�Ɠ`����
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);	// ����̏������s��
}


#ifdef _DEBUG
int main()
{
#else
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �E�B���h�E�N���X�̐���
	WNDCLASSEX w = {};


#endif
	DenugOutputFormatString("Show window test.");
	getchar();
	return 0;
}