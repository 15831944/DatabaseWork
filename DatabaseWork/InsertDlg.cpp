// InsertDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "InsertDlg.h"
#include "afxdialogex.h"


// InsertDlg 对话框

IMPLEMENT_DYNAMIC(InsertDlg, CDialogEx)

InsertDlg::InsertDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERTDLG, pParent)
{

}

InsertDlg::~InsertDlg()
{
}

void InsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InsertDlg, CDialogEx)
END_MESSAGE_MAP()


// InsertDlg 消息处理程序
