unit UnitForm;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Menus;

type
  TMainForm = class(TForm)
    buttonTownsFileChoose: TButton;
    buttonCountriesFileChoose: TButton;
    labelTownsFileChoose: TLabel;
    labelCountriesFileChoose: TLabel;
    labelRequestInfo: TLabel;
    textboxRequestField: TEdit;
    buttonGeneralInfoFileChoose: TButton;
    labelGeneralInfoFileChoose: TLabel;
    buttonGeneralInfoWrite: TButton;
    buttonRequestInfoFind: TButton;
    memoRequestInfo: TMemo;
    MainMenu: TMainMenu;
    menuHelp: TMenuItem;
    menuAbout: TMenuItem;
    procedure menuAboutClick(Sender: TObject);
    procedure buttonRequestInfoFindClick(Sender: TObject);

    procedure FormCreate(Sender: TObject);
    procedure buttonGeneralInfoFileChooseClick(Sender: TObject);
    procedure buttonTownsFileChooseClick(Sender: TObject);
    procedure buttonCountriesFileChooseClick(Sender: TObject);

  private
    // ��������������� ���������
    procedure ChangeEnable(enable: Boolean);
    procedure ShowAll(secondFile: string);
    procedure SetFileNameToLabel(fileName: string; fileLabel: TLabel);
  public
    { Public declarations }
  end;

var
  MainForm: TMainForm;
  townsFileName, countriesFileName, generalInfoFileName: string;
  openFileDialog: TOpenDialog;

implementation

{$R *.dfm}



// ���������/������������ ��������� ������ � ������
procedure TMainForm.ChangeEnable(enable: Boolean);
begin
  // �������� ������ ���������� �� �������
  MainForm.labelRequestInfo.Enabled := enable;
  MainForm.textboxRequestField.Enabled := enable;
  MainForm.buttonRequestInfoFind.Enabled := enable;
  MainForm.memoRequestInfo.Enabled := enable;
  // �������� ������ ����� ���������� � ����
  MainForm.buttonGeneralInfoFileChoose.Enabled := enable;
  MainForm.labelGeneralInfoFileChoose.Enabled := enable;
  MainForm.buttonGeneralInfoWrite.Enabled := enable;
end;

// ����������� ��������� ������ � ������, ���� ����� ������� � ����� �������
procedure TMainForm.ShowAll(secondFile: string);
begin
  if (secondFile <> '') then
  begin
    ChangeEnable(true);
    MainForm.buttonGeneralInfoWrite.Enabled := false;
  end;
end;

// ���������� ���������� ����� � ����� label'�
// � �������� ��� ������ �����������
procedure TMainForm.SetFileNameToLabel(fileName: string; fileLabel: TLabel);
var fileNameForLabel: string;
begin
  fileNameForLabel := fileName;
  Insert(' ', fileNameForLabel, 55);
  fileLabel.Caption := fileNameForLabel;
end;

// ����� ����� �������
procedure TMainForm.buttonTownsFileChooseClick(Sender: TObject);
begin
  // �������� ������ ����������� ����
  openFileDialog.Title := '����� ����� �������';
  if openFileDialog.Execute then
    if (openFileDialog.FileName = countriesFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� �����', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = generalInfoFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� ��� ����� ����������', mtError, [mbOk], 0)
    else
    begin // ���� ��� ����� �� ������������
      townsFileName := openFileDialog.FileName;
      SetFileNameToLabel(townsFileName, MainForm.labelTownsFileChoose);
      ShowAll(countriesFileName);
    end;
end;

// ����� ����� �����
procedure TMainForm.buttonCountriesFileChooseClick(Sender: TObject);
begin
  // �������� ������ ����������� ����
  openFileDialog.Title := '����� ����� �����';
  if openFileDialog.Execute then
    if (openFileDialog.FileName = townsFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� �������', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = generalInfoFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� ��� ����� ����������', mtError, [mbOk], 0)
    else
    begin // ���� ��� ����� �� ������������
      countriesFileName := openFileDialog.FileName;
      SetFileNameToLabel(countriesFileName, MainForm.labelCountriesFileChoose);
      ShowAll(townsFileName);
    end;
end;

// ����� ����� ��� ����� ����������
procedure TMainForm.buttonGeneralInfoFileChooseClick(Sender: TObject);
begin
  // �������� ������ ����������� ����
  openFileDialog.Title := '����� ����� ��� ����� ����������';
  if openFileDialog.Execute then
    if (openFileDialog.FileName = townsFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� �������', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = countriesFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� �����', mtError, [mbOk], 0)
    else
    begin // ���� ��� ����� �� ������������
      generalInfoFileName := openFileDialog.FileName;
      MainForm.labelGeneralInfoFileChoose.Caption := generalInfoFileName; 
      MainForm.buttonGeneralInfoWrite.Enabled := true;
    end;
end;

procedure TMainForm.buttonRequestInfoFindClick(Sender: TObject);
begin

end;

// ����� �������
procedure TMainForm.FormCreate(Sender: TObject);
const lenDir = 8; // ����� ����� ����� � ��������
var myDir: string;   // ���� � ����� � ������� (�������, �����, ��� ����� ����������)
begin
  // ������������ ��������� �� ����� � ������ ������
  ChangeEnable(false);
  townsFileName := '';
  countriesFileName := '';
  generalInfoFileName := '';
  // ������� ���� � ����� � �������
  myDir := GetCurrentDir;
  Delete(myDir, Length(myDir)-lenDir, lenDir+1);
  myDir := myDir + '\iofiles';
  // �������� ����������� ���� ������ ������
  openFileDialog := TOpenDialog.Create(self);
  openFileDialog.InitialDir := myDir;
  openFileDialog.Options := [ofReadOnly, ofFileMustExist];
  openFileDialog.Filter := 'txt, csv files|*.txt; *.csv';
end;

// ���� � ����������� � ���������
procedure TMainForm.menuAboutClick(Sender: TObject);
begin
  MessageDlg('���������� � ������� � �������' + #13#10 + '������ beta 0.03' + #13#10 + '� ������� ����, 2017.' + #13#10 + '�� ��� ����� ��������, �� �� �������� ��� ����.',mtInformation,[mbOk],0);
end;

end.
