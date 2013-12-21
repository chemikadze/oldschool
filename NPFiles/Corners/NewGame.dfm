object NewGameForm: TNewGameForm
  Left = 375
  Top = 292
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1053#1086#1074#1072#1103' '#1087#1072#1088#1090#1080#1103
  ClientHeight = 145
  ClientWidth = 190
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 0
    Width = 148
    Height = 13
    Caption = #1042#1088#1077#1084#1103' '#1085#1072' '#1087#1072#1088#1090#1080#1102', HH:MM:SS'
  end
  object Button1: TButton
    Left = 16
    Top = 112
    Width = 75
    Height = 25
    Caption = #1044#1072
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 104
    Top = 112
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 16
    Width = 177
    Height = 21
    TabOrder = 2
    Text = '00:30:00'
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 48
    Width = 177
    Height = 57
    Caption = #1053#1072#1095#1080#1085#1072#1102#1090
    TabOrder = 3
  end
  object RadioButton1: TRadioButton
    Left = 16
    Top = 64
    Width = 97
    Height = 17
    Caption = #1041#1077#1083#1099#1077
    Checked = True
    TabOrder = 4
    TabStop = True
  end
  object RadioButton2: TRadioButton
    Left = 16
    Top = 80
    Width = 97
    Height = 17
    Caption = #1063#1077#1088#1085#1099#1077
    TabOrder = 5
  end
end
