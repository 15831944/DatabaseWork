// UpdateDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "UpdateDlg.h"
#include "afxdialogex.h"


// UpdateDlg 对话框

IMPLEMENT_DYNAMIC(UpdateDlg, CDialogEx)

UpdateDlg::UpdateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPDATEDLG, pParent)
{

}

UpdateDlg::~UpdateDlg()
{
}

void UpdateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UpdateDlg, CDialogEx)
END_MESSAGE_MAP()


// UpdateDlg 消息处理程序
