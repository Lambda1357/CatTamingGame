#pragma once
#include <Windows.h>

HBITMAP GetScreenImg(HWND hWnd, LPRECT lprc)
{
	int cx = lprc->right - lprc->left; // ���� ũ��
	int cy = lprc->bottom - lprc->top; // ���� ũ��



	HDC hDC = GetDC(hWnd);             // ������ DC�ڵ��� ����
	HDC hMemDC = CreateCompatibleDC(hDC);  // ȣȯ�Ǵ� �޸�DC ����
	HBITMAP hBitmap = CreateCompatibleBitmap(hDC, cx, cy);//�����͸� ������ ��Ʈ���� ����
	HBITMAP hBmpOld = (HBITMAP)SelectObject(hMemDC, hBitmap);//�޸�DC�� ��Ʈ�� ����
	BitBlt(hMemDC, 0, 0, cx, cy, hDC, lprc->left, lprc->top, SRCCOPY); // ��Ʈ�� ������ ����
	SelectObject(hMemDC, hBmpOld);     // �޸�DC, ��Ʈ�� ����
	DeleteDC(hMemDC);                  // �޸�DC ����
	ReleaseDC(hWnd, hDC);              // ������ DC�ڵ� ����
	return hBitmap;                    // ����� ��Ʈ�� ��ȯ
}



void PutScreenImg(HWND hWnd, int x, int y, HBITMAP hBitmap)
{
	BITMAP bmp;    // ��Ʈ��(hBitmap) ������ ������ ����
	GetObject(hBitmap, sizeof(BITMAP), &bmp);  // ��Ʈ�� ���� ����



	HDC hDC = GetDC(hWnd);             // ������ DC�ڵ��� ����
	HDC hMemDC = CreateCompatibleDC(hDC);  // ȣȯ�Ǵ� �޸�DC ����
	HBITMAP hBmpOld = (HBITMAP)SelectObject(hMemDC, hBitmap);//�޸�DC�� ��Ʈ�� ����
	BitBlt(hDC, x, y, bmp.bmWidth, bmp.bmHeight, hMemDC, 0, 0, SRCCOPY);//��Ʈ�ʵ����� ����
	SelectObject(hMemDC, hBmpOld);     // �޸�DC, ��Ʈ�� ����
	DeleteDC(hMemDC);                  // �޸�DC ����
	ReleaseDC(hWnd, hDC);              // ������ DC�ڵ� ����
}