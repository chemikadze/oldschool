object IntroForm: TIntroForm
  Left = 295
  Top = 197
  BorderStyle = bsNone
  Caption = 'IntroForm'
  ClientHeight = 287
  ClientWidth = 374
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 56
    Top = 8
    Width = 273
    Height = 24
    Caption = #1043#1077#1086#1084#1077#1090#1088#1080#1095#1077#1089#1082#1080#1081' '#1087#1086#1089#1090#1088#1086#1080#1090#1077#1083#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 144
    Top = 32
    Width = 96
    Height = 24
    Caption = #1092#1088#1072#1082#1090#1072#1083#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 80
    Top = 200
    Width = 231
    Height = 16
    Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1088#1072#1079#1088#1072#1073#1086#1090#1072#1085#1072' '#1091#1095#1077#1085#1080#1082#1086#1084
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 80
    Top = 216
    Width = 244
    Height = 16
    Caption = '11'#1080#1084'-1 '#1082#1083#1072#1089#1089#1072', '#1090#1077#1086#1088#1080#1090#1080#1095#1077#1089#1082#1086#1075#1086' '#1083#1080#1094#1077#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 80
    Top = 232
    Width = 236
    Height = 16
    Caption = 'Gaudeamus, '#1044#1077#1084#1095#1077#1085#1082#1086' '#1040#1083#1077#1082#1089#1072#1085#1076#1088#1086#1084
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 80
    Top = 248
    Width = 146
    Height = 16
    Caption = 'mailto: alex@ritlabs.com'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    OnClick = Label6Click
  end
  object Label9: TLabel
    Left = 80
    Top = 264
    Width = 156
    Height = 16
    Caption = 'http://www.gaudeamus.md'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    OnClick = Label8Click
  end
  object Label7: TLabel
    Left = 360
    Top = 5
    Width = 9
    Height = 13
    Caption = 'X'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    OnClick = Label7Click
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
  end
end
