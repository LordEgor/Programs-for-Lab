unit UnitForm;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Menus, Grids;

  
type
  // ��������� ���������� � �������
  townsInfo = record
    Town: string;
    People: string;
    Country: string;
  end;
  // ��������� ���������� � �������
  countriesInfo = record
    Country: string;
    Capital: string;
    Continent: string;
  end;
  // ��������� ����� ���������� � ������� � �������
  generalInfo = record
    Town: string;
    People: string;
    Country: string;
    Continent: string;
  end;

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
    MainMenu: TMainMenu;
    menuHelp: TMenuItem;
    menuAbout: TMenuItem;
    stringGridRequestInfo: TStringGrid;
    procedure textboxRequestFieldKeyPress(Sender: TObject; var Key: Char);
    procedure buttonGeneralInfoWriteClick(Sender: TObject);
    procedure menuAboutClick(Sender: TObject);
    procedure buttonRequestInfoFindClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure buttonGeneralInfoFileChooseClick(Sender: TObject);
    procedure buttonTownsFileChooseClick(Sender: TObject);
    procedure buttonCountriesFileChooseClick(Sender: TObject);

  private // ��������������� ���������

    // ��������� ������ �� ��������� �� �����������
    procedure Split(Delimiter: Char; Str: string; ListOfStrings: TStrings);
    // ������ ������ ������� � ����� ���������� �� �����
    procedure PrintInfoLine(k: integer; i: integer);
    // ���������/������������ ��������� ������ � ������
    procedure ChangeEnable(enable: Boolean);
    // ������� ������� � �����������
    procedure ClearStringGrid(StringGrid: TStringGrid);
    // ��������� ��������� ������ � ������
    procedure ShowSearch();
    // ���������� ������ � ������ � ����� label'�
    procedure SetFileNameToLabel(fileName: string; fileLabel: TLabel);
    // ����������� (�������) ���������� �� ���� ������
    procedure MergeFiles();
    // �������� ����� ������ ����� ������ �������� ������
    procedure EventsAfterChoose(secondFile: string);
  public
    { Public declarations }
  end;

var
  MainForm: TMainForm;
  townsFileName, countriesFileName, generalInfoFileName: string; // ����� ������ � �������
  openFileDialog: TOpenDialog;  // ���������� ���� ������ �����
  towns: array of townsInfo;   // ���������� �� ����� �������
  countries: array of countriesInfo; // ���������� �� ����� �����
  towns_N,countries_N, general_N: integer;   // ����� ������� � �������, ������� � �����
  generalInfoBase: array of generalInfo; // ����� ���������� �� ������

implementation

{$R *.dfm}

// ��������� ������ �� ��������� �� �����������
procedure TMainForm.Split(Delimiter: Char; Str: string; ListOfStrings: TStrings);
begin
   ListOfStrings.Clear;
   ListOfStrings.Delimiter       := Delimiter;
   ListOfStrings.StrictDelimiter := True;
   ListOfStrings.DelimitedText   := Str;
end;

// ������ ������ ������� � ����� ���������� �� �����
procedure TMainForm.PrintInfoLine(k: integer; i: integer);
begin
  // k - ���������� ����� � ������� (��� ������������)
  // i - ���������� ����� � generalInfoBase
  with MainForm.stringGridRequestInfo do
  begin
    Cells[0,k] := IntToStr(k);
    Cells[1,k] := generalInfoBase[i].Town;
    Cells[2,k] := generalInfoBase[i].People;
    Cells[3,k] := generalInfoBase[i].Country;
    Cells[4,k] := generalInfoBase[i].Continent;
  end;
end;

// ���������/������������ ��������� ������ � ������
procedure TMainForm.ChangeEnable(enable: Boolean);
begin
  // �������� ������ ���������� �� �������
  MainForm.labelRequestInfo.Enabled := enable;
  MainForm.textboxRequestField.Enabled := enable;
  MainForm.buttonRequestInfoFind.Enabled := enable;
  MainForm.stringGridRequestInfo.Enabled := enable;
  // �������� ������ ����� ���������� � ����
  MainForm.buttonGeneralInfoFileChoose.Enabled := enable;
  MainForm.labelGeneralInfoFileChoose.Enabled := enable;
  MainForm.buttonGeneralInfoWrite.Enabled := enable;
end;

// ������� ������� � �����������
procedure TMainForm.ClearStringGrid(StringGrid: TStringGrid);
var
  i: integer;
