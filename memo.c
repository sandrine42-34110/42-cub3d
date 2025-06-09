/* -------------------------------------------------------------------------- */
/*                                   bastien                                  */
/* -------------------------------------------------------------------------- */


MAKEFILE
Le makefile, qui est actuellement utilisé fonctionne pour Mac (et Linux normalement), mais il est testé que sur Mac.
Sinon il faut que tu echanges le Makefile avec  Makefile qu il y a dans Old .
Renomme celui que tu mettra dans le old avant  (celui À la racine du dossier cub3d Doit être nommé Makefile sans rien d autre) Et permute les après

J ai  modifié dans init Player, la position de base Du joueur en le déplaçant d une demi- case, pour qu il soit au milieu.
Du joueur déplaçant d une demi- cazes, pour qu il soit au milieu.
À la base, on gérait ça dans l affichage en déplaçant de tile_size/ 2 Mais ça nous crée un décalage du point par rapport au bord droit, on restait décalé d une demie case

j ai retravaillé la fonction new_pos_player Et déplace les init minimap et player dans init mlx
Celle qui est commenté En dessous de celle qui est active, c est un test 
Qui n est pas concluant pour ne pas avoir le petit faire retour quand tu arrives sur un bord.
Par exemple, quand on est à 3,8 qu on fait un déplacement et qu on passe à 3,925, 
il faudrait s arrêter à 3,9 pour ne pas aller complètement au bord de la map pour s éviter quelques complications pour après

Le sens des touches est aussi complètement inversée le haut va vers le bas la gauche vers la droite et vice versa

je n ai pas touché au valgrind...

pour la suite :
mettre un petit trait devant le point du joueur pour définir dans quelle orientation on est Et qui s arrête lorsqu il rencontre un mur
Diffuser ce dans un rayon de - 45 et 45° de part et d autres de ce premier trait
 Dessin de l image, 3D sur l écran



/* -------------------------------------------------------------------------- */
/*                                  sandrine                                  */
/* -------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------- */
/*                                    tests                                   */
/* -------------------------------------------------------------------------- */

forbiden.cub -> gerer les espaces dans la map et/ou les zones sans player?? 
				Dans ce cas ca se complique pour le check de la map car flood_fill gere que la zone qui contient le player

texture_dir.cub -> gerer les bons chemins des texture (dans init mlx)
texture_forbidden.cub -> idem texture_dir.cub


Convention orientation pixel dans fenetre
Y  X->
|
v