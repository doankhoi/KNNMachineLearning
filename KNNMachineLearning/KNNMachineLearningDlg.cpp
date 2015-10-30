
// KNNMachineLearningDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KNNMachineLearning.h"
#include "KNNMachineLearningDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CKNNMachineLearningDlg dialog



CKNNMachineLearningDlg::CKNNMachineLearningDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CKNNMachineLearningDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKNNMachineLearningDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, cbbSelectImage);
	DDX_Control(pDX, IDC_IMAGE_CONTROL, imageSelectCtr);
	DDX_Control(pDX, IDC_EDIT3, editK);
	DDX_Control(pDX, IDC_EDIT1, txtNameFileTraining);
	DDX_Control(pDX, IDC_EDIT2, txtFileTest);
}

BEGIN_MESSAGE_MAP(CKNNMachineLearningDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CKNNMachineLearningDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CKNNMachineLearningDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CKNNMachineLearningDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CKNNMachineLearningDlg message handlers

BOOL CKNNMachineLearningDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//Init combobox image
	loadTextForCombobox();
	//end Init cobobox image

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKNNMachineLearningDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKNNMachineLearningDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKNNMachineLearningDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKNNMachineLearningDlg::OnCbnSelchangeCombo1()
{
	int idxSelect = cbbSelectImage.GetCurSel();

	switch (idxSelect)
	{
	case 0:
		break;
	case 1:
		imageCurBitmap.LoadBitmapW(IDB_BITMAP1);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	}

	imageSelectCtr.SetBitmap((HBITMAP)imageCurBitmap);
}

void CKNNMachineLearningDlg::loadTextForCombobox()
{
	cbbSelectImage.AddString(_T("Number 0"));
	cbbSelectImage.AddString(_T("Number 1"));
	cbbSelectImage.AddString(_T("Number 2"));
	cbbSelectImage.AddString(_T("Number 3"));
	cbbSelectImage.AddString(_T("Number 4"));
	cbbSelectImage.AddString(_T("Number 5"));
	cbbSelectImage.AddString(_T("Number 6"));
	cbbSelectImage.AddString(_T("Number 7"));
	cbbSelectImage.AddString(_T("Number 8"));
	cbbSelectImage.AddString(_T("Number 9"));
	cbbSelectImage.SetCurSel(0);
}

int CKNNMachineLearningDlg::getValueOfK()
{
	CString txtEditK;
	editK.GetWindowTextW(txtEditK);
	int k = _tstoi(txtEditK);
	return k;
}

string CKNNMachineLearningDlg::chooserFileTrainingData()
{
	char strFilter[] = {"Text Files (*.txt)|*.txt|"};
	CFileDialog FileDlg(FALSE, CString(".txt"), NULL, 0, CString(strFilter));
	string fullpath;

	while (true)
	{
		if (FileDlg.DoModal() == IDOK) {
			CString filename = FileDlg.GetFileName();
			CString filePath = FileDlg.GetFolderPath();
			UpdateData(true);
			fullpath = CStringA(filePath+'\\'+filename);
			txtNameFileTraining.SetWindowTextW(filename);
			UpdateData(false);
			return fullpath;
		}
	}
}

string CKNNMachineLearningDlg::chooserFileTestData()
{
	char strFilter[] = {"Text Files (*.txt)|*.txt|"};
	CFileDialog FileDlg(FALSE, CString(".txt"), NULL, 0, CString(strFilter));
	string fullpath;

	while (true)
	{
		if (FileDlg.DoModal() == IDOK) {
			CString filename = FileDlg.GetFileName();
			CString filePath = FileDlg.GetFolderPath();
			UpdateData(true);
			fullpath = CStringA(filePath+'\\'+filename);
			txtFileTest.SetWindowTextW(filename);
			UpdateData(false);
			return fullpath;
		}
	}
}

void CKNNMachineLearningDlg::OnBnClickedButton3()
{
	__filePathTrainingData = chooserFileTrainingData();
}


void CKNNMachineLearningDlg::OnBnClickedButton4()
{
	__filePathTestData = chooserFileTestData();
}
