object MainForm: TMainForm
  Left = 26
  Top = 20
  Width = 533
  Height = 488
  Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' '#1092#1088#1072#1082#1090#1072#1083#1072
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnCanResize = FormCanResize
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyUp = FormKeyUp
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Region: TImage
    Left = 0
    Top = 0
    Width = 525
    Height = 461
    Align = alClient
    ParentShowHint = False
    PopupMenu = PopupMenu1
    ShowHint = False
    OnDblClick = RegionDblClick
  end
  object PopupMenu1: TPopupMenu
    Left = 360
    Top = 48
    object BuildItem: TMenuItem
      Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1092#1088#1072#1082#1090#1072#1083
      OnClick = BuildItemClick
    end
    object bmp1: TMenuItem
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082' .bmp'
      OnClick = bmp1Click
    end
    object jpeg1: TMenuItem
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082' .jpeg'
      OnClick = jpeg1Click
    end
    object int1: TMenuItem
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074#1086' '#1074#1085#1091#1090#1088#1077#1085#1085#1077#1084' '#1092#1086#1088#1084#1072#1090#1077
      OnClick = int1Click
    end
    object LoadItem: TMenuItem
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1088#1072#1082#1090#1072#1083' '#1080#1079' '#1092#1072#1081#1083#1072
      OnClick = LoadItemClick
    end
    object N1: TMenuItem
      Caption = #1053#1072' '#1074#1077#1089#1100' '#1101#1082#1088#1072#1085
      OnClick = N1Click
    end
  end
  object SaveDialog: TSaveDialog
    FilterIndex = 0
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofEnableSizing]
    Left = 8
    Top = 8
  end
  object OpenDialog: TOpenDialog
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 40
    Top = 8
  end
end
