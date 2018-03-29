#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include "KoalaSteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "AsteroKreog.hpp"
#include "MiningBarge.hpp"
#include "StripMiner.hpp"

int main() {
	IAsteroid* koala = new KoalaSteroid();
	IAsteroid* astero = new AsteroKreog();
	IMiningLaser* strip = new StripMiner();
	IMiningLaser* deep = new DeepCoreMiner();
	(void)koala;
	(void)strip;
	(void)deep;
	(void)astero;
	std::cout << koala->getName() << " " << astero->getName() << std::endl;
	return 0;
}
