#pragma once
#define _AFXDLL
#include <QtWidgets/QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QAxObject>
#include <QFileDialog>
#include <QByteArray>
#include <QMessageBox>
#include <QComboBox>
#include <QProcess>
#include <QTextEdit>
#include <QThread>
#include <QSqlDatabase>
#include <QWaitCondition>
#include <QSqlQuery>
#include <QMutex>
#include <QList>
#include <QApplication>
#include <QDesktopWidget>
#include "ui_IPServer.h"
#include "Function.h"

class QDialog;
class ThreadOperEntry;
class IPServer : public QMainWindow
{
    Q_OBJECT

public:
    IPServer(QWidget *parent = Q_NULLPTR);
	QTableWidget * DeviceSheet;
	QSqlQuery* db_query;
	BOOL Login_dh(void* dhs);
	BOOL Login_hk(void* hks);
	QCheckBox* pcheckBox_dh;
	
signals:
	void TimerSingal(void* ,BOOL);
	void SearchSingal(void*, BOOL);

	
private slots:
	void Slot_sortDevice(int);
	void Login_Type();
    void WriteInformationToTable_dh(int state);
	void ModifiyLine();
	void EquipmentSearch();
	void TimerSlotd(void*,BOOL);
	void TimerSlotd_Search(void*, BOOL);
	void ExportFunction();
	void ImportFunction();
	void ManualAddDeviceFunc();
	void SetState(int stated);
	void ManualAddDfunc();
	void DatabaseConnectFunc();
	void RefreshDeviceList();
	void QDoubleWfunc(int aitem,int cuttonds);
	void SearchFunc();
	void UpdateTransmitPanel();
private:
    Ui::IPServerClass ui;
	QPushButton* DeviceFind;
	QPushButton* DerivedForm;
	QPushButton* ModifiyButton;
	QPushButton* ExportButton;
	QPushButton* ImportButton;
	QPushButton* ManualAddDevice;
	QDialog* ManualAddDeviceDialog;
	QComboBox* DeviceTypeBox;
	QLineEdit* DeviceEdit[4];
	QLabel* DeviceLabel[4];
	QPushButton* DeviceButton;
	QPushButton* LoginButton;
	QSqlDatabase* db;
	QCheckBox* pCheckBox;
	
	sADP_Start_V30 SADP_Start_V30;
	sADP_Stop SADP_Stop;
	sADP_GetDeviceConfig SADP_GetDeviceConfig;
	sADP_ModifyDeviceNetParam SADP_ModifyDeviceNetParam;
	cLIENT_Init CLIENT_Init;
	cLIENT_SetAutoReconnect CLIENT_SetAutoReconnect;
	cLIENT_SetConnectTime CLIENT_SetConnectTime;
	cLIENT_SearchDevicesByIPs CLIENT_SearchDevicesByIPs;
	cLIENT_StartSearchDevices CLIENT_StartSearchDevices;
	cLIENT_LoginEx2 CLIENT_LoginEx2;
	cLIENT_PacketData CLIENT_PacketData;
	cLIENT_SetNewDevConfig CLIENT_SetNewDevConfig;
	nET_DVR_Login_V40 NET_DVR_Login_V40;
	nET_DVR_Init NET_DVR_Init;
	nET_DVR_SetReconnect NET_DVR_SetReconnect;
	nET_DVR_GetDVRConfig NET_DVR_GetDVRConfig;
	nET_DVR_SetDVRConfig NET_DVR_SetDVRConfig;
	cLIENT_GetLastError CLIENT_GetLastError;
	cLIENT_GetNewDevConfig CLIENT_GetNewDevConfig;
	cLIENT_ParseData CLIENT_ParseData;
	cLIENT_ModifyDevice CLIENT_ModifyDevice;
	cLIENT_Logout CLIENT_Logout;
	nET_DVR_Logout NET_DVR_Logout;
	cLIENT_InitEx CLIENT_InitEx;
	cLIENT_SetNetworkParam CLIENT_SetNetworkParam;
	sADP_GetLastError SADP_GetLastError;
	nET_DVR_GetLastError NET_DVR_GetLastError;
	
	QCheckBox* pCheckBox_hk;
	QThread* Thread_Search;
	ThreadOperEntry* entry;
	QTextEdit* LogOutputMessage;
    QDialog* ConfigDialog_o;
	QDialog* OSDResuit;
	QLineEdit* SuccessOsd;
	QLabel* SuccessOSD;
	QLineEdit* LostOsd;
	QLabel* LostOSD;
	QLineEdit* InputEdit[5];
	QLabel* LabelOfE[5];
	QLineEdit* DatabaseConnection;
	QPushButton* DatabaseConnectButton;
	QPushButton* SearchSetting;
};
class NewQTableWight :public QTableWidgetItem
{
	public:
		bool operator<(const QTableWidgetItem &other) const;
};
class ThreadOperEntry :public QObject
{
	Q_OBJECT
signals:
	void signal_search();
private slots :
	void slot_search();
};
