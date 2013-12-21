echo > outtests.inc; for i in /media/KnoRus/Tests/*.txt; do ./tests.py < $i ; done | iconv -f cp1251 -t utf8 >> outtests.inc
