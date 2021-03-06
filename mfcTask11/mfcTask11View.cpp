
// mfcTask11View.cpp: реализация класса CmfcTask11View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "mfcTask11.h"
#endif

#include "mfcTask11Doc.h"
#include "mfcTask11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcTask11View

IMPLEMENT_DYNCREATE(CmfcTask11View, CFormView)

BEGIN_MESSAGE_MAP(CmfcTask11View, CFormView)
END_MESSAGE_MAP()

// Создание или уничтожение CmfcTask11View

CmfcTask11View::CmfcTask11View()
	: CFormView(IDD_MFCTASK11_FORM)
    , m_EnableTask1Check(FALSE)
    , m_EnableTask2Check(FALSE)
    , m_Task1Edit(0)
    , m_Task2Edit(0)
{
	// TODO: добавьте код создания

}

CmfcTask11View::~CmfcTask11View()
{
}

void CmfcTask11View::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    DDX_Check(pDX, IDC_CHECK1, m_EnableTask1Check);
    DDX_Check(pDX, IDC_CHECK2, m_EnableTask2Check);
    DDX_Text(pDX, IDC_EDIT1, m_Task1Edit);
    DDX_Text(pDX, IDC_EDIT2, m_Task2Edit);
}

BOOL CmfcTask11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CmfcTask11View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
    m_EnableTask1Check = TRUE;
    m_EnableTask2Check = TRUE;
    UpdateData(FALSE);

}


// Диагностика CmfcTask11View

#ifdef _DEBUG
void CmfcTask11View::AssertValid() const
{
	CFormView::AssertValid();
}

void CmfcTask11View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CmfcTask11Doc* CmfcTask11View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfcTask11Doc)));
	return (CmfcTask11Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CmfcTask11View
