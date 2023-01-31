void grid(char tab[1][11]);

void show_grid(char tab[10][11]);

void inventory(int *artillerie, int *bombes, int *tactique, int *simple, char niveau);




typedef struct boat_structure boat_structure;
struct boat_structure {

    char orientation;
    int taille;
    int position_Colonne;
    int position_Ligne;

};

void save(int artillerie, int bombes, int tactique, int simple, char mode, char tab_boat[10][11], boat_structure, boat_structure, boat_structure, boat_structure, boat_structure);
void load(int *artillerie, int *bombes, int *tactique, int *simple, char *mode, char tab_boat[10][11], boat_structure *Boat1, boat_structure *Boat2, boat_structure *Boat3, boat_structure *Boat4, boat_structure *Boat5);


int is_alive(char tab_boat[10][11], boat_structure boat, int numero, int couleur);

void boat(boat_structure *boat,int numero_bateau);

void grid_boat(char tab_boat[10][11], boat_structure *Boat1, boat_structure *Boat2, boat_structure *Boat3,boat_structure *Boat4, boat_structure *Boat5);

void fire_bomb(char tab_boat[10][11], char tab[10][11], char mode_de_jeu);

void fire_simple(char tab_boat[10][11], char tab[10][11], char mode_de_jeu);

void fire_tactical(char tab_boat[10][11], char tab[10][11],boat_structure Boat1, boat_structure Boat2, boat_structure Boat3,boat_structure Boat4, boat_structure Boat5, char mode_de_jeu);

void fire_artillery(char tab_boat[10][11], char tab[10][11], char mode_de_jeu);

void mode_active(char tab_boat[10][11],boat_structure *Boat1, boat_structure *Boat2, boat_structure *Boat3,boat_structure *Boat4, boat_structure *Boat5);
