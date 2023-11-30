
// AlarmDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Alarm.h"
#include "AlarmDlg.h"
#include "afxdialogex.h"
#include "CKeyBoardGame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedstart();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()



// CAlarmDlg 대화 상자



CAlarmDlg::CAlarmDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ALARM_DIALOG, pParent)

	, alarm_hour1(0)
	, alarm_minute1(0)
	, alarm_hour2(0)
	, alarm_minute2(0)
	, alarm_timer_id(0)
	, alarm_timer_id1(0)
	, alarm_timer_id2(0)	
	, alarm_ampm1(_T(""))
	, alarm_ampm2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAlarmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_hour, alarm_hour1);
	DDX_Text(pDX, IDC_MINUTE, alarm_minute1);
	DDX_Text(pDX, IDC_hour2, alarm_hour2);
	DDX_Text(pDX, IDC_MINUTE2, alarm_minute2);
	DDX_CBString(pDX, IDC_AMPM1, alarm_ampm1);
	DDX_CBString(pDX, IDC_AMPM2, alarm_ampm2);
}

BEGIN_MESSAGE_MAP(CAlarmDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CAlarmDlg::OnBnClickedOk)
	ON_STN_CLICKED(IDC_MINUTESTR2, &CAlarmDlg::OnStnClickedMinutestr2)
	ON_BN_CLICKED(IDC_MAKE_ALARM1, &CAlarmDlg::OnClickedMakeAlarm1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_MAKE_ALARM2, &CAlarmDlg::OnBnClickedMakeAlarm2)
	ON_CBN_SELCHANGE(IDC_AMPM1, &CAlarmDlg::OnCbnSelchangeAmpm1)
END_MESSAGE_MAP()


// CAlarmDlg 메시지 처리기

BOOL CAlarmDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	alarm_hour1 = 0;
	alarm_minute1 = 0;
	alarm_hour2 = 0;
	alarm_minute2 = 0;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CAlarmDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CAlarmDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CAlarmDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAlarmDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CAlarmDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CAlarmDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CAlarmDlg::OnEnChangeAmpm()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CAlarmDlg::OnEnChangeAmpm2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CAlarmDlg::OnStnClickedMinutestr2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CAlarmDlg::OnClickedMakeAlarm1() // 알람 1번을 설정했을 때 호출되는 함수
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 현재 시간을 얻음
	CTime currentTime = CTime::GetCurrentTime();
	CTime todayStart(currentTime.GetYear(), currentTime.GetMonth(), currentTime.GetDay(), 0, 0, 0); // 오늘의 시작 시간을 계산 (현재 날짜의 00:00:00)
	CTimeSpan elapsedTime = currentTime - todayStart; // 현재 시간과 오늘의 시작 시간 간의 차이 계산
	long secondsPassedToday = elapsedTime.GetTotalSeconds(); //차이를 초로 변환,하루 24시를 기준으로 몇 초가 흘렀는지 계산
	
	alarm_type = 1; // 1번째 알람 설정에 대한 flag 
	UpdateData(TRUE);
	if (alarm_ampm1 == "오전" && (alarm_hour1 > 11 || alarm_hour1 < 0)) { // 오전으로 설정된 입력란에 정확한 값이 들어왔는지 확인
		AfxMessageBox(_T("잘못된 값을 입력하였습니다."), MB_OK | MB_ICONINFORMATION);
		return;
	}
	else if (alarm_ampm1 == "오후" && (alarm_hour1 > 12 || alarm_hour1 < 1)) { //오후로 설정된 입력란에 정확한 값이 들어왔는지 확인
		AfxMessageBox(_T("잘못된 값을 입력하였습니다. 오후 hour 값은 1부터 12까지 입니다"), MB_OK | MB_ICONWARNING);
		return;
	}
	if (alarm_ampm1 == "오후" && alarm_hour1 != 12) // 오후값이라면 24시 형태로 변환 필요
		alarm_hour1 += 12; // 예를 들어 오후 1시이면 13시로 변환
	int timerDuration = alarm_hour1 * 60 * 60 + alarm_minute1 * 60 - secondsPassedToday; // 현재 시간으로부터 얼마나 지나야 알람이 울릴지 설정
	if (timerDuration > 0)
	{
		alarm_timer_id1 = SetTimer(1, timerDuration * 1000, nullptr); // timerDuration 초 후에 timer 설정
		// 여기에서 추가적으로 필요한 알람 설정 코드를 작성할 수 있습니다.
	}
	else if (timerDuration <= 0) // 다음날에 알람이 울리도록 설정을 하는 것이므로 24시간을 더한다
	{
		SetTimer(1, (timerDuration + 24 * 60 * 60) * 1000, nullptr);
		CString NextdayMessage;
		NextdayMessage.Format(_T("내일 %d 시 %d 분에 알람이 울립니다"), alarm_hour1, alarm_minute1);
		AfxMessageBox(NextdayMessage, MB_OK | MB_ICONINFORMATION);
	}
	UpdateData(FALSE);

}