begin
  with StringGrid do
  begin
    for i := 0 to (ColCount - 1) do
      Cols[i].Clear;
    // ����� �������
    Cells[0,0] := '�';
    Cells[1,0] := '�����';
    Cells[2,0] := '����� �������';
    Cells[3,0] := '������';
    Cells[4,0] := '���������';
  end;
end;

// ��������� ��������� ������ � ������
procedure TMainForm.ShowSearch();
begin
    ChangeEnable(true);
    MainForm.buttonGeneralInfoWrite.Enabled := false;
end;

// ���������� ������ � ������ � ����� label'�
// � �������� ��� ����������� � �����
procedure TMainForm.SetFileNameToLabel(fileName: string; fileLabel: TLabel);
var i: integer; // ���������� �����
    OutPutList: TStringList;  // ������������� ������ ��������
begin
  OutPutList := TStringList.Create;
  fileLabel.Caption := '';
  Split('\', fileName, OutPutList);
  for i := 0 to OutPutList.Count - 1 do
  begin
    fileLabel.Caption := fileLabel.Caption + OutPutList[i];
    if (i <> (OutPutList.Count - 1)) then
      fileLabel.Caption := fileLabel.Caption + ' \';
  end;
  // ���������� �������� ����������, �����
  // ��������� ���� � ����� �� �����.
  // ����� ����� ������� ���� ����� � label'�, ����
  // �� � ���� �� �������, ��������
end;

// ����������� (�������) ���������� �� ���� ������
procedure TMainForm.MergeFiles();
var
  i,j,k: integer; // ���������� ������
  flag: boolean;  // =false, ���� ��� �� ������ ������ �� ������/��� ������ ��� ������
begin
  k := 0; // ����� �������
  // ������� ����������
  for i := 0 to towns_N - 1 do  // �� �������
  begin
    flag := false;
    for j := 0 to countries_N - 1 do  // �� �������
    begin
      if ((towns[i].Country = countries[j].Country)) then
      begin
        flag := true;
        SetLength(generalInfoBase,k+1);
        generalInfoBase[k].Town := towns[i].Town;
        generalInfoBase[k].People := towns[i].People;
        generalInfoBase[k].Country := countries[j].Country;
        generalInfoBase[k].Continent := countries[j].Continent;
        if (Pos(towns[i].Town, countries[j].Capital) = 1) then
          generalInfoBase[k].Town := towns[i].Town + ' (�������)';
        // ������ ����� ���������� �� �����
        PrintInfoLine(k+1,k);
        inc(k);
      end;
    end; // j
    // ��� ������ ��� ������ i
    if not(flag) then
    begin
      SetLength(generalInfoBase,k+1);
      generalInfoBase[k].Town := towns[i].Town;
      generalInfoBase[k].People := towns[i].People;
      generalInfoBase[k].Country := towns[i].Country;
      generalInfoBase[k].Continent := '-';
      // ������ ���������� �� �����
      PrintInfoLine(k+1,k);
      inc(k);
    end;
  end; // i
  // ��� �� ������ ������ �� ������ j
  for j := 0 to countries_N - 1 do
  begin
    flag := false;
    for i := 0 to towns_N - 1 do
    begin
      if ((towns[i].Country = countries[j].Country)) then
      begin
        // �������� ����� i �� ������ j
        flag := true;
        break;
      end;
    end; // i
    // ������ ������ j ��� �������
    if not(flag) then
    begin
      SetLength(generalInfoBase,k+1);
      generalInfoBase[k].Town := '-';
      generalInfoBase[k].People := '-';
      generalInfoBase[k].Country := countries[j].Country;
      generalInfoBase[k].Continent := countries[j].Continent;
      // ������ ���������� �� �����
      PrintInfoLine(k+1,k);
      inc(k);
    end;
  end; // j
  // � ������ ���������� ����� ����������
  if (k = 0) then
  begin
    MessageDlg('� ��������� ���� ������ ��� ����� ����������!', mtError, [mbOk], 0);
    // ��������� � ��������� ����� ������ ����� �������
    ChangeEnable(false);
    countriesFileName := '';
    MainForm.labelCountriesFileChoose.Caption := '���� �� ������';
    Exit;
  end;
  general_N := k;
  MainForm.stringGridRequestInfo.RowCount := general_N;
end;

// �������� ����� ������ ������ �������� ������
procedure TMainForm.EventsAfterChoose(secondFile: string);
begin
  // ��������� ��� ������� � label'� ��� ���
  MainForm.labelGeneralInfoFileChoose.Caption := '���� ��� ����� ���������� �� ������';
  MainForm.textboxRequestField.Text := '';
  ClearStringGrid(MainForm.stringGridRequestInfo);
  if (secondFile <> '') then
  begin
    ShowSearch(); // ���������� �����
    MergeFiles(); // ���������� ���������� �� ������
  end;
end;

// ����� ��������������� ��������
// ������ ������������ �������

// ����� ����� ������� � ������ ���������� � �������
procedure TMainForm.buttonTownsFileChooseClick(Sender: TObject);
var
  f:TextFile; // ���������� ��� �����
  k: integer; // ������� �������
  OutPutList: TStringList;  // ������������� ������ ��������
  s: string;  // ������������� ������  � ���������� ������ �����
begin
  // �������� ������ ����������� ����
  openFileDialog.Title := '����� ����� �������';
  if openFileDialog.Execute then
    // ���� ��� ������������ � ���������
    if (openFileDialog.FileName = countriesFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� �����', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = generalInfoFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� ��� ����� ����������', mtError, [mbOk], 0)
    else
    // ���� ��� �� ������������
    begin 
      townsFileName := openFileDialog.FileName;
      // ������ ���������� � �������
      OutPutList := TStringList.Create;
      AssignFile(f, townsFileName);
      Reset(f);
      // ���� ����
      if (Eof(f)) then
      begin
        MessageDlg('���� ' + townsFileName + ' �� �������� ���������� � �������.', mtError, [mbOk], 0);
        townsFileName := '';
        Exit;
      end;
      k := 0;   // ������� �������
      while (not Eof(f)) do
      begin
        Readln(f,s);
        s := Utf8ToAnsi(s);
        Split(';', s, OutPutList);
        // �������� ������� ���������� � �����
        if (OutPutList.Count <> 3) then
        begin
          MessageDlg('���� ' + townsFileName + '  �������� ���������� � ������������ �������.'
                      + ' ������ ������ � ����� ������� ������ ��������� ���������� � ����: '
                      + '"�����;���������;������"', mtError, [mbOk], 0);
          townsFileName := '';   
          CloseFile(f);
          Exit;
        end;
        // ���������� ����������
        SetLength(Towns,k+1);
        Towns[k].Town := OutPutList[0];
        Towns[k].People := OutPutList[1];
        Towns[k].Country := OutPutList[2];
        inc(k);
      end;
      CloseFile(f);
      towns_N := k;
      SetFileNameToLabel(townsFileName, MainForm.labelTownsFileChoose);
      EventsAfterChoose(countriesFileName);
    end;
end;

// ����� ����� ����� � ������ ���������� � �������
procedure TMainForm.buttonCountriesFileChooseClick(Sender: TObject);
var    
  f:TextFile; // ���������� ��� �����
  k: integer; // ������� �����
  OutPutList: TStringList;  // ������������� ������ �������� 
  s: string;   // ������������� ������
begin
  // �������� ������ ����������� ����
  openFileDialog.Title := '����� ����� �����';
  if openFileDialog.Execute then
    // ���� ��� ������������ � ���������
    if (openFileDialog.FileName = townsFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� �������', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = generalInfoFileName) then
      MessageDlg('���� ' + openFileDialog.FileName + ' ��� ������ ��� ���� ��� ����� ����������', mtError, [mbOk], 0)
    else
    // ���� ��� ����� �� ������������
    begin
      countriesFileName := openFileDialog.FileName;
      // ������ ���������� � �������
      OutPutList := TStringList.Create;
      AssignFile(f, countriesFileName);
      Reset(f);
      // ���� ����
      if (Eof(f)) then
      begin
        MessageDlg('���� ' + countriesFileName + ' �� �������� ���������� � �������.', mtError, [mbOk], 0);
        countriesFileName := '';
        Exit;
      end;
      k := 0;   // ������� �����
      while (not Eof(f)) do
      begin
        Readln(f,s);
        s := Utf8ToAnsi(s);
        Split(';', s, OutPutList);
        // �������� ������� ���������� � �����
        if (OutPutList.Count <> 3) then
        begin
          MessageDlg('���� ' + countriesFileName + '  �������� ���������� � ������������ �������.'
                      + ' ������ ������ � ����� ����� ������ ��������� ���������� � ����: '
                      + '"������;�������;���������"', mtError, [mbOk], 0);
          countriesFileName := '';
          CloseFile(f);
          Exit;
        end;  
        // ���������� ���������� 
        SetLength(Countries,k+1);
        Countries[k].Country := OutPutList[0];
        Countries[k].Capital := OutPutList[1];
        Countries[k].Continent := OutPutList[2];
        inc(k);
      end;
      CloseFile(f);
      countries_N := k;
      SetFileNameToLabel(countriesFileName, MainForm.labelCountriesFileChoose);
      EventsAfterChoose(townsFileName);
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
      SetFileNameToLabel('��� ����� ���������� ������ ���� ' + generalInfoFileName, MainForm.labelGeneralInfoFileChoose);
      MainForm.buttonGeneralInfoWrite.Enabled := true;
    end;
end;

// ������ ����� ���������� � ��������� ��� �� ����
procedure TMainForm.buttonGeneralInfoWriteClick(Sender: TObject);
var
  f:TextFile;   // ���������� ��� ������ �������� ������
  i: integer;   // ���������� �����
begin
  AssignFile(f, generalInfoFileName);
  Rewrite(f);
  for i := 0 to general_N - 1 do
    with generalInfoBase[i] do
      Writeln(f,Town + ';' + People + ';' + Country + ';' + Continent);
  CloseFile(f);
  SetFileNameToLabel('����� ���������� ���� �������� � ���� ' + generalInfoFileName,MainForm.labelGeneralInfoFileChoose);
end;

// ����� ���������� �� ������� � ������ � �� ������
procedure TMainForm.buttonRequestInfoFindClick(Sender: TObject);
var
  i: integer; // ���������� �����
  k: integer; // ������� ������������ ����� � �����������
  s: string;  // ����� �� TextBox (Edit)
begin       
  s := LowerCase(textboxRequestField.Text);
  if (s <> '') then
  begin       
    ClearStringGrid(MainForm.stringGridRequestInfo);
    k := 0;
    // ������ ����� �� �����
    if ((s = '��') or (s = '���')) then
    begin 
      for i := 0 to general_N - 1 do
      begin
        PrintInfoLine(i+1,i);
      end;
    end //��
    else begin // ������
      for i := 0 to general_N - 1 do
      begin
        with generalInfoBase[i] do
        if ((Pos(s, LowerCase(Town)) + Pos(s, LowerCase(People))
           + Pos(s, LowerCase(Country)) + Pos(s, LowerCase(Continent)))>0)then
        begin
          PrintInfoLine(k+1,i);
          inc(k);
        end;
      end;//i
      // ������ �� ������� �� �������
      if (k = 0) then
      begin
        MessageDlg('�� ������� "' + s + '" ������ �� �������', mtError, [mbOk], 0);
        Exit;
      end;
    end;//������
  end;//''
end;

// ������ �� ���� ������������ �������� � TextBox (Edit)
procedure TMainForm.textboxRequestFieldKeyPress(Sender: TObject; var Key: Char);
begin
  // ������ ��������� ��� ����� ��������
  if (Key in [';', '<', '>', '/', '?', '/', '\', '|',
              '=', ' ', ':', '.', ',', #13, '!']) then
    Key := #0;
end;

// ����� �������
procedure TMainForm.FormCreate(Sender: TObject);
var
  myDir: string; // ���� � ����� � ������� (�������, �����, � ����� �����������)
  w: integer;   // �������� ������� ����� ����� � ������ (� ��������)
begin
  // ������������ ��������� �� ����� � ������ ������
  ChangeEnable(false);
  townsFileName := '';
  countriesFileName := '';
  generalInfoFileName := '';
	// ��������� ���� � ����� � �������
  //myDir := GetCurrentDir;
  myDir := '..\iofiles';
  // �������� ����������� ���� ������ ������
  openFileDialog := TOpenDialog.Create(self);
  openFileDialog.InitialDir := myDir;
  openFileDialog.Options := [ofReadOnly, ofFileMustExist];
  openFileDialog.Filter := 'txt, csv files|*.txt; *.csv';
  // ��������� ������� � �����������
  ClearStringGrid(stringGridRequestInfo);
  with stringGridRequestInfo do
  begin
    ColCount := 5;
    DefaultRowHeight := 15;
    w := 4;
    // ������� ������� = w * ����� �������� � ������ �������
    ColWidths[0] := w*7;  // ����� ������
    ColWidths[2] := w*20; // ����� �������
    ColWidths[3] := w*22; // ������
    ColWidths[4] := w*18; // ���������
    // ����� = ������� ���� ������� - ������� ��������� ��������
    ColWidths[1] := Width - 25 - ColWidths[0] - ColWidths[2] - ColWidths[3] - ColWidths[4];
  end;
end;

// ���� � ����������� � ���������
procedure TMainForm.menuAboutClick(Sender: TObject);
begin
  MessageDlg('���������� � ������� � �������' + #13#10 + '������ 1.3' + #13#10
              + '� ������� ����, 2018.' + #13#10 + '�� ��� ����� ��������, �� �� �������� ��� ����.',mtInformation,[mbOk],0);
end;

end.
