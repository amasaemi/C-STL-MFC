
// mfcTask10Dlg.cpp: файл реализации
//

#include "stdafx.h"
#include "mfcTask10.h"
#include "mfcTask10Dlg.h"
#include "afxdialogex.h"
#include "Showdib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
public:
//    afx_msg void OnFileOpen();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//    ON_COMMAND(ID_FILE_OPEN, &CAboutDlg::OnFileOpen)
END_MESSAGE_MAP()


// Диалоговое окно CmfcTask10Dlg



CmfcTask10Dlg::CmfcTask10Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MFCTASK10_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    hbm = 0;
}

void CmfcTask10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcTask10Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_COMMAND(ID_FILE_EXIT, &CmfcTask10Dlg::OnFileExit)
    ON_COMMAND(ID_FILE_OPEN32771, &CmfcTask10Dlg::OnFileOpen32771)
END_MESSAGE_MAP()


// Обработчики сообщений CmfcTask10Dlg

BOOL CmfcTask10Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CmfcTask10Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CmfcTask10Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
        //Если открыт bmp файл
        if (hbm) {
            CClientDC dc(this);

            //Получить указатель на DC.

            HDC hdc = ::GetDC(m_hWnd);
            HDC hdcBits = ::CreateCompatibleDC(hdc);

            //Выбрать объект
            SelectObject(hdcBits, hbm);

            //Закрасить клиентскую облаcть черным цветом
            CRect wdRect;
            GetClientRect(&wdRect);
            CBrush brush;
            brush.CreateSolidBrush(RGB(0, 0, 0));
            dc.FillRect(&wdRect, &brush);

            //Вывести изображение
            BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcBits, 0, 0, SRCCOPY);

            //Удалить DC
            DeleteDC(hdcBits);
            ::ReleaseDC(m_hWnd, hdc);
        }

		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CmfcTask10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcTask10Dlg::OnFileExit()
{
    // TODO: добавьте свой код обработчика команд
    OnOK();
}

void CmfcTask10Dlg::OnFileOpen32771()
{
    // TODO: добавьте свой код обработчика команд
    //Заголовок и путь к файлу
    char FileName[500];
    char FileTitle[100];
    FileName[0] = '\0';

    //Создать объект диалогового окна 
    CFileDialog file(TRUE);
    //Уставновить аттрибуты диалогового окна
    file.m_ofn.lpstrFilter = TEXT("Bitmap picture files *.bmp\0*.bmp\0All Files *.*\0*.*\0\0");
    file.m_ofn.lpstrFileTitle = FileTitle;
    file.m_ofn.lpstrFile = FileName;
    file.m_ofn.lpstrTitle = "Open BMP File";
    //Вывести диалоговое окно
    file.DoModal();

    //Если ничего не выбранно, то вернуться
    if (FileName[0] == '\0')return;
    //Изменить заголовок окна на имя файла
    SetWindowText(FileTitle);

    //Получить указатель на объект в памяти
    HANDLE hdibCurrent1 = OpenDIB(FileName);
    hbm = 0;

    //Получить указатель на изображение
    hbm = BitmapFromDib(hdibCurrent1, 0);

    //Записать параметры изображения 
    GetObject(hbm, sizeof(BITMAP), (LPSTR)&bm);

    //Получить координаты окна
    CRect wdRect;
    GetClientRect(&wdRect);
    ClientToScreen(&wdRect);

    //Изменить размеры окна
    //SetWindowPos(NULL, wdRect.left - 4, wdRect.top - 42, bm.bmWidth + wdRect.left, bm.bmHeight + wdRect.top, NULL);
    SetWindowPos(NULL, wdRect.left, wdRect.top, bm.bmWidth+4, bm.bmHeight+42, NULL);

    //Вывести картинку
    OnPaint();
}