void CAlarmDlg::OnBnClickedMakeAlarm2() // 알람 2번을 설정했을 때 호출되는 함수
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		// 현재 시간을 얻음
	CTime currentTime = CTime::GetCurrentTime();
	CTime todayStart(currentTime.GetYear(), currentTime.GetMonth(), currentTime.GetDay(), 0, 0, 0); // 오늘의 시작 시간을 계산 (현재 날짜의 00:00:00)
	CTimeSpan elapsedTime = currentTime - todayStart; // 현재 시간과 오늘의 시작 시간 간의 차이 계산
	long secondsPassedToday = elapsedTime.GetTotalSeconds(); //차이를 초로 변환,하루 24시를 기준으로 몇 초가 흘렀는지 계산

	alarm_type = 2; // 2번째 알람 설정에 대한 flag 
	UpdateData(TRUE);
	if (alarm_ampm2 == "오전" && (alarm_hour2 > 11 || alarm_hour2 < 0)) { // 오전으로 설정된 입력란에 정확한 값이 들어왔는지 확인
		AfxMessageBox(_T("잘못된 값을 입력하였습니다."), MB_OK | MB_ICONINFORMATION);
		return;
	}
	else if (alarm_ampm2== "오후" && (alarm_hour2 > 12 || alarm_hour2 < 1)) { //오후로 설정된 입력란에 정확한 값이 들어왔는지 확인
		AfxMessageBox(_T("잘못된 값을 입력하였습니다. 오후 hour 값은 1부터 12까지 입니다"), MB_OK | MB_ICONWARNING);
		return;
	}
	if (alarm_ampm2 == "오후" && alarm_hour2 != 12) // 오후값이라면 24시 형태로 변환 필요
		alarm_hour2 += 12; // 예를 들어 오후 1시이면 13시로 변환
	int timerDuration = alarm_hour2 * 60 * 60 + alarm_minute2 * 60 - secondsPassedToday; // 현재 시간으로부터 얼마나 지나야 알람이 울릴지 설정
	if (timerDuration > 0)
	{
		alarm_timer_id2 = SetTimer(1, timerDuration * 1000, nullptr); // timerDuration 초 후에 timer 설정
		// 여기에서 추가적으로 필요한 알람 설정 코드를 작성할 수 있습니다.
	}
	else if (timerDuration <= 0) // 다음날에 알람이 울리도록 설정을 하는 것이므로 24시간을 더한다
	{
		SetTimer(1, (timerDuration + 24 * 60 * 60) * 1000, nullptr);
		CString NextdayMessage;
		NextdayMessage.Format(_T("내일 %d 시 %d 분에 알람이 울립니다"), alarm_hour1, alarm_minute1);
		AfxMessageBox(NextdayMessage, MB_OK | MB_ICONINFORMATION);
	}
	UpdateData(FALSE);

}

bool CAlarmDlg::KeyboardGame() { // 무작위 문자열을 제한 시간안에 키보드로 입력 시 true값을 리턴, 아닐 경우 false 리턴

	CKeyBoardGame game_dlg;
	alarm_timer_id = SetTimer(1, 1000, nullptr); // 알람음을 울리는 타이머 생성
	INT_PTR nResponse = game_dlg.DoModal(); // 게임 대화상자 생성, 게임 대화상자 내 컨트롤 변수들을 가져와 게임 실행
	if (nResponse == IDOK) {
		KillTimer(alarm_timer_id); // 게임을 완료하면 알림음을 울리는것을 종료하기
		alarm_timer_id = 0;
		return true;
	}
	return false;
}

void CAlarmDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == alarm_timer_id) {
		MessageBeep(MB_ICONEXCLAMATION); // 경고음을 울리는 경우
	}
	else if (nIDEvent == alarm_timer_id1) { // timer 아이디가 경고음울 울리는 타이머의 아이디가 아니라면 다른 동작을 수행
		KillTimer(alarm_timer_id1);
		CDialogEx::OnTimer(nIDEvent);
		KeyboardGame(); // 키보드 게임을 실행하는 함수를 호출합니다. 게임을 성공해야지만 알람이 종료됩니다
		alarm_timer_id1 = 0; // 종료되면 알람 타이머 아이디 초기화
		AfxMessageBox(_T("알람이 종료되었습니다."), MB_OK | MB_ICONINFORMATION);
	}
	else if (nIDEvent == alarm_timer_id2) { // timer 아이디가 경고음울 울리는 타이머의 아이디가 아니라면 다른 동작을 수행
		KillTimer(alarm_timer_id2);
		CDialogEx::OnTimer(nIDEvent);
		KeyboardGame(); // 키보드 게임을 실행하는 함수를 호출합니다. 게임을 성공해야지만 알람이 종료됩니다
		alarm_timer_id2 = 0; // 종료되면 알람 타이머 아이디 초기화
		AfxMessageBox(_T("알람이 종료되었습니다."), MB_OK | MB_ICONINFORMATION);
	}
}




void CAlarmDlg::OnCbnSelchangeAmpm1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


