object ParamsForm: TParamsForm
  Left = 561
  Top = 19
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
  ClientHeight = 461
  ClientWidth = 211
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 211
    Height = 461
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    TabPosition = tpBottom
    object TabSheet1: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 203
        Height = 435
        Align = alClient
        TabOrder = 0
        object Label1: TLabel
          Left = 8
          Top = 16
          Width = 105
          Height = 13
          Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1092#1088#1072#1082#1090#1072#1083#1072':'
        end
        object Label2: TLabel
          Left = 8
          Top = 72
          Width = 62
          Height = 13
          Caption = 'F ('#1072#1082#1089#1080#1086#1084#1072'):'
        end
        object Label3: TLabel
          Left = 8
          Top = 112
          Width = 31
          Height = 13
          Caption = 'NewF:'
        end
        object Label5: TLabel
          Left = 8
          Top = 144
          Width = 10
          Height = 13
          Caption = 'X:'
        end
        object Label6: TLabel
          Left = 8
          Top = 168
          Width = 10
          Height = 13
          Caption = 'Y:'
        end
        object Label7: TLabel
          Left = 8
          Top = 216
          Width = 10
          Height = 13
          Caption = 'B:'
        end
        object Label8: TLabel
          Left = 8
          Top = 288
          Width = 71
          Height = 13
          Caption = #1050#1086#1083'-'#1074#1086' '#1096#1072#1075#1086#1074':'
        end
        object Label9: TLabel
          Left = 8
          Top = 312
          Width = 28
          Height = 13
          Caption = #1059#1075#1086#1083':'
        end
        object Label10: TLabel
          Left = 72
          Top = 312
          Width = 14
          Height = 13
          Caption = 'PI*'
        end
        object Label11: TLabel
          Left = 136
          Top = 312
          Width = 5
          Height = 13
          Caption = '/'
        end
        object Label12: TLabel
          Left = 8
          Top = 336
          Width = 50
          Height = 13
          Caption = #1053#1072#1095'. '#1091#1075#1086#1083':'
        end
        object Label13: TLabel
          Left = 72
          Top = 336
          Width = 14
          Height = 13
          Caption = 'PI*'
        end
        object Label14: TLabel
          Left = 136
          Top = 336
          Width = 5
          Height = 13
          Caption = '/'
        end
        object Label4: TLabel
          Left = 8
          Top = 360
          Width = 100
          Height = 13
          Caption = #1043#1086#1090#1086#1074#1099#1077' '#1092#1088#1072#1082#1090#1072#1083#1099':'
        end
        object Label15: TLabel
          Left = 8
          Top = 192
          Width = 10
          Height = 13
          Caption = 'Z:'
        end
        object ViewButton: TButton
          Left = 120
          Top = 400
          Width = 75
          Height = 25
          Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnClick = ViewButtonClick
        end
        object MinusButton: TButton
          Left = 88
          Top = 400
          Width = 25
          Height = 25
          Caption = '+'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = MinusButtonClick
        end
        object PlusButton: TButton
          Left = 56
          Top = 400
          Width = 25
          Height = 25
          Caption = '-'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
          OnClick = PlusButtonClick
        end
        object NameEdit: TEdit
          Left = 8
          Top = 32
          Width = 185
          Height = 21
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
        end
        object AxiomEdit: TEdit
          Left = 8
          Top = 88
          Width = 185
          Height = 21
          ParentShowHint = False
          ShowHint = True
          TabOrder = 4
        end
        object NewFEdit: TEdit
          Left = 48
          Top = 112
          Width = 145
          Height = 21
          ParentShowHint = False
          ShowHint = True
          TabOrder = 5
        end
        object GroupBox2: TGroupBox
          Left = 8
          Top = 56
          Width = 185
          Height = 6
          TabOrder = 6
        end
        object StepsEdit: TSpinEdit
          Left = 88
          Top = 280
          Width = 105
          Height = 22
          MaxValue = 0
          MinValue = 0
          ParentShowHint = False
          ShowHint = True
          TabOrder = 7
          Value = 3
        end
        object Angle1Edit: TEdit
          Left = 88
          Top = 304
          Width = 49
          Height = 21
          TabOrder = 8
          Text = '1'
        end
        object Angle2Edit: TEdit
          Left = 144
          Top = 304
          Width = 49
          Height = 21
          TabOrder = 9
          Text = '3'
        end
        object NewXEdit: TEdit
          Left = 48
          Top = 136
          Width = 145
          Height = 21
          ParentShowHint = False
          ShowHint = True
          TabOrder = 10
        end
        object NewYEdit: TEdit
          Left = 48
          Top = 160
          Width = 145
          Height = 21
          ParentShowHint = False
          ShowHint = True
          TabOrder = 11
        end
        object NewBEdit: TEdit
          Left = 48
          Top = 208
          Width = 145
          Height = 21
          ParentShowHint = False
          ShowHint = True
          TabOrder = 12
        end
        object StartAngle1Edit: TEdit
          Left = 88
          Top = 328
          Width = 49
          Height = 21
          TabOrder = 13
        end
        object StartAngle2Edit: TEdit
          Left = 144
          Top = 328
          Width = 49
          Height = 21
          TabOrder = 14
        end
        object ReadyCombo: TComboBox
          Left = 8
          Top = 376
          Width = 185
          Height = 22
          Style = csOwnerDrawFixed
          ItemHeight = 16
          ParentShowHint = False
          ShowHint = True
          TabOrder = 15
          OnChange = ReadyComboChange
        end
        object NewZEdit: TEdit
          Left = 48
          Top = 184
          Width = 145
          Height = 21
          ParentShowHint = False
          ShowHint = True
          TabOrder = 16
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086
      ImageIndex = 1
      object GroupBox3: TGroupBox
        Left = 0
        Top = 0
        Width = 201
        Height = 313
        Caption = #1062#1074#1077#1090#1072
        TabOrder = 0
        object Label16: TLabel
          Left = 8
          Top = 16
          Width = 105
          Height = 13
          Caption = #1050#1086#1083#1080#1095#1077#1090#1089#1090#1074#1086' '#1094#1074#1077#1090#1086#1074':'
        end
        object SpinEdit1: TSpinEdit
          Left = 8
          Top = 32
          Width = 185
          Height = 22
          MaxValue = 28
          MinValue = 1
          TabOrder = 0
          Value = 1
          OnChange = SpinEdit1Change
        end
        object ColorAsTreeChk: TCheckBox
          Left = 8
          Top = 288
          Width = 185
          Height = 17
          Hint = #1055#1088#1080#1084#1077#1085#1080#1084#1086' '#1090#1086#1083#1100#1082#1086' '#1076#1083#1103' '#1092#1088#1072#1082#1090#1072#1083#1086#1074' '#1089#1086#1076#1077#1088#1078#1072#1097#1080#1093' [, ] '#1086#1087#1077#1088#1072#1090#1086#1088#1099
          Caption = #1050#1088#1072#1089#1080#1090#1100' '#1086#1090#1076#1077#1083#1100#1085#1086' '#1082#1072#1078#1076#1091#1102' '#1074#1077#1090#1074#1100
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
        end
      end
      object GroupBox4: TGroupBox
        Left = 0
        Top = 320
        Width = 201
        Height = 113
        Caption = #1044#1088#1091#1075#1086#1077
        TabOrder = 1
        object DynamicWidthChk: TCheckBox
          Left = 8
          Top = 16
          Width = 185
          Height = 17
          Caption = #1048#1079#1084#1077#1085#1103#1090#1100' '#1090#1086#1083#1097#1080#1085#1091' '#1089#1090#1074#1086#1083#1072
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object DoUpdateChk: TCheckBox
          Left = 8
          Top = 33
          Width = 185
          Height = 16
          Hint = #1047#1072#1084#1077#1076#1083#1103#1077#1090' '#1088#1072#1073#1086#1090#1091
          Caption = #1054#1073#1085#1086#1074#1083#1103#1090#1100' '#1088#1080#1089#1091#1085#1086#1082' '#1087#1088#1080' '#1087#1086#1089#1090#1088#1086#1077#1085#1080#1080
          Checked = True
          ParentShowHint = False
          ShowHint = True
          State = cbChecked
          TabOrder = 1
        end
      end
    end
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Options = [cdFullOpen, cdAnyColor]
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 40
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object SaveBmpItem: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082' .bmp'
        OnClick = SaveBmpItemClick
      end
      object SaveJpgItem: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082' .jpg'
        OnClick = SaveJpgItemClick
      end
      object SaveIntItem: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074#1086' '#1074#1085#1091#1090#1088#1077#1085#1085#1077#1084' '#1092#1086#1088#1084#1072#1090#1077
        OnClick = SaveIntItemClick
      end
      object LoadItem: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1088#1072#1082#1090#1072#1083' '#1080#1079' '#1092#1072#1081#1083#1072
        OnClick = LoadItemClick
      end
      object N8: TMenuItem
        Caption = '-'
      end
      object CloseItem: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = CloseItemClick
      end
    end
    object N2: TMenuItem
      Caption = #1071#1079#1099#1082
      object RussianItem: TMenuItem
        Caption = #1056#1091#1089#1089#1082#1080#1081
        OnClick = RussianItemClick
      end
      object EnglishItem: TMenuItem
        Caption = #1040#1085#1075#1083#1080#1081#1089#1082#1080#1081
        OnClick = EnglishItemClick
      end
    end
    object N3: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object AboutItem: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = AboutItemClick
      end
    end
  end
end
