object Form1: TForm1
  Left = 220
  Top = 133
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 528
  ClientWidth = 738
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    738
    528)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 105
    Height = 16
    Caption = 'tg^2 x + ctg^2 x'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 296
    Width = 125
    Height = 13
    Caption = #1052#1077#1090#1086#1076' '#1087#1088#1103#1084#1086#1091#1075#1086#1083#1100#1085#1080#1082#1086#1074
  end
  object Label3: TLabel
    Left = 8
    Top = 344
    Width = 82
    Height = 13
    Caption = #1052#1077#1090#1086#1076' '#1090#1088#1072#1087#1077#1094#1080#1081
  end
  object Label4: TLabel
    Left = 8
    Top = 392
    Width = 86
    Height = 13
    Caption = #1052#1077#1090#1086#1076' '#1057#1080#1084#1087#1089#1086#1085#1072
  end
  object Label6: TLabel
    Left = 8
    Top = 80
    Width = 79
    Height = 13
    Caption = #1053#1080#1078#1085#1080#1081' '#1087#1088#1077#1076#1077#1083
  end
  object Label7: TLabel
    Left = 8
    Top = 32
    Width = 81
    Height = 13
    Caption = #1042#1077#1088#1093#1085#1080#1081' '#1087#1088#1077#1076#1077#1083
  end
  object Label8: TLabel
    Left = 8
    Top = 128
    Width = 90
    Height = 13
    Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1099#1081' N'
  end
  object Image1: TImage
    Left = 144
    Top = 8
    Width = 587
    Height = 310
    Anchors = [akLeft, akTop, akRight, akBottom]
  end
  object Image2: TImage
    Left = 145
    Top = 325
    Width = 585
    Height = 193
    Anchors = [akLeft, akRight, akBottom]
  end
  object Label5: TLabel
    Left = 8
    Top = 176
    Width = 92
    Height = 13
    Caption = #1052#1072#1089#1096#1090#1072#1073' '#1075#1088#1072#1092#1080#1082#1072
  end
  object Edit1: TEdit
    Left = 8
    Top = 312
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 8
    Top = 360
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 8
    Top = 408
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 2
  end
  object Edit7: TEdit
    Left = 8
    Top = 96
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '0,523598775598'
  end
  object Edit8: TEdit
    Left = 8
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '1,0471975512'
  end
  object Button1: TButton
    Left = 24
    Top = 224
    Width = 75
    Height = 25
    Caption = #1057#1095#1080#1090#1072#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
  object SpinEdit1: TSpinEdit
    Left = 8
    Top = 144
    Width = 121
    Height = 22
    MaxValue = 10000
    MinValue = 1
    TabOrder = 6
    Value = 100
    OnChange = SpinEdit1Change
  end
  object SpinEdit2: TSpinEdit
    Left = 8
    Top = 192
    Width = 121
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 7
    Value = 25
    OnChange = SpinEdit2Change
  end
end
