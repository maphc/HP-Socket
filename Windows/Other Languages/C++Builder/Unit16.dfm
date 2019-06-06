object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'frmMain'
  ClientHeight = 475
  ClientWidth = 589
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 60
    Height = 13
    Caption = #26381#21153#22320#22336#65306
  end
  object Label2: TLabel
    Left = 15
    Top = 47
    Width = 60
    Height = 13
    Caption = #26381#21153#31471#21475#65306
  end
  object Label3: TLabel
    Left = 216
    Top = 16
    Width = 60
    Height = 13
    Caption = #22312#32447#36830#25509#65306
  end
  object Label4: TLabel
    Left = 272
    Top = 16
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Edit1: TEdit
    Left = 71
    Top = 14
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '0.0.0.0'
  end
  object Edit2: TEdit
    Left = 71
    Top = 45
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '8808'
  end
  object btn1: TButton
    Left = 424
    Top = 12
    Width = 75
    Height = 25
    Caption = #21551#21160#26381#21153
    TabOrder = 2
    OnClick = btn1Click
  end
  object btn2: TButton
    Left = 424
    Top = 40
    Width = 75
    Height = 25
    Caption = #20572#27490#26381#21153
    TabOrder = 3
    OnClick = btn2Click
  end
  object mmout: TMemo
    Left = 7
    Top = 88
    Width = 562
    Height = 345
    Lines.Strings = (
      ' ')
    ScrollBars = ssBoth
    TabOrder = 4
  end
  object Timer1: TTimer
    Left = 352
    Top = 24
  end
end
