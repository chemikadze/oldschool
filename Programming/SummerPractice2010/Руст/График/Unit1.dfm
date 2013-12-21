object Form1: TForm1
  Left = 185
  Top = 234
  Width = 599
  Height = 353
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 441
    Height = 297
  end
  object Label1: TLabel
    Left = 456
    Top = 8
    Width = 7
    Height = 13
    Caption = 'A'
  end
  object Label2: TLabel
    Left = 456
    Top = 48
    Width = 7
    Height = 13
    Caption = 'B'
  end
  object Label3: TLabel
    Left = 456
    Top = 96
    Width = 109
    Height = 13
    Caption = #1051#1077#1074#1072#1103' '#1075#1088#1072#1085#1080#1094#1072' '#1082#1086#1088#1085#1103
  end
  object Label4: TLabel
    Left = 456
    Top = 136
    Width = 109
    Height = 13
    Caption = #1055#1088#1072#1074#1072#1103' '#1075#1088#1072#1080#1094#1072' '#1082#1086#1088#1085#1103
  end
  object Label5: TLabel
    Left = 456
    Top = 264
    Width = 30
    Height = 13
    Caption = #1054#1090#1074#1077#1090
  end
  object Label6: TLabel
    Left = 456
    Top = 176
    Width = 47
    Height = 13
    Caption = #1058#1086#1095#1085#1086#1089#1090#1100
  end
  object Edit1: TEdit
    Left = 456
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '5'
    OnKeyPress = Edit2KeyPress
  end
  object Edit2: TEdit
    Left = 456
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '2'
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 456
    Top = 112
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '-1'
  end
  object Edit4: TEdit
    Left = 456
    Top = 152
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '1'
  end
  object Button1: TButton
    Left = 480
    Top = 232
    Width = 75
    Height = 25
    Caption = #1079#1072#1087#1091#1089#1082
    TabOrder = 4
    OnClick = Button1Click
  end
  object Edit5: TEdit
    Left = 456
    Top = 192
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '0,0001'
  end
  object Edit6: TEdit
    Left = 456
    Top = 280
    Width = 121
    Height = 21
    TabOrder = 6
  end
end
