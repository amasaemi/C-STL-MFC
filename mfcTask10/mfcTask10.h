
// mfcTask10.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CmfcTask10App:
// Сведения о реализации этого класса: mfcTask10.cpp
//

class CmfcTask10App : public CWinApp
{
public:
	CmfcTask10App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CmfcTask10App theApp;
