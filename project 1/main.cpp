#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
        int card[8] = {1, 2, 3, 4, 5, 6, 7, 8}, random, i, x, y;
        srand(time(NULL));
        for(i = 0; i < 8; i++) {
                random = rand() % 8;
                if(card[random] == 9) {
                        --i;
                        continue;
                }
                else{
                        cout << card[random] << ' ';
                        card[random] = 9;
                }
        }
        int game_count = 180, mana, mana_origin,  card_have[4], enemy_position_x, enemy_position_y;
        char game_overview[22][53], game_detail[22][53];
	while(1){
		enemy_position_x = 0;
		if(game_count <= 100)
			enemy_position_y = 23;
		else
			enemy_position_y = 14;
		cin >> game_count >> mana >> card_have[0] >> card_have[1] >> card_have[2] >> card_have[3];
		cin.ignore();
		for(i = 0; i < 22; i++) 
			cin.getline(game_overview[i], 53);
		for(i = 0; i < 22; i++)	
			cin.getline(game_detail[i], 53);
		if(game_count % 4 == 0 || game_count % 4 == 1) {
			for(x = 3; x < 19 && enemy_position_x == 0; x++)
       	        		for(y = 16; y <= 11 && enemy_position_x == 0; y--) {
        	                        if(game_detail[x][y] != 32) {
                                	        if(x <= 10)
							enemy_position_x = 3 + rand() % 4;
						else
							enemy_position_x = 15 + rand() % 4;
                                	        enemy_position_y = 11;
					}
                	        }
			for(x = 3; x < 19 && enemy_position_x == 0; x++)
				for(y = 40; y >= 30 && enemy_position_x == 0; y--) {
					if(game_detail[x][y] != 32)
						enemy_position_x = x;
				}
			if(enemy_position_x == 0)
				enemy_position_x = 5;
		}
		else{
			for(x = 18; x >= 3 && enemy_position_x == 0; x--)
                                for(y = 16; y <= 11 && enemy_position_x == 0; y--) {
                                        if(game_detail[x][y] != 32) {
                                                if(x <= 10)
                                                        enemy_position_x = 3 + rand() % 4;
                                                else
                                                        enemy_position_x = 15 + rand() % 4;
                                                enemy_position_y = 11;
                                        }
                                }
                        for(x = 18; x >= 3 && enemy_position_x == 0; x--)
                                for(y = 40; y >= 30 && enemy_position_x == 0; y--) {
                                        if(game_detail[x][y] != 32)
                                                enemy_position_x = x;
                                }
			if(enemy_position_x == 0)
				enemy_position_x = 16;
		}
		while(mana != -1) {
			switch(mana){
				case 0:
					cout << '0' << endl;
					mana = -1;
					break;
				case 1:
					cout << '0' << endl;
					mana = -1;
					break;
				case 2:
					for(i = 0; i < 4 && mana != -1; i++) {
						if(card_have[i] == 5) {
							cout << "1 5 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
							mana = -1;
						}
					} 
					if(mana != -1)
                                                --mana;
					break;
				case 3:
					for(i = 0; i < 4 && mana != -1; i++){
						if(card_have[i] == 1 || card_have[i] == 3 || card_have[i] == 4 || card_have[i] == 6 || card_have[i] == 7 || card_have[i] == 8){
							cout << "0" << endl;
							mana = -1;
						}	
					}
					for(i = 0; i < 4 && mana != -1; i++) {
						if(card_have[i] == 2){
							cout << "1 2 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
							mana = -1;
						}	
					}
					if(mana != -1)
                                                --mana;
					break;
				case 4:
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 1 || card_have[i] == 4 || card_have[i] == 7 || card_have[i] == 8){
                                                        cout << "0" << endl;
							mana = -1;
                                                }
                                        }
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 3){
                                                	cout << "1 3 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
							mana = -1;
						}
                                        }
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 4){
                                                        cout << "1 4 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
                                                        mana = -1;
                                                }
                                        }
					if(mana != -1)
                                                --mana;
					break;
				case 5:
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 4 || card_have[i] == 7){
                                                        cout << "0" << endl;
                                                        mana = -1;
                                                }
                                        }
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 8){
                                                        cout << "1 8 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
                                                        mana = -1;
                                                }
                                        }
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 1){
                                                        cout << "1 1 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
                                                        mana = -1;
                                                }
                                        }
					if(mana != -1)
						--mana;
					break;
				case 6:
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 4 || card_have[i] == 7){
                                                        cout << "0" << endl;
                                                        mana = -1;
                                                }
                                        }
					if(mana != -1)
						--mana;
					break;
				case 7:
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 7){
                                                        cout << "0" << endl;
                                                        mana = -1;
                                                }
                                        }
					for(i = 0; i < 4 && mana != -1; i++){
						if(card_have[i] == 4)
							cout << "1 4 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
							mana = -1;
					}
					if(mana != -1)
						--mana;
					break;
				case 8:
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 7){
                                                        cout << "0" << endl;
                                                        mana = -1;
                                                }
                                        }
					for(i = 0; i < 4 && mana != -1; i++) {
						if(card_have[i] == 4){
							cout << "1 4 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
							mana = -1;
						}
					}	
					if(mana != -1)
                                                mana -= 2;
					break;
				case 9:
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 7){
                                                        cout << "1 7 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
                                                        mana = -1;
                                                }
                                        }
					if(mana != -1)
						--mana;
					break;
				case 10:
					for(i = 0; i < 4 && mana != -1; i++){
                                                if(card_have[i] == 7){
                                                        cout << "1 7 " << enemy_position_x << " " << enemy_position_y << endl << "0" << endl;
                                                        mana = -1;
                                                }
                                        }
                                        if(mana != -1)
                                                mana -= 2;
                                        break;
			}
		}
		
	}
}
