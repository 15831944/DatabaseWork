#pragma once
class DBtoListCtrl
{
public:
	DBtoListCtrl();
	DBtoListCtrl(CListCtrl* CLC_list,CRecordset* CRS_result);
	~DBtoListCtrl();

	void GerenateLC();
	void addNewRecord(CRecordset* new_rs);
private:
	CListCtrl * list;
	CRecordset* result;
};

