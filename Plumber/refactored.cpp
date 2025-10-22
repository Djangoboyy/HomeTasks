#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

const int MAP_WIDTH = 80;
const int MAP_HEIGHT = 25;

enum ObjectType {
	BRICK = '#',
	EMPTY_BOX = '-',
	ENEMY = 'o',
	FULL_BOX = '?',
	MARIO = '@',
	MONEY = '$',
	WIN_BRICK = '+'
};

struct GameObject {
	float x, y;
	float width, height;
	float vertical_speed;
	float horizontal_speed;
	bool is_flying;
	ObjectType type;
};

// Глобальные переменные (вместо класса)
vector<vector<char>> game_map;
GameObject player;
vector<GameObject> bricks;
vector<GameObject> moving_objects;
int current_level = 1;
int score = 0;
const int MAX_LEVEL = 3;

// Функции инициализации
void hide_cursor() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(handle, &cursor_info);
	cursor_info.bVisible = false;
	SetConsoleCursorInfo(handle, &cursor_info);
}

void set_cursor_position(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void initialize_map() {
	game_map.resize(MAP_HEIGHT, vector<char>(MAP_WIDTH + 1, ' '));
	for (int i = 0; i < MAP_HEIGHT; i++) {
		game_map[i][MAP_WIDTH] = '\0';
	}
}

void initialize_object(GameObject& obj, float x, float y, float width, float height, ObjectType type) {
	obj.x = x;
	obj.y = y;
	obj.width = width;
	obj.height = height;
	obj.vertical_speed = 0;
	obj.horizontal_speed = 0.2f;
	obj.is_flying = true;
	obj.type = type;
}

GameObject create_object(float x, float y, float width, float height, ObjectType type) {
	GameObject obj;
	initialize_object(obj, x, y, width, height, type);
	return obj;
}

// Функции физики и коллизий
bool check_collision(const GameObject& obj1, const GameObject& obj2) {
	return (obj1.x + obj1.width > obj2.x &&
	obj1.x < obj2.x + obj2.width &&
	obj1.y + obj1.height > obj2.y &&
	obj1.y < obj2.y + obj2.height);
}

bool is_position_valid(int x, int y) {
	return x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT;
}

void move_map_horizontally(float delta_x) {
	// Проверяем столкновение перед движением
	player.x -= delta_x;
	for (const auto& brick : bricks) {
		if (check_collision(player, brick)) {
			player.x += delta_x;
			return;
		}
	}
	player.x += delta_x;

	// Двигаем все объекты
	for (auto& brick : bricks) {
		brick.x += delta_x;
	}
	for (auto& moving_obj : moving_objects) {
		moving_obj.x += delta_x;
	}
}

void move_object_vertically(GameObject& obj) {
	obj.is_flying = true;
	obj.vertical_speed += 0.05f;
	obj.y += obj.vertical_speed;

	for (auto& brick : bricks) {
		if (check_collision(obj, brick)) {
			if (obj.vertical_speed > 0) {
				obj.is_flying = false;
			}

			// Обработка блоков с монетами
			if (brick.type == FULL_BOX && obj.vertical_speed < 0 && &obj == &player) {
				brick.type = EMPTY_BOX;

				GameObject coin;
				initialize_object(coin, brick.x, brick.y - 3, 3, 2, MONEY);
				coin.vertical_speed = -0.7f;
				moving_objects.push_back(coin);
			}

			obj.y -= obj.vertical_speed;
			obj.vertical_speed = 0;

			// Проверка на завершение уровня
			if (brick.type == WIN_BRICK) {
				current_level++;
				if (current_level > MAX_LEVEL) {
					current_level = 1;
				}
				system("color 2F");
				Sleep(500);
				return; // Уровень перезагрузится в основном цикле
			}
			break;
		}
	}
}

void move_object_horizontally(GameObject& obj) {
	obj.x += obj.horizontal_speed;

	for (const auto& brick : bricks) {
		if (check_collision(obj, brick)) {
			obj.x -= obj.horizontal_speed;
			obj.horizontal_speed = -obj.horizontal_speed;
			return;
		}
	}

	// Для врагов проверяем, не находятся ли они в воздухе
	if (obj.type == ENEMY) {
		GameObject temp = obj;
		move_object_vertically(temp);
		if (temp.is_flying) {
			obj.x -= obj.horizontal_speed;
			obj.horizontal_speed = -obj.horizontal_speed;
		}
	}
}

void check_player_collisions() {
	for (size_t i = 0; i < moving_objects.size(); i++) {
		if (check_collision(player, moving_objects[i])) {
			if (moving_objects[i].type == ENEMY) {
				if (player.is_flying && player.vertical_speed > 0 &&
					player.y + player.height < moving_objects[i].y + moving_objects[i].height * 0.5f) {
					score += 50;
				moving_objects.erase(moving_objects.begin() + i);
				i--;
					} else {
						return; // Рестарт уровня в основном цикле
					}
			} else if (moving_objects[i].type == MONEY) {
				score += 100;
				moving_objects.erase(moving_objects.begin() + i);
				i--;
			}
		}
	}
}

void remove_fallen_objects() {
	for (size_t i = 0; i < moving_objects.size(); i++) {
		if (moving_objects[i].y > MAP_HEIGHT) {
			moving_objects.erase(moving_objects.begin() + i);
			i--;
		}
	}
}

// Функции рендеринга
void clear_map() {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			game_map[i][j] = ' ';
		}
		game_map[i][MAP_WIDTH] = '\0';
	}
}

