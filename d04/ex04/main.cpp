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
	IMiningLaser* DeepCoreMiner = new DeepCoreMiner();
	return 0;
}