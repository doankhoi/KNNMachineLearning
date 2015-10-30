
// KNNMachineLearningDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <string>
#include <iostream>
using namespace std;

// CKNNMachineLearningDlg dialog
class CKNNMachineLearningDlg : public CDialogEx
{
// Construction
public:
	CKNNMachineLearningDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_KNNMACHINELEARNING_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CComboBox cbbSelectImage;
	CStatic imageSelectCtr;

	CBitmap imageCurBitmap;
public:
	afx_msg void OnCbnSelchangeCombo1();

private:
	int __k;
	string __filePathTrainingData;
	string __filePathTestData;

	void loadTextForCombobox();
	int getValueOfK();
	string chooserFileTrainingData();
	string chooserFileTestData();
protected:
	CEdit editK;
public:
	afx_msg void OnBnClickedButton3();
protected:
	CEdit txtNameFileTraining;
	CEdit txtFileTest;
public:
	afx_msg void OnBnClickedButton4();
};
