
// mfcTask11.cpp: определяет поведение классов для приложения.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "mfcTask11.h"
#include "MainFrm.h"

#include "mfcTask11Doc.h"
#include "mfcTask11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcTask11App

BEGIN_MESSAGE_MAP(CmfcTask11App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CmfcTask11App::OnAppAbout)
	// Стандартные команды по работе с файлами документов
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// Создание CmfcTask11App

CmfcTask11App::CmfcTask11App()
{
	// TODO: замените ниже строку идентификатора приложения строкой уникального идентификатора; рекомендуемый
	// формат для строки: ИмяКомпании.ИмяПродукта.СубПродукт.СведенияОВерсии
	SetAppID(_T("mfcTask11.AppID.NoVersion"));

	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}

// Единственный объект CmfcTask11App

CmfcTask11App theApp;


// Инициализация CmfcTask11App

BOOL CmfcTask11App::InitInstance()
{
	// InitCommonControlsEx() требуются для Windows XP, если манифест
	// приложения использует ComCtl32.dll версии 6 или более поздней версии для включения
	// стилей отображения.  В противном случае будет возникать сбой при создании любого окна.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
	// в вашем приложении.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Инициализация библиотек OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// Для использования элемента управления RichEdit требуется метод AfxInitRichEdit2()
	// AfxInitRichEdit2();

	// Стандартная инициализация
	// Если эти возможности не используются и необходимо уменьшить размер
	// конечного исполняемого файла, необходимо удалить из следующего
	// конкретные процедуры инициализации, которые не требуются
	// Измените раздел реестра, в котором хранятся параметры
	// TODO: следует изменить эту строку на что-нибудь подходящее,
	// например на название организации
	SetRegistryKey(_T("Локальные приложения, созданные с помощью мастера приложений"));
	LoadStdProfileSettings(4);  // Загрузите стандартные параметры INI-файла (включая MRU)


	// Зарегистрируйте шаблоны документов приложения.  Шаблоны документов
	//  выступают в роли посредника между документами, окнами рамок и представлениями
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CmfcTask11Doc),
		RUNTIME_CLASS(CMainFrame),       // основное окно рамки SDI
		RUNTIME_CLASS(CmfcTask11View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Разрешить использование расширенных символов в горячих клавишах меню
	CMFCToolBar::m_bExtCharTranslation = TRUE;

	// Синтаксический разбор командной строки на стандартные команды оболочки, DDE, открытие файлов
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Команды диспетчеризации, указанные в командной строке.  Значение FALSE будет возвращено, если
	// приложение было запущено с параметром /RegServer, /Register, /Unregserver или /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Одно и только одно окно было инициализировано, поэтому отобразите и обновите его
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CmfcTask11App::ExitInstance()
{
	//TODO: обработайте дополнительные ресурсы, которые могли быть добавлены
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// Обработчики сообщений CmfcTask11App


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Команда приложения для запуска диалога
void CmfcTask11App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Обработчики сообщений CmfcTask11App





BOOL CmfcTask11App::OnIdle(LONG lCount)
{
    // TODO: добавьте специализированный код или вызов базового класса
    ////-Мой код начинается здесь-////
    /*Вызвать функцию базового класса СWinApp::OnIdle(), чтобы завершить его служебные задачи*/
    CWinApp::OnIdle(lCount);
    //Получить указатель на шаблон документа
    POSITION pos = GetFirstDocTemplatePosition();
    CDocTemplate* pDocTemplate = GetNextDocTemplate(pos);


    //Получить указательна документ
    pos = pDocTemplate->GetFirstDocPosition();
    CDocument* pDoc = pDocTemplate->GetNextDoc(pos);


    //Получить указатель на представление
    pos = pDoc->GetFirstViewPosition();
    CmfcTask11View* pView = (CmfcTask11View*)pDoc->GetNextView(pos);


    //Переменные для хранения времени
    static DWORD PrevTimeTask1 = 0;
    static DWORD PrevTimeTask2 = 0;


    //Получить Текущее время
    DWORD CurrentTime = GetTickCount();


    //Получить данные от элементов уравления
    pView->UpdateData(TRUE);

    //Если время превысило 50 мс, то прибавить 1
    if (CurrentTime>PrevTimeTask1 + 50 &&
        pView->m_EnableTask1Check)
    {
        pView->m_Task1Edit = pView->m_Task1Edit + 1;
        pView->UpdateData(FALSE);
        PrevTimeTask1 = CurrentTime;
    }

    //Если время превысило 500 мс и cчетчик включен, то прибавить 1
    if (CurrentTime>PrevTimeTask2 + 500 &&
        pView->m_EnableTask2Check)
    {
        pView->m_Task2Edit = pView->m_Task2Edit + 1;
        pView->UpdateData(FALSE);
        PrevTimeTask2 = CurrentTime;
    }
    return TRUE;

    return CWinApp::OnIdle(lCount);
}
