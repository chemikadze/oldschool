QVector <int> Widget::algoLook(bool cycle /* = false */ )
{
	// выделяем память для результата
	QVector <int> res;
	res.reserve(m_queries.size()+1);
	// направление движения
	enum Direction { LeftToRight, RightToLeft } direction;
	direction = ui->directionBar->value() ? LeftToRight : RightToLeft;

	// текущая позиция
	int pos = ui->startPosition->value();
	res.push_back(pos);

	// подготавливаем очередь для обработки
	m_queries.append(pos);
	qSort(m_queries);
	// копируем в связный список для удаления за O(1)
	QLinkedList <int> unread;
	foreach (int val, m_queries)
		unread.append(val);
	// итератор текущей позиции
	QLinkedList <int>::iterator it;
	// находим первоначальную позицию в списке
	if (direction == LeftToRight)
		for (it = unread.begin(); *it!=pos; ++it);
	else
		for (it = unread.end()-1; *it!=pos; --it);

	// пока есть куда переходить
	while (unread.count()-1)
	{
		if (direction == LeftToRight)   // если движемся направо
		{
			if (it+1 != unread.end())   // если не крайний
			{
				moveHead(pos, *(++it)); // перемещаемся
				res.push_back(pos);
				unread.erase(it-1);     // и удаляем обработанный
			}
			else
			{                           // если крайний
				if (cycle)              // если C-LOOK
				{
					unread.erase(it);   // удаляем текущую позицию
					it = unread.begin();// переходим в начало
					moveHead(pos, *it);
					res.push_back(pos);
				}
				else                    // если LOOK
				{                       // меняем направление
					direction = RightToLeft;
				}
			}
		}
		else
		{
			if (it != unread.begin())   // если не крайний
			{
				moveHead(pos, *(--it)); // перемещаемся
				res.push_back(pos);
				unread.erase(it+1);     // и удаляем прошлый
			}
			else
			{
				if (cycle)              // если C-LOOK
				{
					unread.erase(it);   // удаляем обработанный
					it = unread.end()-1;
					moveHead(pos, *(it));// перемещаемся
					res.push_back(pos);
				}
				else                    // если LOOK
				{                       // меняем направление
					direction = LeftToRight;
				}
			}
		}
	}

	return res;                         // возвращаем результат
}
