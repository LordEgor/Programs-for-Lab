unit UnitForm;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Menus, Grids;

  
type
  // Структура информации о городах
  townsInfo = record
    Town: string;
    People: string;
    Country: string;
  end;
  // Структура информации о странах
  countriesInfo = record
    Country: string;
    Capital: string;
    Continent: string;
  end;
  // Структура общей информации о городах и странах
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

  private // Вспомогательные процедуры

    // Разделяет строки на подстроки по разделителю
    procedure Split(Delimiter: Char; Str: string; ListOfStrings: TStrings);
    // Печать строки таблицы с общей информации на экран
    procedure PrintInfoLine(k: integer; i: integer);
    // Активация/дизактивация элементов поиска и печати
    procedure ChangeEnable(enable: Boolean);
    // Очищает таблицу с информацией
    procedure ClearStringGrid(StringGrid: TStringGrid);
    // Активация элементов поиска и печати
    procedure ShowSearch();
    // Добавление текста с файлом в текст label'а
    procedure SetFileNameToLabel(fileName: string; fileLabel: TLabel);
    // Объединение (слияние) информации из двух файлов
    procedure MergeFiles();
    // Действия после выбора обеих файлов исходных данных
    procedure EventsAfterChoose(secondFile: string);
  public
    { Public declarations }
  end;

var
  MainForm: TMainForm;
  townsFileName, countriesFileName, generalInfoFileName: string; // Имена файлов с данными
  openFileDialog: TOpenDialog;  // Диалоговое окно выбора файла
  towns: array of townsInfo;   // Информация из файла городов
  countries: array of countriesInfo; // Информация из файла стран
  towns_N,countries_N, general_N: integer;   // Число записей о городах, странах и общей
  generalInfoBase: array of generalInfo; // Общая ниформация из файлов

implementation

{$R *.dfm}

// Разделяет строки на подстроки по разделителю
procedure TMainForm.Split(Delimiter: Char; Str: string; ListOfStrings: TStrings);
begin
   ListOfStrings.Clear;
   ListOfStrings.Delimiter       := Delimiter;
   ListOfStrings.StrictDelimiter := True;
   ListOfStrings.DelimitedText   := Str;
end;

// Печать строки таблицы с общей информации на экран
procedure TMainForm.PrintInfoLine(k: integer; i: integer);
begin
  // k - порядковый номер в таблице (для пользователя)
  // i - порядковый номер в generalInfoBase
  with MainForm.stringGridRequestInfo do
  begin
    Cells[0,k] := IntToStr(k);
    Cells[1,k] := generalInfoBase[i].Town;
    Cells[2,k] := generalInfoBase[i].People;
    Cells[3,k] := generalInfoBase[i].Country;
    Cells[4,k] := generalInfoBase[i].Continent;
  end;
end;

// Активация/дизактивация элементов поиска и печати
procedure TMainForm.ChangeEnable(enable: Boolean);
begin
  // Элементы поиска информации по запросу
  MainForm.labelRequestInfo.Enabled := enable;
  MainForm.textboxRequestField.Enabled := enable;
  MainForm.buttonRequestInfoFind.Enabled := enable;
  MainForm.stringGridRequestInfo.Enabled := enable;
  // Элементы печати общей информации в файл
  MainForm.buttonGeneralInfoFileChoose.Enabled := enable;
  MainForm.labelGeneralInfoFileChoose.Enabled := enable;
  MainForm.buttonGeneralInfoWrite.Enabled := enable;
end;

// Очищает таблицу с информацией
procedure TMainForm.ClearStringGrid(StringGrid: TStringGrid);
var
  i: integer;
begin
  with StringGrid do
  begin
    for i := 0 to (ColCount - 1) do
      Cols[i].Clear;
    // Шапка таблицы
    Cells[0,0] := '№';
    Cells[1,0] := 'Город';
    Cells[2,0] := 'Число жителей';
    Cells[3,0] := 'Страна';
    Cells[4,0] := 'Континент';
  end;
end;

// Активация элементов поиска и печати
procedure TMainForm.ShowSearch();
begin
    ChangeEnable(true);
    MainForm.buttonGeneralInfoWrite.Enabled := false;
end;

// Добавление текста с файлом в текст label'а
// с пробелом для вместимости в форму
procedure TMainForm.SetFileNameToLabel(fileName: string; fileLabel: TLabel);
var i: integer; // Переменная цикла
    OutPutList: TStringList;  // Промежуточный список подстрок
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
  // Добавление пробелов необходимо, чтобы
  // разделить путь к файлу на слова.
  // После этого перенос пути файла в label'е, если
  // он в него не влезает, возможен
end;

// Объединение (слияние) информации из двух файлов
procedure TMainForm.MergeFiles();
var
  i,j,k: integer; // Переменные циклов
  flag: boolean;  // =false, если нет ни одного города из страны/нет страны для города
