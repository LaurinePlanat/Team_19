/*! on part sur l idee que la fonction FastaReader nous renvoit un vector de sequence d'interet
 * de plus les exeptions : 
 * - le nucleotide est non existant (different du enum type {A, T, C, G}
 * - la position n'existe pas dans le genome
 * - la position correspond a un endroit ou la sequence ne peut pas être calculée
 * comme des exeptions deja repérées dans le FastaReader au moment de la lecture et traitées (dans le main ??)
 * */
 
 
 enum Nucleotide {A, T, C, G}
 /*! Ces nucleotides permettent de referencer les acides amines du code genomique, mais aussi les colonnes du array de tab_matrice */
 
Classe Matrice {
	
	
 Attribut : 

/*! Tableau bi-dimensionnel pour représenter la matrice : un vector (donc dont la taille peut etre variable)
 *  													  contenant des array de 4 (le nombre de nucleotides differents)*/
prive : 
std::vector<array>  tab_matrice (4);
std::vector<std::string> list_seq;
bool exeption_zero_proba(False);



 Fonctions :
 
void (bool?) initialize (Lla longuer du motif et le poid pr chaque nucleotide //////////////////	
/*! Initialise la matrice
 * Se fait en trois etapes : 
 * - appelle a la fonction FastaReader et recupération de la liste de sequence d'interet, qu on stockera ici dans une variable intermediare list_seq pour 
 *   pouvoir y acceder plus tard 
 * - Pour chacune de ces listes : 
 * 			-> lire nucleotide par nucleotide et incrémenter tab_matrice en correspondance [fonction : void lire_seq (std::string seq)]
 * - Caclucler les probabilités [fonction void CalculProba (std::vector<std::array>>)]
 */
 
 
 void CalculProbaMatrice (std::vector<std::array>>);
 /*! Parcourir tab_matrice, pour chaque ligne (p est le numero de la ligne) appeler [void CaclculProbasPosition (double p, double list_seq.size())]
  * Une fois qu'elle est totalement calculee, si exeption_zero_proba alors rediviser chaque probabilite de chaque nucleotide de chaque ligne par 8
  * (double boucle "for" imbriquee) : pour chaque ligne p 
  * appeler [void CalculProbasPosition ( double p, double 8)]
*/
 
 
 void CalculProbasPosition (double p, double diviseur );
 /*! pour une position, va calculer la probabilite de tous les nucleotides 
  * sous forme de boucle de 0 a 3 
  * si tab_matrice[position][i] =  0 (on peut le tester avant de calculer la probabilite pour gagner du temps d execution)
  * pour chaque chaque nucleotide de chaque ligne ajouter 1/4 et passer exeption_zero_proba a TRUE
  * sinon calculer la probabilite du nucleotide s y trouvant, et l'y placer : 
  * tab_matrice[position][i] /= diviseur;
  * */
  
 void lire_seq (str::string seq) ; 
 /*! parcourt la sequence seq et pour chaque nucleotide, met a jour tab_matrice avec la fonction :  void incrementer (Nuceoltide N)*/
 
 
 void incrementer ( Nucleotide N );
 /*! doit incrementer tab_matrice avec le nucleotide N
  * - creation d une nouvelle ligne (push_back) dans le vector de tab_matrice lorsque c est la premiere sequence lue, sinon parcourt du vector
  * - switch pour choisir quelle colonne incrementer en fonction de la nature de N (utilisation type enumere)
  * 
  * Ici on incremente physiquement avec +1, on ne calcule les probabilités que a lorsque la matrice est completement remplie*/

double Probabilite (double position, Nucleotide N);
/*! retourne la probabilite du nucleotide N a la position P */ 

std::string Write_Complementaire (std::string seq);
/*! va ecrire le complementaire de la sequence seq et le retourner comme resultat
 * deux possibilites : 
 * - faire un switch et donc donner une correspondance pour chaque lettre "dans le cas ou j'ai A donner un T" et faire une concatenation successive 
 *   pour construire la sequence complementaire
 * - construire une liste de paire (possible de l'ajouter a l'enum type ?  //CHARLOTTE// qui fait que j'ai le nucleotide en first et son complementaire 
 *   en seconde. Donc pour chaque nucleotide je prends son second (mais cela implique que tous les nucleotides sont sous forme de paires je crois ... donc pas ouf, a voir 
 * retourner la sequence complementaire
 * */
 
double calculScore(size_t positon);
/*! Calcul le score de vraisemblance d'une séquence à partir d'une position donnée
 * On sépare le calcul si la séquence est sur le brin codant ou sur le brin complémentaire 
 * en parcourant la matrice de haut en bas ou de bas en haut respectivement
 * Pour le calcul du brin complémentaire, la formule devient : ..................**********************
 * On appelle la fonction matrice::findElement qui retourne un élément de la matrice
 * @param : position de la séquence à analyser
 * @output : score de la séquence analysée
 * */
 
double findElement(size_t line, Nucleotide N);
/*! Trouve l'élément de tab_matrice à la ligne line pour le nucléotide N et retourne sa probabilité
 * qui est le double correspondant à tab_matrice[line][N]
 * @param : ligne = position dans la séquence analysée et N = nucléotide à analyser
 * @output : probabilité d'avoir le nucléotide N à la position line de la séquence
 * */
 
std::vector<size_t> positionSeuil(double seuil);
/*! Trouve toutes les positions où le score de la séquence à la position p est en dessous du seuil donné en paramètre
 * @param : seuil en-dessous duquel doit être le score de la séquence
 * @outup : tableau de toutes les positions où le score est en dessous de seuil
 * */
