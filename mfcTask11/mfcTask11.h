
// mfcTask11.h: основной файл заголовка для приложения mfcTask11
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CmfcTask11App:
// Сведения о реализации этого класса: mfcTask11.cpp
//

class CmfcTask11App : public CWinApp
{
public:
	CmfcTask11App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
    virtual BOOL OnIdle(LONG lCount);
};

extern CmfcTask11App theApp;
