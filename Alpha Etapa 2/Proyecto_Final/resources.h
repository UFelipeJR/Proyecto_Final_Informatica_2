#ifndef RESOURCES_H
#define RESOURCES_H

#include <QString>


// Macros
#define SpriteTorsoLength 256
#define SpriteLegsLength 512
#define SpriteWeaponLength 336
#define SpriteLegsLengthMezeek 542
#define SpriteTorsoLengthMezeek 256
#define pointRotationX 40
#define pointRotationY 40
//#define pointRotationX 28.5
//#define pointRotationY 41

class resources
{
public:
    resources();
    static const QString icon;
    static const QString cursor;
    static const QString torsoRick;
    static const QString legsRick;
    static const QString weaponRick;
    static const QString deadRick;
    static const QString torsoMezeek;
    static const QString legsMezeek;
    static const QString deadMezeek;
    static const QString lyingMezeek;
    static const QString map1Path;
    static const QString maskMap1Path;
    static const QString weaponSprite;
    static const QString ostLevel1;
    static const QString ostLevel2;
    static const QString killSound;
    static const QString punchSound;
    static const QString map2Path;
    static const QString map2PathMask;
};

#endif // RESOURCES_H
