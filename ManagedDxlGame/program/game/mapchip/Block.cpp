#include "Block.h"


Block::Block(const tnl::Vector3& pos, MAPCHIP chipType) : MapChipBase( pos, chipType) {

	chipType_ = chipType;
	collision_ = true;
	has_damage_ = false;
}

void Block::onCollision_() {

}
