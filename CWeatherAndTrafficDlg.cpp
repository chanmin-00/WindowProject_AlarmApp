// CWeatherAndTrafficDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Alarm.h"
#include "afxdialogex.h"
#include "CWeatherAndTrafficDlg.h"


// CWeatherAndTrafficDlg 대화 상자

IMPLEMENT_DYNAMIC(CWeatherAndTrafficDlg, CDialogEx)

CWeatherAndTrafficDlg::CWeatherAndTrafficDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(WetherAndTrafficDlg, pParent)
{

}

CWeatherAndTrafficDlg::~CWeatherAndTrafficDlg()
{
}

void CWeatherAndTrafficDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWeatherAndTrafficDlg, CDialogEx)
	ON_STN_CLICKED(IDC_WEATHER, &CWeatherAndTrafficDlg::OnStnClickedWeather)
	ON_STN_CLICKED(IDC_Traffic, &CWeatherAndTrafficDlg::OnStnClickedTraffic)
END_MESSAGE_MAP()

BOOL CWeatherAndTrafficDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// 하이퍼링크 주소에 대한 폰트를 다르게 설정합니다.
	
	LOGFONT font_info;
	::GetObject(GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &font_info);

	font_info.lfUnderline = TRUE;
	font_info.lfItalic = TRUE;
	font_info.lfWeight = 600;
	memcpy(font_info.lfFaceName, L"굴림체", sizeof(L"굴림체"));
	
	m_font.CreateFontIndirectW(&font_info); 
	GetDlgItem(IDC_WEATHER)->SetFont(&m_font);
	GetDlgItem(IDC_Traffic)->SetFont(&m_font); // 하이퍼링크 스태틱 컨트롤의 폰트를 변경합니다

	return TRUE;
}

// CWeatherAndTrafficDlg 메시지 처리기


void CWeatherAndTrafficDlg::OnStnClickedWeather()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShellExecute(NULL, L"open", L"chrome.exe", L"https://www.weather.go.kr/w/index.do", NULL, SW_SHOW);
	// chome.exe로 기상청 주소로 접속합니다.
}


void CWeatherAndTrafficDlg::OnStnClickedTraffic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShellExecute(NULL, L"open", L"chrome.exe", L"https://www.its.go.kr/", NULL, SW_SHOW);
}
