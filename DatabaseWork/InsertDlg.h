#pragma once


// InsertDlg 对话框

class InsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InsertDlg)

public:
	InsertDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~InsertDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
