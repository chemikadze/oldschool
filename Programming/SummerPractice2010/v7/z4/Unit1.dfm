object Form1: TForm1
  Left = 230
  Top = 252
  Width = 405
  Height = 348
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 248
    Width = 35
    Height = 13
    Caption = #1043#1088#1091#1087#1087#1072
  end
  object DBGStud: TDBGrid
    Left = 8
    Top = 8
    Width = 385
    Height = 120
    DataSource = DSStud
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Name'
        Title.Caption = #1048#1084#1103
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Sex'
        PickList.Strings = (
          #1052#1091#1078#1089#1082#1086#1081#13
          #1046#1077#1085#1089#1082#1080#1081)
        Title.Caption = #1055#1086#1083
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Group'
        Title.Caption = #1043#1088#1091#1087#1087#1072
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Mark'
        Title.Caption = #1054#1094#1077#1085#1082#1072
        Visible = True
      end>
  end
  object RGSort: TRadioGroup
    Left = 8
    Top = 136
    Width = 185
    Height = 105
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
    ItemIndex = 0
    Items.Strings = (
      #1048#1084#1103
      #1055#1086#1083
      #1043#1088#1091#1087#1087#1072)
    TabOrder = 1
    OnClick = RGSortClick
  end
  object RGFiltr: TRadioGroup
    Left = 208
    Top = 136
    Width = 185
    Height = 105
    Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103
    ItemIndex = 0
    Items.Strings = (
      #1042#1077#1089#1100' '#1089#1087#1080#1089#1086#1082
      #1070#1085#1086#1096#1080
      #1044#1077#1074#1091#1096#1082#1080)
    TabOrder = 2
    OnClick = RGFiltrClick
  end
  object EFind: TEdit
    Left = 8
    Top = 264
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object BFind: TButton
    Left = 136
    Top = 264
    Width = 73
    Height = 25
    Caption = #1060#1080#1083#1100#1090#1088#1086#1074#1072#1090#1100
    TabOrder = 4
    OnClick = BFindClick
  end
  object Button1: TButton
    Left = 216
    Top = 264
    Width = 75
    Height = 25
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 5
    OnClick = Button1Click
  end
  object TStud: TTable
    Active = True
    DatabaseName = 'STUDENTS'
    TableName = 'Student.db'
    Left = 328
    Top = 8
  end
  object DSStud: TDataSource
    DataSet = TStud
    Left = 360
    Top = 8
  end
end
