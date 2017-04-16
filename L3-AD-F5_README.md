# EFREI L3-AD-F5
Projet d'aide à la décision de PSC 

Ce programme a été réalisé avec le logiciel Visual Studio 2015 que vous pouvez obtenir ici : https://www.visualstudio.com/fr/vs/cplusplus/

Pour fonctionner, le programme a besoin de la bibliothèque STL et experimental/filesystem disponible avec C++11

Attention pour fonctionner l'exécutable du fichier doit être mis dans le MÊME dossier que les fichiers de tests.
Si malgré cela, vous vous retrouvez face au message d'erreur suivant : "[ERREUR] Aucun element du type : .txt n'a ete trouve" faites la démarche suivante :
1) Allez dans le fichier "L3-AD-F5-file_finder.h"
2) Cherchez la ligne #define PATH_PAR_DEFAUT ".\/"
3) Remplacez ce qu'il y a dans les guillemets par le chemin absolu de votre dossier où vous avez mis les fichiers de tests (attention à bien mettre deux antislashs si vous êtes sous Windows)
Exemple de path : D:\\L3-AD-F5

Lors de la sauvegarde de fichier il convient de faire attention au nom choisi car le programme effacera le fichier texte s'il en trouve un du meme nom.