// Вариант 1
// Необходимо смоделировать атаку замка злым драконом.
// 1) Реализовать классы:
// А) Замок со свойствами: количество башень = 10, Башня*. Башни в замке
// закольцованы (т.е. 1 башня соединена с 10)
// Б) Класс Башня: прочность = 1000, урон = от 75 до 125.
// В) Дракон: живучесть = 10000, урон от 334 до 1000.
// 2) У дракона 3 головы, поэтому каждый ход он атакует выбранную башню и
// 2 смежные с ней (если они существуют и еще не уничтожены). После хода
// дракона башни атакуют в ответ (атакуют только Башни, находящиеся от
// центральной головы дракона не далее 3 ед.). Урон для всех объектов каждый ход
// генерируется заново. Реализовать 2 варианта событий:
// - Дракон каждый ход выбирает новую башню и бьет ее (если она не
// разрушена, иначе выбирает другую)
// - Дракон бьют выбранную башню до ее уничтожения
// 3) После окончания сражения вывести:
// а) Победителя. Если это Замок, то количество неразрушенных башень и их
// прочность. Если это Дракон, то его оставшуюся живучесть.
// б) Нанесенный урон обеими сторонами конфликта (Считается полный урон,
// даже если он вышел за пределы живучести атакуемого).
// в) Подобрать живучесть дракона так, чтобы победить могли обе стороны.


#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class  Tower {
    private:
        int tower_HP = 1000;
        int min_tower_DMG = 75;
        int MAX_TOWER_DMG = 125;
    public:        
        int attack_tower(){
            return rand() % (MAX_TOWER_DMG-min_tower_DMG) + min_tower_DMG; 
        }

        void get_DMG_tower(int DMG){
            tower_HP -= DMG;
            
        }
        
        int return_tower_HP(){
            return tower_HP;
        }

};

class Dragon {
    private:
        int dragon_HP = 3000;
        int min_dragon_DMG = 334;
        int max_dragon_DMG = 1000;

    public:
        int attack_dragon(){
            return rand() % (max_dragon_DMG-min_dragon_DMG) + min_dragon_DMG;
        }

        void  get_DMG_dragon(int DMG){
            dragon_HP -= DMG;
        }
        int return_dragon_HP(){
            return dragon_HP;
        }

        int tower_choise(int Coutn_tower){
            return rand() % Coutn_tower;
        }
        int type_attack(){
            return rand()%1;
        }
};

class Castle {
    private:
        const int MAX_TOWER = 10;
        vector<Tower> vec_tower;
    public:
        Castle(){
            vec_tower.resize(MAX_TOWER);
        }
        
        bool castle_alive(){
            for (int i = 0; i<MAX_TOWER; i++ ){
                if ( vec_tower[i].return_tower_HP() > 0 ) {
                    return true;
                }
            }
            return false; 
        }
        int castle_MAX_TOWER(){
            return MAX_TOWER;
        }
        int castle_tower_HP(int num_tower){
            return vec_tower[num_tower].return_tower_HP();
        }

        int castle_tower_get_DMG(int num_tower,int DMG){
            num_tower = (num_tower> -1 && num_tower < MAX_TOWER) ? num_tower : abs(MAX_TOWER - abs(num_tower));
            if (vec_tower[num_tower].return_tower_HP() > 0 ) vec_tower[num_tower].get_DMG_tower(DMG);;
            return DMG;
        }

        int castle_tower_attack(int num_tower) {
            int DMG = 0;
            int tower_index;
            const int near_tower = 3;
            for (int i = -near_tower; i <= near_tower ; i++ ) {
                tower_index = (num_tower + i > -1 && num_tower + i < MAX_TOWER) ? num_tower + i : abs(MAX_TOWER - abs(num_tower + i));
                if (vec_tower[tower_index].return_tower_HP() > 0) DMG += vec_tower[tower_index].attack_tower();
            }
            return DMG;
        }
        void return_tower_info(){
            int whole_towers = 0; 
            for (int i = 0 ; i < MAX_TOWER ; i++) {
                if (vec_tower[i].return_tower_HP() > 0) {
                    whole_towers++;
                    cout << "Здоровье башни " << i << " : " << vec_tower[i].return_tower_HP() << endl; 
                }
            }
            cout << "Количество оставшихся башень : " << whole_towers << endl;
        }
};

int main(){
    srand(time( 0 ));
    int rand_tower,i = 0;
    int summ_dragon_DMG = 0, summ_tower_DMG = 0, tower_DMG = 0, type_dragon_attack = 0;
    Dragon my_dragon;
    Castle my_castle;
    while (my_dragon.return_dragon_HP() > 0){
        if (type_dragon_attack == 0) {
            rand_tower = my_dragon.tower_choise(my_castle.castle_MAX_TOWER());
            type_dragon_attack = my_dragon.type_attack();
        }
        if (my_castle.castle_tower_HP(rand_tower) > 0){
            summ_dragon_DMG += my_castle.castle_tower_get_DMG(rand_tower - 1,my_dragon.attack_dragon());
            summ_dragon_DMG += my_castle.castle_tower_get_DMG(rand_tower,my_dragon.attack_dragon());
            summ_dragon_DMG += my_castle.castle_tower_get_DMG(rand_tower + 1,my_dragon.attack_dragon());
        }
        else if (!my_castle.castle_alive()) break;
        else {
            type_dragon_attack = 0;
            continue;
        } 

        tower_DMG = my_castle.castle_tower_attack(rand_tower);
        summ_tower_DMG += tower_DMG;
        my_dragon.get_DMG_dragon(tower_DMG);
    }

    if (my_dragon.return_dragon_HP() > 0 ) {
        cout << "Победил дракон" << endl << "Оставшееся здоровье дракона :" << my_dragon.return_dragon_HP() << endl;
    }
    else {
        cout << "Победил замок" << endl;
        my_castle.return_tower_info();
    }
    cout <<"Суммарный урон дракона : " << summ_dragon_DMG << endl;
    cout <<"Суммарный урон башен : " << summ_tower_DMG << endl;
    cout <<"Суммарный урон : " << summ_tower_DMG + summ_dragon_DMG << endl;
    return 0;
}