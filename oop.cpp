#include <iostream>

class Father {
	protected:	// видны только классу
		int m;		// значение m спрятано в классе, "инкапсулировано".
					// под инкапсуляцией подразумевают сокрытие данных
					// нужных только для самого класса
	public:		// видны всем
		void setM(int newM)	// метод, устанавливающий M
		{
			std::cout << "Father::setM( " << m << ")" << std::endl;
			m = newM;
		}

		int getM()	// метод, возвращающий M
		{
			std::cout << "Father::getM()" << std::endl << "\tm = " << m << std::endl;
			return m;
		}
		
		virtual void doSomething()
		{
			std::cout << "Father::doSomething()" << std::endl;
		}

		Father()
		{
			std::cout << "Father::Father()" << std::endl;
			m = 0;
		}
};

class Son: public Father {	// наследуем
	public:
		virtual void doSomething()	// полиморфизм - когда разные методы разных классов делают разные вещи
		{
			std::cout << "Son::doSomething()" << std::endl;
		}

		int getM_on_10()		// новый метод
		{
			std::cout << "Son::getM_on_10()" << std::endl << "\tm*10 = " << m*10 << std::endl;
			return m*10;
		}
};

class Daughter: public Father {
	public:
		virtual void doSomething()
		{
			std::cout << "Daughter::doSomething()" << std::endl;
		}
};

int main()
{
	Father *o;
	o = new Father();
	o->setM(5);
	o->getM();
	o->doSomething();
	delete o;

	o = new Son();	// обрати внимание, Father для Son и Daughter - абстрактный класс, присваивание корректно
	o->doSomething(); // выполнится Son::doSomething()
	o->setM(10050);
	((Son*)o)->getM_on_10(); // приведение к типу Son чтобы вызвать метод
	delete o;

	o = new Daughter();
	o->doSomething();	// выполнится Daughter::doSomething()
	delete o;
}
