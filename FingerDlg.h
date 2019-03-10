
// FingerDlg.h : 头文件
//

#pragma once
#include"CZKFPEngX.h"//引入指纹采集器SDK
#include "afxwin.h"

#include<direct.h>//for_mkdir()
#define TEMP_DIR "temp\\" //临时文件夹，用于存放指纹入库前的所有中间处理结果
#define DB_DIR   "Database\\"//指纹库文件夹
#define DB_INDEX_TXT "Database\\index.txt" //指纹库索引文件




//CFingerDlg 对话框
class CFingerDlg : public CDialogEx
{
// 构造
public:
	CFingerDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CFingerDlg();
	CZKFPEngX m_zkfpEng;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	DECLARE_EVENTSINK_MAP()
	afx_msg void OnImageReceivedZkfpengx(BOOL FAR * AImageValid);
public:
	afx_msg void OnBnClickedBtnExit();
	CStatic m_staticInfo;
	CStatic m_picCtrl1;
	CStatic m_picCtrl2;

	CStatic m_picCtrl3,m_picCtrl4, m_picCtrl5, m_picCtrl6, m_picCtrl7, m_picCtrl8, m_picCtrl9, m_picCtrl10, m_picCtrl11, m_picCtrl13;
	CString m_name;
	CString m_name1;
	long m_minuCount;


	afx_msg void OnBnClickedBtnConnect();
	afx_msg void OnBnClickedDisconnect();
	afx_msg void OnBnClickedBtnCapture();
	afx_msg void OnBnClickedBtnStep1();
	afx_msg void OnBnClickedBtnDatabase();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedBtnAddImage();
	afx_msg void OnBnClickedBtnRegister();
	afx_msg void OnBnClickedBtnMatchimage();
	afx_msg void OnBnClickedBtnIdentify();
	void OnDestroy();
};

//3.6.1
void InitDatabase();//创建并初始化指纹库
void InitFile(char* filename);//创建并初始化文件