void place_object_on_map(const GameObject& obj) {
	int start_x = static_cast<int>(round(obj.x));
	int start_y = static_cast<int>(round(obj.y));
	int end_x = static_cast<int>(round(obj.x + obj.width));
	int end_y = static_cast<int>(round(obj.y + obj.height));

	char symbol = static_cast<char>(obj.type);

	for (int x = start_x; x < end_x; x++) {
		for (int y = start_y; y < end_y; y++) {
			if (is_position_valid(x, y)) {
				game_map[y][x] = symbol;
			}
		}
	}
}

void display_score() {
	string score_text = "Score: " + to_string(score);
	for (size_t i = 0; i < score_text.length() && i + 5 < MAP_WIDTH; i++) {
		game_map[1][i + 5] = score_text[i];
	}
}

void render() {
	clear_map();

	// Отрисовка всех объектов
	for (const auto& brick : bricks) {
		place_object_on_map(brick);
	}
	for (const auto& moving_obj : moving_objects) {
		place_object_on_map(moving_obj);
	}
	place_object_on_map(player);
	display_score();

	set_cursor_position(0, 0);
	for (const auto& row : game_map) {
		cout << row.data() << '\n';
	}
}

// Функции управления уровнями
void load_level(int level) {
	system("color 9F");

	bricks.clear();
	moving_objects.clear();
	initialize_object(player, 39, 10, 3, 3, MARIO);
	score = 0;

	switch (level) {
		case 1:
			bricks.push_back(create_object(20, 20, 40, 5, BRICK));
			bricks.push_back(create_object(60, 15, 40, 10, BRICK));
			bricks.push_back(create_object(100, 20, 20, 5, BRICK));
			bricks.push_back(create_object(120, 15, 10, 10, BRICK));
			bricks.push_back(create_object(150, 20, 40, 5, BRICK));
			bricks.push_back(create_object(210, 15, 10, 10, WIN_BRICK));

			bricks.push_back(create_object(30, 10, 5, 3, FULL_BOX));
			bricks.push_back(create_object(50, 10, 5, 3, FULL_BOX));
			bricks.push_back(create_object(70, 5, 5, 3, FULL_BOX));
			bricks.push_back(create_object(80, 5, 5, 3, FULL_BOX));

			bricks.push_back(create_object(60, 5, 10, 3, EMPTY_BOX));
			bricks.push_back(create_object(75, 5, 5, 3, EMPTY_BOX));
			bricks.push_back(create_object(85, 5, 10, 3, EMPTY_BOX));

			moving_objects.push_back(create_object(25, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(80, 10, 3, 2, ENEMY));
			break;

		case 2:
			bricks.push_back(create_object(20, 20, 40, 5, BRICK));
			bricks.push_back(create_object(60, 15, 10, 10, BRICK));
			bricks.push_back(create_object(80, 20, 20, 5, BRICK));
			bricks.push_back(create_object(120, 15, 10, 10, BRICK));
			bricks.push_back(create_object(150, 20, 40, 5, BRICK));
			bricks.push_back(create_object(210, 15, 10, 10, WIN_BRICK));

			moving_objects.push_back(create_object(25, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(80, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(65, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(120, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(160, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(175, 10, 3, 2, ENEMY));
			break;

		case 3:
			bricks.push_back(create_object(20, 20, 40, 5, BRICK));
			bricks.push_back(create_object(80, 20, 15, 5, BRICK));
			bricks.push_back(create_object(120, 15, 15, 10, BRICK));
			bricks.push_back(create_object(160, 10, 15, 15, WIN_BRICK));

			moving_objects.push_back(create_object(25, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(50, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(80, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(90, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(120, 10, 3, 2, ENEMY));
			moving_objects.push_back(create_object(135, 10, 3, 2, ENEMY));
			break;
	}
}

void restart_level() {
	system("color 4F");
	Sleep(500);
	load_level(current_level);
}

// Основной игровой цикл
void run_game() {
	initialize_map();
	hide_cursor();
	load_level(current_level);

	while (GetKeyState(VK_ESCAPE) >= 0) {
		bool need_restart = false;
		bool level_completed = false;

		// Обработка управления
		if (!player.is_flying && GetKeyState(VK_SPACE) < 0) {
			player.vertical_speed = -1.0f;
		}
		if (GetKeyState('A') < 0) {
			move_map_horizontally(1.0f);
		}
		if (GetKeyState('D') < 0) {
			move_map_horizontally(-1.0f);
		}

		// Проверка падения игрока
		if (player.y > MAP_HEIGHT) {
			need_restart = true;
		}

		// Обновление физики
		move_object_vertically(player);
		check_player_collisions();

		for (auto& moving_obj : moving_objects) {
			move_object_vertically(moving_obj);
			move_object_horizontally(moving_obj);
		}

		remove_fallen_objects();
		render();

		if (need_restart) {
			restart_level();
		}

		Sleep(10);
	}
}

int main() {
	run_game();
	return 0;
}
