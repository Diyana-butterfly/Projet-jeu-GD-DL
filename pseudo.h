#ifndef PSEUDO_H_INCLUDED
#define PSEUDO_H_INCLUDED

int enregistrerPseudo(const char* pseudo, const char* motDePasse);
int verifierPseudoEtMotDePasse(const char* pseudo, const char* motDePasse);
void consulterPseudos();

#endif // PSEUDO_H_INCLUDED
