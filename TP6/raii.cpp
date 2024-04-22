RAII::RAII(Piece& piece, char new_position) : piece_(piece), old_position_(piece.position()) {
	piece.setPosition(new_position);
}
RAII::~RAII() {
	piece_.setPosition(old_position_);
}