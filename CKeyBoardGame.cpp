// CKeyBoardGame.cpp: 구현 파일
//

#include "pch.h"
#include "Alarm.h"
#include "afxdialogex.h"
#include "CKeyBoardGame.h"
#include "framework.h"

// CKeyBoardGame 대화 상자

IMPLEMENT_DYNAMIC(CKeyBoardGame, CDialogEx)

CKeyBoardGame::CKeyBoardGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CKeyBoardGameDlg, pParent)

	, keyboardResult(_T(""))
	, TestProblem(_T(""))
	, keyboard_time_limit(_T(""))
	, currentTime(0)
	, afterTime(0)
	, time_limit(0)
{	

}

CKeyBoardGame::~CKeyBoardGame()
{
}

BOOL CKeyBoardGame::OnInitDialog()
{
	CDialog::OnInitDialog();

	LOGFONT font_info; // 폰트를 휴먼 매직체로 변경합니다.
	::GetObject(GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &font_info);

	font_info.lfUnderline = TRUE;
	font_info.lfItalic = TRUE;
	font_info.lfWeight = 600;
	memcpy(font_info.lfFaceName, L"휴먼매직체", sizeof(L"휴먼매직체"));

	m_font.CreateFontIndirectW(&font_info);
	GetDlgItem(keyboardGameTitle)->SetFont(&m_font);
	GetDlgItem(keyboardString)->SetFont(&m_font); 
	GetDlgItem(keyboardtest)->SetFont(&m_font);

	// 게임을 강제 종료를 막기 위해 x 버튼을 Gray 처리합니다.
	CMenu* p_menu = this->GetSystemMenu(FALSE);
	p_menu->EnableMenuItem(SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
	return TRUE;
}

void CKeyBoardGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, keyboardinput, keyboardResult);
	DDX_Text(pDX, keyboardtest, TestProblem);
	DDX_Text(pDX, keyboardLimitSec, keyboard_time_limit);
}


BEGIN_MESSAGE_MAP(CKeyBoardGame, CDialogEx)
	ON_BN_CLICKED(game_start, &CKeyBoardGame::OnBnClickedstart)
	ON_EN_CHANGE(keyboardLimitSec, &CKeyBoardGame::OnEnChangekeyboardlimitsec)
	ON_BN_CLICKED(IDOK, &CKeyBoardGame::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CKeyBoardGame::OnBnClickedComplete1)
END_MESSAGE_MAP()


void CKeyBoardGame::OnBnClickedstart() // 게임시작 버튼을 눌렀을 때 호출되는 함수
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	time_limit = rand() % 11 + 5; // 시간 제한 초 설정
	CString characters = _T("가나다라마바사아자차카타파하"); // 무작위 문자열을 위한 데이터
	CString randomString;
	int length = rand() % 21 + 10; // 문자열의 길이는 20부터 30까지 중 무작위
	
	UpdateData(TRUE);
	keyboard_time_limit.Format(_T("%d"), time_limit); 
	for (int i = 0; i < length; ++i) {
		int index = rand() % characters.GetLength();
		randomString += characters[index];
	} // length 길이만큼의 무작위 문자열 생성
	TestProblem.Format(randomString); // 에디트 컨트롤에 문자열 출력
	GetDlgItem(keyboardtest)->EnableWindow(FALSE); // 문자열을 복사하는 행위를 막기 위해 에디트컨트롤 비활성화
	
	currentTime = CTime::GetCurrentTime(); // 게임을 시작한 현재시간을 설정
	UpdateData(FALSE);
}

void CKeyBoardGame::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}



void CKeyBoardGame::OnEnChangekeyboardlimitsec()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void CKeyBoardGame::OnBnClickedComplete1() // 게임 완료 버튼을 눌렀을 때 호출되는 함수
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	afterTime = CTime::GetCurrentTime();
	CTimeSpan tmp = afterTime - currentTime;
	UpdateData(TRUE);
	if (0 < tmp.GetTotalSeconds() && tmp.GetTotalSeconds() < time_limit && keyboardResult.Compare(TestProblem) == 0) {
		CDialogEx::OnOK(); // 제한 시간 내 그리고 알맞은 문자열을 입력하였을 시에 알람음이 울리는 것을 종료
	}
	else {
		AfxMessageBox(_T("게임에 실패했습니다. 다시 시도해주세요"), MB_OK | MB_ICONINFORMATION);
		OnBnClickedstart(); // 제한시간을 맞추지 못하거나 문자열이 다르면 재호출
	}
	UpdateData(FALSE);
}
