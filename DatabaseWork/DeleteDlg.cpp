// DeleteDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "DeleteDlg.h"
#include "afxdialogex.h"


// DeleteDlg 对话框

IMPLEMENT_DYNAMIC(DeleteDlg, CDialogEx)

DeleteDlg::DeleteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETEDLG, pParent)
{

}

DeleteDlg::~DeleteDlg()
{
}

void DeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteDlg, CDialogEx)
END_MESSAGE_MAP()


// DeleteDlg 消息处理程序
