#pragma once
#include <Windows.h>

HBITMAP GetScreenImg(HWND hWnd, LPRECT lprc)
{
	int cx = lprc->right - lprc->left; // 가로 크기
	int cy = lprc->bottom - lprc->top; // 세로 크기



	HDC hDC = GetDC(hWnd);             // 윈도우 DC핸들을 얻음
	HDC hMemDC = CreateCompatibleDC(hDC);  // 호환되는 메모리DC 생성
	HBITMAP hBitmap = CreateCompatibleBitmap(hDC, cx, cy);//데이터를 저장할 비트맵을 생성
	HBITMAP hBmpOld = (HBITMAP)SelectObject(hMemDC, hBitmap);//메모리DC에 비트맵 연결
	BitBlt(hMemDC, 0, 0, cx, cy, hDC, lprc->left, lprc->top, SRCCOPY); // 비트맵 데이터 복사
	SelectObject(hMemDC, hBmpOld);     // 메모리DC, 비트맵 해제
	DeleteDC(hMemDC);                  // 메모리DC 삭제
	ReleaseDC(hWnd, hDC);              // 윈도우 DC핸들 해제
	return hBitmap;                    // 복사된 비트맵 반환
}



void PutScreenImg(HWND hWnd, int x, int y, HBITMAP hBitmap)
{
	BITMAP bmp;    // 비트맵(hBitmap) 정보를 저장할 공간
	GetObject(hBitmap, sizeof(BITMAP), &bmp);  // 비트맵 정보 구함



	HDC hDC = GetDC(hWnd);             // 윈도우 DC핸들을 얻음
	HDC hMemDC = CreateCompatibleDC(hDC);  // 호환되는 메모리DC 생성
	HBITMAP hBmpOld = (HBITMAP)SelectObject(hMemDC, hBitmap);//메모리DC에 비트맵 연결
	BitBlt(hDC, x, y, bmp.bmWidth, bmp.bmHeight, hMemDC, 0, 0, SRCCOPY);//비트맵데이터 복사
	SelectObject(hMemDC, hBmpOld);     // 메모리DC, 비트맵 해제
	DeleteDC(hMemDC);                  // 메모리DC 삭제
	ReleaseDC(hWnd, hDC);              // 윈도우 DC핸들 해제
}