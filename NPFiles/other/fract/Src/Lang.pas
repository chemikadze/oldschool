unit Lang;

interface
const
  LangArray: array[0..22, 0..1] of String = (
    {0}('Остановить', 'Stop'),
    {1}('Построить', 'Build'),
    {2}('Картинка BMP', 'BMP Image'),
    {3}('Картинка JPG', 'JPG Image'),
    {4}('Внутренний формат', 'Internal format'),
    {5}('Ошибка', 'Error'),
    {6}('Информация введена некорректно', 'Invalid fractal parameters'),
       ('Кривая Коха', 'Koch''s curve'),
       ('Кривая Коха (цв)', 'Koch''s curve (color)'),
       ('Снежинка Коха', 'Koch''s snowflake'),
       ('Дракон Хартера-Хайвея', 'Harter-Highway''s Dragon'),
       ('Кривая Госпера', 'Ghosper''s curve'),
       ('Ковер Серпинского', 'Serpinski carpet'),
       ('Кривая Гильберта 2', 'Gilbert''s curve-2'),
       ('Цепочка', 'Chain'),
       ('Кольцо', 'Circle'),
       ('Ковер', 'Carpet'),
       ('Ветка', 'Branch'),
       ('Дерево', 'Tree'),
       ('Растение', 'Plant'),
       ('Растение-2', 'Plant-2'),
       ('Цветок', 'Flower'),
   {22}('Сорняк', 'Flower-2')
  );

var
  CurLang: Byte = 1;

implementation

end.
