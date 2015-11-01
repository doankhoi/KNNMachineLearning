
// KNNMachineLearningDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <string>
#include <iostream>
#include "Data\ReadDataTraining.h"
#include "Data\ReadDataTest.h"
#include "Data\Utils.h"
#include "KNN\KNN.h"
#include "ImageProcessing\ImageProcessing.h"
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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	DECLARE_MESSAGE_MAP()
	CComboBox cbbSelectImage;
	CStatic imageSelectCtr;

	CBitmap imageCurBitmap;

private:
	int __k;
	string __filePathTrainingData;
	string __filePathTestData;
	ReadDataTest* __readDataTest;
	ReadDataTraining* __readDataTraining;
	ImageProcessing* __imageProcessing;
	KNN* __knn;

	void setK();
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
	afx_msg void OnBnClickedButton1();
protected:
	CEdit editEstimate;
public:
	afx_msg void OnBnClickedButton2();
protected:
	CEdit editResult;
public:
	afx_msg void OnBnClickedButton5();
};
