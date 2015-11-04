
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
	DDX_Control(pDX, IDC_IMAGE_CONTROL, imageSelectCtr);
	DDX_Control(pDX, IDC_EDIT3, editK);
	DDX_Control(pDX, IDC_EDIT1, txtNameFileTraining);
	DDX_Control(pDX, IDC_EDIT2, txtFileTest);
	DDX_Control(pDX, IDC_EDIT4, editEstimate);
	DDX_Control(pDX, IDC_EDIT5, editResult);
	DDX_Control(pDX, IDC_COMBO1, cbbSelectDistance);
}

BEGIN_MESSAGE_MAP(CKNNMachineLearningDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CKNNMachineLearningDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CKNNMachineLearningDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CKNNMachineLearningDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CKNNMachineLearningDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CKNNMachineLearningDlg::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CKNNMachineLearningDlg::OnCbnSelchangeCombo1)
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
	__imageProcessing = new ImageProcessing();
	//end Init cobobox image

	//init combobox
	cbbSelectDistance.AddString(L"Eclide Distance");
	cbbSelectDistance.AddString(L"Cosin Distance");
	//cbbSelectDistance.SetCurSel(0);
	
	//end init combobox
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
	this->__readDataTraining = new ReadDataTraining(__filePathTrainingData, NUMBER_OF_ATTRIBUTES, NUMBER_OF_IMAGES_TRAINING);
}

void CKNNMachineLearningDlg::OnBnClickedButton4()
{
	__filePathTestData = chooserFileTestData();
	this->__readDataTest = new ReadDataTest(__filePathTestData, NUMBER_OF_ATTRIBUTES, NUMBER_OF_IMAGES_TEST);
}


void CKNNMachineLearningDlg::OnBnClickedButton1()
{
	//Estimate with data test
	UpdateData(true);
	setK();

	if ((__filePathTestData.length() == 0) || (__filePathTrainingData.length() == 0) ) {
		MessageBox(L"Please enter file training and test", L"Warring");
		return;
	}

	if (this->__k <= 0)
	{
		MessageBox(L"Please enter a number k > 0", L"Warring");
		return;
	}
	this->__methodDistance = cbbSelectDistance.GetCurSel();
	this->__knn = new KNN(__filePathTrainingData, __filePathTestData, __k, __methodDistance);
	float acc = __knn->estimate();
	CString s;
	s.Format(_T("Accuracy: %f"), acc);
	editEstimate.SetWindowTextW(s);
	UpdateData(false);
}


void CKNNMachineLearningDlg::OnBnClickedButton2()
{
	if (__imageProcessing->getImagePath().length() <= 0) 
	{
		MessageBox(L"Please select image size 32 x 32", L"Warring");
		return;
	}

	setK();
	if ((this->__k <= 0))
	{
		MessageBox(L"Please enter a number k > 0", L"Warring");
		return;
	}
	if ((this->__filePathTrainingData.length() <= 0))
	{
		MessageBox(L"Please enter file training", L"Warring");
		return;
	}
	this->__methodDistance = cbbSelectDistance.GetCurSel();
	vector<unsigned int> attr = __imageProcessing->normalizeImage();
	Image* img = new Image(attr);
	this->__knn = new KNN(__filePathTrainingData, __filePathTestData, __k, __methodDistance);
	int result = __knn->predict(img);
	UpdateData(true);
	CString txtResult;
	txtResult.Format(_T("%d"), result);
	CWnd *pWnd = GetDlgItem(IDC_EDIT5);
	CDC *pDC   = pWnd->GetDC();
	pDC->SetTextColor(RGB(255, 0, 0));
	editResult.SetWindowTextW(txtResult);
	UpdateData(false);
}

HBRUSH CKNNMachineLearningDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if ( pWnd->m_hWnd == editResult.m_hWnd )
	{
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkColor(RGB(255,255,255));
		
		hbr = (HBRUSH)GetStockObject(WHITE_BRUSH);
	}

	return hbr;
}

void CKNNMachineLearningDlg::setK()
{
	UpdateData(true);
	CString txtK;
	editK.GetWindowTextW(txtK);
	if (txtK.GetLength() <= 0) {
		cout << "Please enter k" << endl;
		return;
	}

	this->__k = _tstoi(txtK);
	UpdateData(false);
}


void CKNNMachineLearningDlg::OnBnClickedButton5()
{
	char strFilter[] = {"Text Files (*.bmp*)|*.bmp*|"};
	CFileDialog FileDlg(FALSE, CString(".bmp*"), NULL, 0, CString(strFilter));
	string fullpath;

	while (true)
	{
		if (FileDlg.DoModal() == IDOK) {
			CString filename = FileDlg.GetFileName();
			CString filePath = FileDlg.GetFolderPath();
			UpdateData(true);
			fullpath = CStringA(filePath+'\\'+filename);
			__imageProcessing->setImagePath(fullpath);
			break;
		}
	}

	if (fullpath.length() > 0) 
	{
		editResult.SetWindowTextW(L"");
		std::wstring ws; 
		ws.assign( fullpath.begin(), fullpath.end() );
		HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, ws.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		if (hBitmap != NULL)
		{
			imageCurBitmap.Detach();
			imageCurBitmap.Attach(hBitmap);
			imageSelectCtr.SetBitmap(imageCurBitmap);
		}
	}
}


void CKNNMachineLearningDlg::OnCbnSelchangeCombo1()
{
	int idxSelect = cbbSelectDistance.GetCurSel();
	switch (idxSelect)
	{
	case 0:
		__methodDistance = 0;
		break;
	case 1:
		__methodDistance = 1;
		break;
	default:
		break;
	}
}
