program LABA_1_2;

uses
  Forms,
  UnitForm in 'UnitForm.pas' {MainForm};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TMainForm, MainForm);
  Application.Run;
end.
