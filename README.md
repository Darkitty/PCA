PCA
===

Projet de C avancé - Monoplan

But :
* Réaliser un tableau simple en utilisant des structures avec le langage C
* Tester l'ensemble des fonctions via des tests
* Intégration d'une interface graphique de type GTK

Contexte :
* Cours de programmation C en licence 3 Ingénierie Informatique

Réalisation : [Nicolas Le Gall](http://www.nlegall.fr)

Séance 1
========

- Module pile :
    - type de la pile : LIFO
    - éléments de type double
    - nombre éléments max fixé au démarrage
    - Fonctionnalités (macro définition du pré-processeur sauf création/destruction):
        - création
        - destruction
        - empilement
        - dépilement
        - nombre places restantes
        - nombre places occupées

- Module list :
    - type de la liste : liste chainée
    - noeud = poiteur générique (void *)
    - Fonctionnalités à implanter :
        - création
        - insertion en tête
        - ajout en queue
        - suppression en tête
        - suppression de la première instance dans la liste
        - application d'une fonction sur les données de la liste
        - destruction d'une liste complète

Séance 2
========
Les cellules, formules et évaluation
--------

- Cellule :
    - chaine de caractère contenue dans la cellule
    - double associé à la cellule (0.0 si non calculable)
    - liste des jetons découlant de l'analyse de la formule
    - liste des cellules en dépendances

- Fueille de calcul :
    - nom du fichier
    - nombre de lignes
    - nombre de colonnes
    - liste des cellules existantes

- Formule :
    - résulte de la décomposition du contenu de la cellule
    - ensemble de tokens -> nombre | référence vers une autre cellule | opérateur

Séance 3
========
Graphe des cellules
--------

Mettre en place un tri topologique afin d'évaluer les cellules contenant des références vers d'autres cellules

    D2 - D3 - A4(D3) - A5(A4,D3) - C5(D2,A5)

Séance 4
========
Interface graphique
--------

Mise en place de l'interface graphique avec GTK en utilisant [Glade](https://glade.gnome.org/)