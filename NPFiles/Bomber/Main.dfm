object MainForm: TMainForm
  Left = 405
  Top = 249
  Width = 200
  Height = 239
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Bomber'
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 129
    Height = 13
    Caption = #1040#1076#1088#1077#1089' ('#1080#1084#1103' '#1074' '#1089#1077#1090#1080' '#1080#1083#1080' IP)'
  end
  object Label2: TLabel
    Left = 8
    Top = 56
    Width = 29
    Height = 13
    Caption = #1058#1077#1082#1089#1090
  end
  object Label3: TLabel
    Left = 8
    Top = 104
    Width = 63
    Height = 13
    Caption = #1057#1082#1086#1083#1100#1082#1086' '#1088#1072#1079
  end
  object Label4: TLabel
    Left = 96
    Top = 104
    Width = 77
    Height = 13
    Caption = #1047#1072#1076#1077#1088#1078#1082#1072' ('#1084#1089'.)'
  end
  object EAdres: TEdit
    Left = 8
    Top = 24
    Width = 177
    Height = 21
    TabOrder = 0
  end
  object EText: TEdit
    Left = 8
    Top = 72
    Width = 177
    Height = 21
    TabOrder = 1
  end
  object BSend: TButton
    Left = 32
    Top = 152
    Width = 129
    Height = 25
    Caption = #1055#1086#1089#1083#1072#1090#1100
    TabOrder = 2
    OnClick = BSendClick
  end
  object ECount: TSpinEdit
    Left = 8
    Top = 120
    Width = 81
    Height = 22
    MaxValue = 1000
    MinValue = 1
    TabOrder = 3
    Value = 1
  end
  object EDelay: TSpinEdit
    Left = 96
    Top = 120
    Width = 89
    Height = 22
    MaxValue = 60000
    MinValue = 0
    TabOrder = 4
    Value = 0
  end
  object XPManifest1: TXPManifest
    Left = 176
  end
  object MainMenu1: TMainMenu
    Left = 96
    Top = 56
    object N1: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = N2Click
    end
  end
end