begin
  k := 0; // Число записей
  // Слияние информации
  for i := 0 to towns_N - 1 do  // по городам
  begin
    flag := false;
    for j := 0 to countries_N - 1 do  // по странам
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
          generalInfoBase[k].Town := towns[i].Town + ' (столица)';
        // Печать общей информации на экран
        PrintInfoLine(k+1,k);
        inc(k);
      end;
    end; // j
    // Нет страны для города i
    if not(flag) then
    begin
      SetLength(generalInfoBase,k+1);
      generalInfoBase[k].Town := towns[i].Town;
      generalInfoBase[k].People := towns[i].People;
      generalInfoBase[k].Country := towns[i].Country;
      generalInfoBase[k].Continent := '-';
      // Печать информации на экран
      PrintInfoLine(k+1,k);
      inc(k);
    end;
  end; // i
  // Нет ни одного города из страны j
  for j := 0 to countries_N - 1 do
  begin
    flag := false;
    for i := 0 to towns_N - 1 do
    begin
      if ((towns[i].Country = countries[j].Country)) then
      begin
        // Встречен город i из страны j
        flag := true;
        break;
      end;
    end; // i
    // Запись страны j без городов
    if not(flag) then
    begin
      SetLength(generalInfoBase,k+1);
      generalInfoBase[k].Town := '-';
      generalInfoBase[k].People := '-';
      generalInfoBase[k].Country := countries[j].Country;
      generalInfoBase[k].Continent := countries[j].Continent;
      // Печать информации на экран
      PrintInfoLine(k+1,k);
      inc(k);
    end;
  end; // j
  // В случае отсутствия общей информцаии
  if (k = 0) then
  begin
    MessageDlg('В выбранных вами файлах нет общей информации!', mtError, [mbOk], 0);
    // Программа в состоянии после выбора файла городов
    ChangeEnable(false);
    countriesFileName := '';
    MainForm.labelCountriesFileChoose.Caption := 'Файл не выбран';
    Exit;
  end;
  general_N := k;
  MainForm.stringGridRequestInfo.RowCount := general_N;
end;

// Действия после выбора файлов исходных данных
procedure TMainForm.EventsAfterChoose(secondFile: string);
begin
  // начальный вид таблицы и label'а под ним
  MainForm.labelGeneralInfoFileChoose.Caption := 'Файл для общей информации не выбран';
  MainForm.textboxRequestField.Text := '';
  ClearStringGrid(MainForm.stringGridRequestInfo);
  if (secondFile <> '') then
  begin
    ShowSearch(); // Отобразить поиск
    MergeFiles(); // Объединить информацию из файлов
  end;
end;

// Конец вспомогательных процедур
// Начало обработчиков событий

// Выбор файла городов и чтение информации о странах
procedure TMainForm.buttonTownsFileChooseClick(Sender: TObject);
var
  f:TextFile; // Переменная для файла
  k: integer; // Счётчик городов
  OutPutList: TStringList;  // Промежуточный список подстрок
  s: string;  // Промежуточная строка  с содержимым строки файла
begin
  // Описание работы диалогового окна
  openFileDialog.Title := 'Выбор файла городов';
  if openFileDialog.Execute then
    // Файл уже используется в программе
    if (openFileDialog.FileName = countriesFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл стран', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = generalInfoFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл для общей информации', mtError, [mbOk], 0)
    else
    // Файл ещё не используется
    begin 
      townsFileName := openFileDialog.FileName;
      // Чтение информации о городах
      OutPutList := TStringList.Create;
      AssignFile(f, townsFileName);
      Reset(f);
      // Файл пуст
      if (Eof(f)) then
      begin
        MessageDlg('Файл ' + townsFileName + ' не содержит информацию о городах.', mtError, [mbOk], 0);
        townsFileName := '';
        Exit;
      end;
      k := 0;   // Счётчик городов
      while (not Eof(f)) do
      begin
        Readln(f,s);
        s := Utf8ToAnsi(s);
        Split(';', s, OutPutList);
        // Проверка формата информации в файле
        if (OutPutList.Count <> 3) then
        begin
          MessageDlg('Файл ' + townsFileName + '  содержит информацию в некорректном формате.'
                      + ' Каждая строка в файле городов должна содержать информацию в виде: '
                      + '"город;население;страна"', mtError, [mbOk], 0);
          townsFileName := '';   
          CloseFile(f);
          Exit;
        end;
        // Сохранение информации
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

// Выбор файла стран и чтение информации о странах
procedure TMainForm.buttonCountriesFileChooseClick(Sender: TObject);
var    
  f:TextFile; // Переменная для файла
  k: integer; // Счётчик стран
  OutPutList: TStringList;  // Промежуточный список подстрок 
  s: string;   // Промежуточная строка
