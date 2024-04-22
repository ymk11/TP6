#pragma once
#include "echiquier.hpp"




namespace chess {

	class Temporarypiecewrapper {
	public:
		Temporarypiecewrapper(Case& tcase, const ui::Echiquier& echiquier);
		~Temporarypiecewrapper();
		//const std::unique_ptr<Piece>& get();
		void moveTo(const Position& position);

	private:
		Case case_;
		Case originalcase_;

	};
}
