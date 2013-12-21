unit Lang;

interface
const
  LangArray: array[0..22, 0..1] of String = (
    {0}('����������', 'Stop'),
    {1}('���������', 'Build'),
    {2}('�������� BMP', 'BMP Image'),
    {3}('�������� JPG', 'JPG Image'),
    {4}('���������� ������', 'Internal format'),
    {5}('������', 'Error'),
    {6}('���������� ������� �����������', 'Invalid fractal parameters'),
       ('������ ����', 'Koch''s curve'),
       ('������ ���� (��)', 'Koch''s curve (color)'),
       ('�������� ����', 'Koch''s snowflake'),
       ('������ �������-������', 'Harter-Highway''s Dragon'),
       ('������ �������', 'Ghosper''s curve'),
       ('����� �����������', 'Serpinski carpet'),
       ('������ ��������� 2', 'Gilbert''s curve-2'),
       ('�������', 'Chain'),
       ('������', 'Circle'),
       ('�����', 'Carpet'),
       ('�����', 'Branch'),
       ('������', 'Tree'),
       ('��������', 'Plant'),
       ('��������-2', 'Plant-2'),
       ('������', 'Flower'),
   {22}('������', 'Flower-2')
  );

var
  CurLang: Byte = 1;

implementation

end.
