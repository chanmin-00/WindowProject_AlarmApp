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
{

}

CKeyBoardGame::~CKeyBoardGame()
{
}

void CKeyBoardGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, keyboardinput, keyboardResult);
	DDX_Text(pDX, keyboardtest, TestProblem);
}


BEGIN_MESSAGE_MAP(CKeyBoardGame, CDialogEx)
	ON_BN_CLICKED(game_start, &CKeyBoardGame::OnBnClickedstart)
	ON_EN_CHANGE(keyboardLimitSec, &CKeyBoardGame::OnEnChangekeyboardlimitsec)
END_MESSAGE_MAP()


void CKeyBoardGame::OnBnClickedstart() // 게임시작 버튼을 눌렀을 때 호출되는 함수
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString characters = _T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"); // 무작위 문자열을 위한 데이터
	CString randomString;
	int length = rand() % 51 + 20; // 문자열의 길이는 50부터 100까지 중 무작위
	UpdateData(TRUE);
	for (int i = 0; i < length; ++i) {
		int index = rand() % characters.GetLength();
		randomString += characters[index];
	} // length 길이만큼의 무작위 문자열 생성
	TestProblem.Format(randomString); // 에디트 컨트롤에 문자열 출력
	UpdateData(FALSE);

}


void CKeyBoardGame::OnEnChangekeyboardlimitsec()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
