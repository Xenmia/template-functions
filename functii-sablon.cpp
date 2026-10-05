#include <iostream>

template <typename T> void transform_tablou(T* tablou, const size_t size)
{
	auto move_zero = [tablou](const size_t i)
		{
			if (i == 0)
			{
				return;
			}
			for (auto j = i;; j--)
			{
				if (j > 0 && tablou[j - 1] != 0)
				{
					tablou[j] = tablou[j - 1];
					continue;
				}
				tablou[j] = 0;
				break;
			}
		};

	for (auto i = 0; i < size; i++)
	{
		if (tablou[i] == 0)
		{
			move_zero(i);
		}
	}
}

void transform_tablou(char* tablou, const size_t size)
{
	auto move_zero = [tablou](const size_t i)
		{
			for (auto j = i;; j--)
			{
				if (j > 0 && tablou[j - 1] != '0')
				{
					tablou[j] = tablou[j - 1];
					continue;
				}
				tablou[j] = '0';
				break;
			}
		};

	for (auto i = 0; i < size; i++)
	{
		if (tablou[i] == '0')
		{
			move_zero(i);
		}
	}
}

template <typename T> void print_tablou(const T* tablou, const size_t size)
{
	if (size == 0) return;
	std::cout << "[";
	for (auto i = 0; i < size - 1; i++)
	{
		std::cout << tablou[i] << ", ";
	}
	std::cout << tablou[size - 1] << "]\n";
}

int main()
{
	auto opt = -1;
	do
	{
		std::cout << "Introduceti tipul tabloului:\n[1: int, 2: bool, 3: double, 4: char, 0: Iesire]\nOptiunea: ";
		std::cin >> opt;
		if (opt == 0) break;

		std::cout << "Introduceti dimensiunea tabloului: ";
		int n;	std::cin >> n;

		std::cout << "Introduceti datele:\n";
		switch (opt)
		{
		case 1:
		{
			auto* table = new int[n];

			for (int i = 0; i < n; i++)
			{
				std::cout << i + 1 << ": ";
				std::cin >> table[i];
			}
			std::cout << "Inainte de transformare";
			print_tablou(table, n);
			transform_tablou(table, n);
			std::cout << "Dupa transformare";
			print_tablou(table, n);
			delete[] table;
			break;
		}
		case 2:
		{
			auto* table = new bool[n];

			for (int i = 0; i < n; i++)
			{
				std::cout << i + 1 << ": ";
				std::cin >> table[i];
			}

			print_tablou(table, n);
			transform_tablou(table, n);
			print_tablou(table, n);
			delete[] table;
			break;
		}
		case 3:
		{
			auto* table = new double[n];

			for (int i = 0; i < n; i++)
			{
				std::cout << i + 1 << ": ";
				std::cin >> table[i];
			}

			print_tablou(table, n);
			transform_tablou(table, n);
			print_tablou(table, n);
			delete[] table;
			break;
		}
		case 4:
		{
			auto* table = new char[n];

			for (int i = 0; i < n; i++)
			{
				std::cout << i + 1 << ": ";
				std::cin >> table[i];
			}
			fflush(stdin);
			print_tablou(table, n);
			transform_tablou(table, n);
			print_tablou(table, n);
			delete[] table;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida!\n";
			return 1;
		}
		}
	} while (opt != 0);
	return 0;
}