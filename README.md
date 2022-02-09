Bienvenue sur ce projet utilisateur LINUX

 $$$$$$\  $$\   $$\  $$$$$$\  $$\   $$\ $$$$$$$$\ 
$$  __$$\ $$$\  $$ |$$  __$$\ $$ | $$  |$$  _____|
$$ /  \__|$$$$\ $$ |$$ /  $$ |$$ |$$  / $$ |      
\$$$$$$\  $$ $$\$$ |$$$$$$$$ |$$$$$  /  $$$$$\    
 \____$$\ $$ \$$$$ |$$  __$$ |$$  $$<   $$  __|   
$$\   $$ |$$ |\$$$ |$$ |  $$ |$$ |\$$\  $$ |      
\$$$$$$  |$$ | \$$ |$$ |  $$ |$$ | \$$\ $$$$$$$$\ 
 \______/ \__|  \__|\__|  \__|\__|  \__|\________|


 1 - COMPILATION :
    librairies nécessaires -> SDL2 & SDL2_ttf
    Commande de compilation -> g++ classes.cpp main.cpp visual.cpp -lSDL2 -lSDL2_ttf -o snake

2 - JOUER AU JEU :
    lancer le jeu -> ./snake
    objectif :
        -> manger le plus de fruit possible
        -> ne pas sortir des bordures du jeu
        -> ne pas faire de colision avec son propre corp

3- COMMANDES :
    UP -> se diriger vers le haut ( ne fonctionne pas si le serpent descent )
    DOWN -> se diriger vers le bas ( ne fonctionne pas si le serpent monte )
    RIGHT -> se diriger vers la droite ( ne fonctionne pas si le serpent va vers la gauche )
    DOWN -> se diriger vers la gauche ( ne fonctionne pas si le serpent va vers la droite )