begin
  // Описание работы диалогового окна
  openFileDialog.Title := 'Выбор файла стран';
  if openFileDialog.Execute then
    // Файл уже используется в программе
    if (openFileDialog.FileName = townsFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл городов', mtError, [mbOk], 0)
    else if (openFileDialog.FileName = generalInfoFileName) then
      MessageDlg('Файл ' + openFileDialog.FileName + ' уже выбран как файл для общей информации', mtError, [mbOk], 0)
    else
    // Файл ещё нигде не используется
    begin
      countriesFileName := openFileDialog.FileName;
      // Чтение информации о странах
      OutPutList := TStringList.Create;
      AssignFile(f, countriesFileName);
      Reset(f);
      // Файл пуст
      if (Eof(f)) then
      begin
        MessageDlg('Файл ' + countriesFileName + ' не содержит информацию о странах.', mtError, [mbOk], 0);
        countriesFileName := '';
        Exit;
      end;
      k := 0;   // Счётчик стран
      while (not Eof(f)) do
      begin
        Readln(f,s);
        s := Utf8ToAnsi(s);
        Split(';', s, OutPutList);
        // Проверка формата информации в файле
        if (OutPutList.Count <> 3) then
        begin
          MessageDlg('Файл ' + countriesFileName + '  содержит информацию в некорректном формате.'
                      + ' Каждая строка в файле стран должна содержать информацию в виде: '
                      + '"страна;столица;континент"', mtError, [mbOk], 0);
          countriesFileName := '';
          CloseFile(f);
          Exit;
        end;  
        // Сохранение информации 
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
      SetFileNameToLabel('Для общей информации выбран файл ' + generalInfoFileName, MainForm.labelGeneralInfoFileChoose);
      MainForm.buttonGeneralInfoWrite.Enabled := true;
    end;
end;

// Запись общей информации в выбранный для неё файл
procedure TMainForm.buttonGeneralInfoWriteClick(Sender: TObject);
var
  f:TextFile;   // Переменная для файлов исходных данных
  i: integer;   // Переменная цикла
begin
  AssignFile(f, generalInfoFileName);
  Rewrite(f);
  for i := 0 to general_N - 1 do
    with generalInfoBase[i] do
      Writeln(f,Town + ';' + People + ';' + Country + ';' + Continent);
  CloseFile(f);
  SetFileNameToLabel('Общая информация была записана в файл ' + generalInfoFileName,MainForm.labelGeneralInfoFileChoose);
end;

// Поиск информации по запросу и печать её на экране
procedure TMainForm.buttonRequestInfoFindClick(Sender: TObject);
var
  i: integer; // Переменная цикла
  k: integer; // Счётчик напечатанных строк с информацией
  s: string;  // Текст из TextBox (Edit)
begin       
  s := LowerCase(textboxRequestField.Text);
  if (s <> '') then
  begin       
    ClearStringGrid(MainForm.stringGridRequestInfo);
    k := 0;
    // Печать всего на экран
    if ((s = 'всё') or (s = 'все')) then
    begin 
      for i := 0 to general_N - 1 do
      begin
        PrintInfoLine(i+1,i);
      end;
    end //всё
    else begin // запрос
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
      // Ничего по запросу не найдено
      if (k = 0) then
      begin
        MessageDlg('По запросу "' + s + '" ничего не найдено', mtError, [mbOk], 0);
        Exit;
      end;
    end;//запрос
  end;//''
end;

// Запрет на ввод некорректных символов в TextBox (Edit)
procedure TMainForm.textboxRequestFieldKeyPress(Sender: TObject; var Key: Char);
begin
  // Список запретных для ввода символов
  if (Key in [';', '<', '>', '/', '?', '/', '\', '|',
              '=', ' ', ':', '.', ',', #13, '!']) then
    Key := #0;
end;

// Форма создана
procedure TMainForm.FormCreate(Sender: TObject);
var
  myDir: string; // Путь к папке с файлами (городов, стран, с общей информацией)
  w: integer;   // Параметр толщины одной буквы в строке (в пикселях)
begin
  // Дизактивация элементов на форме в начале работы
  ChangeEnable(false);
  townsFileName := '';
  countriesFileName := '';
  generalInfoFileName := '';
	// Установка пути к папке с файлами
  //myDir := GetCurrentDir;
  myDir := '..\iofiles';
  // Описание диалогового окна выбора файлов
  openFileDialog := TOpenDialog.Create(self);
  openFileDialog.InitialDir := myDir;
  openFileDialog.Options := [ofReadOnly, ofFileMustExist];
  openFileDialog.Filter := 'txt, csv files|*.txt; *.csv';
  // Параметры таблицы с информацией
  ClearStringGrid(stringGridRequestInfo);
  with stringGridRequestInfo do
  begin
    ColCount := 5;
    DefaultRowHeight := 15;
    w := 4;
    // Толщина столбца = w * число символов в ячейке столбца
    ColWidths[0] := w*7;  // Номер строки
    ColWidths[2] := w*20; // Число жителей
    ColWidths[3] := w*22; // Страна
    ColWidths[4] := w*18; // Континент
    // Город = толщина всей таблицы - толщина остальных столбцов
    ColWidths[1] := Width - 25 - ColWidths[0] - ColWidths[2] - ColWidths[3] - ColWidths[4];
  end;
end;

// Окно с информацией о программе
procedure TMainForm.menuAboutClick(Sender: TObject);
begin
  MessageDlg('Информация о городах и странах' + #13#10 + 'Версия 1.3' + #13#10
              + '© Макаров Егор, 2018.' + #13#10 + 'Не все права защищены, но мы работаем над этим.',mtInformation,[mbOk],0);
end;

end.
