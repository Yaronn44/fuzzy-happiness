//! \file Etat_Chose.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de EtatChose.cpp
 

#ifndef ETATCHOSE_H
#define ETATCHOSE_H

#include <QApplication>
#include <iostream>
#include <memory>

class Chose;


//------------------------------------------------------------------------------ Général
//! \class Etat_Chose
//! \brief Classe "abstraite" permettant l'implémentation du pattern States

class Etat_Chose{
private:

public:

    //! \brief Constructeur
    Etat_Chose();

    //! \brief Destructeur
    virtual ~Etat_Chose();

    //! \brief Méthode de changement d'étât 
    virtual void fuire();

    //! \brief Méthode de changement d'étât 
    virtual void en_securite();

    //! \brief Méthode de changement d'étât 
    virtual void explore();

    //! \brief Méthode de changement d'étât 
    virtual void pourchasser();

    virtual void seTapperLAffiche();
signals:

public slots:
};


//------------------------------------------------------------------------------ Fuite
//! \class Etat_Fuite
//! \brief Classe implémentant la classe Etat_Chose

class Etat_Fuite : public Etat_Chose{

private:
    std::unique_ptr<Chose> chose_;

public:

    //! \brief Constructeur
    //! \param c : Chose pour laquelle l'état est appliqué 
    Etat_Fuite(Chose c);

    //! \brief Destructeur
    ~Etat_Fuite();

    void fuire();
    void en_securite();
    void explore();
    void pourchasser();
    void seTapperLAffiche();

signals:

public slots:
};


//------------------------------------------------------------------------------ Repos
//! \class Etat_Repos
//! \brief Classe implémentant la classe Etat_Chose

class Etat_Repos : public Etat_Chose{

private:
    std::unique_ptr<Chose> chose_;

public:

    
    //! \brief Constructeur
    //! \param c : Chose pour laquelle l'état est appliqué 
    Etat_Repos(Chose c);

    //! \brief Destructeur
    ~Etat_Repos();

    void fuire();
    void en_securite();
    void explore();
    void pourchasser();
    void seTapperLAffiche();

signals:

public slots:
};


//------------------------------------------------------------------------------ Explore
//! \class Etat_Explore
//! \brief Classe implémentant la classe Etat_Chose

class Etat_Explore : public Etat_Chose{

private:
    std::unique_ptr<Chose> chose_;

public:

    
    //! \brief Constructeur
    //! \param c : Chose pour laquelle l'état est appliqué 
    Etat_Explore(Chose c);

    //! \brief Destructeur
    ~Etat_Explore();

    void fuire();
    void en_securite();
    void explore();
    void pourchasser();
    void seTapperLAffiche();

signals:

public slots:
};


//------------------------------------------------------------------------------ Pourchase
//! \class Etat_Pourchasse
//! \brief Classe implémentant la classe Etat_Chose

class Etat_Pourchasse : public Etat_Chose{

private:
    std::unique_ptr<Chose> chose_;

public:

    
    //! \brief Constructeur
    //! \param c : Chose pour laquelle l'état est appliqué 
    Etat_Pourchasse(Chose c);

    //! \brief Destructeur
    ~Etat_Pourchasse();

    void fuire();
    void en_securite();
    void explore();
    void pourchasser();
    void seTapperLAffiche();

signals:

public slots:
};


#endif // ETATCHOSE_H
