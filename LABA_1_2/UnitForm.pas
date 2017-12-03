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
    // Вспомогательные процедуры
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



// Активация/дизактивация элементов поиска и печати
procedure TMainForm.ChangeEnable(enable: Boolean);
begin
  // Элементы поиска информации по запросу
  MainForm.labelRequestInfo.Enabled := enable;
  MainForm.textboxRequestField.Enabled := enable;
  MainForm.buttonRequestInfoFind.Enabled := enable;
  MainForm.memoRequestInfo.Enabled := enable;
  // Элементы печати общей информации в файл
  MainForm.buttonGeneralInfoFileChoose.Enabled := enable;
  MainForm.labelGeneralInfoFileChoose.Enabled := enable;
  MainForm.buttonGeneralInfoWrite.Enabled := enable;
end;

// Отображение элементов поиска и печати, если файлы городов и стран выбраны
procedure TMainForm.ShowAll(secondFile: string);
begin
  if (secondFile <> '') then
  begin
    ChangeEnable(true);
    MainForm.buttonGeneralInfoWrite.Enabled := false;
  end;
end;

// Добавление выбранного файла в текст label'а
// с пробелом для полной вместимости
procedure TMainForm.SetFileNameToLabel(fileName: string; fileLabel: TLabel);
var fileNameForLabel: string;
begin
  fileNameForLabel := fileName;
  Insert(' ', fileNameForLabel, 55);
  fileLabel.Caption := fileNameForLabel;
end;

// Выбор файла городов
procedure TMainForm.buttonTownsFileChooseClick(Sender: TObject);
begin
  // Описание работы диалогового окна
  openFileDialog.Title := 'Выбор файла городов';
  if openFileDialog.Execute then
    if (openFileDialog.FileName = countriesFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл стран', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = generalInfoFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл для общей информации', mtError, [mbOk], 0)
    else
    begin // Файл ещё нигде не используется
      townsFileName := openFileDialog.FileName;
      SetFileNameToLabel(townsFileName, MainForm.labelTownsFileChoose);
      ShowAll(countriesFileName);
    end;
end;

// Выбор файла стран
procedure TMainForm.buttonCountriesFileChooseClick(Sender: TObject);
begin
  // Описание работы диалогового окна
  openFileDialog.Title := 'Выбор файла стран';
  if openFileDialog.Execute then
    if (openFileDialog.FileName = townsFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл городов', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = generalInfoFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл для общей информации', mtError, [mbOk], 0)
    else
    begin // Файл ещё нигде не используется
      countriesFileName := openFileDialog.FileName;
      SetFileNameToLabel(countriesFileName, MainForm.labelCountriesFileChoose);
      ShowAll(townsFileName);
    end;
end;

// Выбор файла для общей информации
procedure TMainForm.buttonGeneralInfoFileChooseClick(Sender: TObject);
begin
  // Описание работы диалогового окна
  openFileDialog.Title := 'Выбор файла для общей информации';
  if openFileDialog.Execute then
    if (openFileDialog.FileName = townsFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл городов', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = countriesFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл стран', mtError, [mbOk], 0)
    else
    begin // Файл ещё нигде не используется
      generalInfoFileName := openFileDialog.FileName;
      MainForm.labelGeneralInfoFileChoose.Caption := generalInfoFileName; 
      MainForm.buttonGeneralInfoWrite.Enabled := true;
    end;
end;

procedure TMainForm.buttonRequestInfoFindClick(Sender: TObject);
begin

end;

// Форма создана
procedure TMainForm.FormCreate(Sender: TObject);
const lenDir = 8; // Длина имени папки в символах
var myDir: string;   // Путь к папке с файлами (городов, стран, для общей информации)
begin
  // Дизактивация элементов на форме в начале работы
  ChangeEnable(false);
  townsFileName := '';
  countriesFileName := '';
  generalInfoFileName := '';
  // Задаётся путь к папке с файлами
  myDir := GetCurrentDir;
  Delete(myDir, Length(myDir)-lenDir, lenDir+1);
  myDir := myDir + '\iofiles';
  // Описание диалогового окна выбора файлов
  openFileDialog := TOpenDialog.Create(self);
  openFileDialog.InitialDir := myDir;
  openFileDialog.Options := [ofReadOnly, ofFileMustExist];
  openFileDialog.Filter := 'txt, csv files|*.txt; *.csv';
end;

// Окно с информацией о программе
procedure TMainForm.menuAboutClick(Sender: TObject);
begin
  MessageDlg('Информация о городах и странах' + #13#10 + 'Версия beta 0.03' + #13#10 + '© Макаров Егор, 2017.' + #13#10 + 'Не все права защищены, но мы работаем над этим.',mtInformation,[mbOk],0);
end;

end.
