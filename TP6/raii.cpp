#include "RAII.hpp"

RAII::RAII() {
	moveTo(const chess::Position & start, const chess::Position & destination);
}
RAII::~RAII() {
	moveTo(const chess::Position & destination, const chess::Position & start);

}