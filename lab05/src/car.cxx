#include "car.h"

// Является ли автомобиль грузовым? (проверка на простоту)
Carcass::Carcass(size_t num)
{
	is_freight = false;

	for (size_t i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return;

	is_freight = true;
}

// Вычисление мощности движка (a^x)
Engine::Engine(int a, int x)
{
	engine_power = a;

	for (int i = 0; i < x; i++)
		engine_power *= a;
}

// Вычисление числа колес (n-ое число Фибоначчи)
Wheels::Wheels(int n)
{
	size_t f1 = 1, f2 = 1;
	this->wheels_cnt = f1;

	for (int i = 2; i < n; i++)
	{
		wheels_cnt = f1 + f2;
		f1 = f2;
		f2 = wheels_cnt;
	}
}

void Car::create_engine(size_t task_num)
{
	Logger::log_current_event(task_num, "Part 2 | Start");

	if (carcass->is_freight) 
		engine = std::unique_ptr<Engine>(new Engine(10, 150000));
	else
		engine = std::unique_ptr<Engine>(new Engine(5, 150000));

	Logger::log_current_event(task_num, "Part 2 | End  ");
}

void Car::create_carcass(size_t task_num)
{
	Logger::log_current_event(task_num, "Part 1 | Start");
	carcass = std::unique_ptr<Carcass>(new Carcass(27644437));
	Logger::log_current_event(task_num, "Part 1 | End  ");
}

void Car::create_wheels(size_t task_num)
{
	Logger::log_current_event(task_num, "Part 3 | Start");
	wheels = std::unique_ptr<Wheels>(new Wheels(engine->engine_power));
	Logger::log_current_event(task_num, "Part 3 | End  ");
}