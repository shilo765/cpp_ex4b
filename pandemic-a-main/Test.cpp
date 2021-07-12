#include "doctest.h"
#include "Board.hpp"
#include "OperationsExpert.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "GeneSplicer.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"


using namespace pandemic;
	
Board b;

TEST_CASE("Test Classes") {
	/* Operations Expert */
	
	OperationsExpert p(b, City::Chicago);
	p.build(); // Legal
	
	/* Dispatcher */
	
	Dispatcher p2(b, City::SanFrancisco);
	p2.fly_direct(City::Chicago); // Illegal
	CHECK_THROWS(p2.drive(City::SanFrancisco));
	p2.drive(City::Chicago); // Legal
	CHECK_THROWS(p2.drive(City::Chicago));
	p2.fly_direct(City::SanFrancisco); // Legal
	
	/* Scientist */
	
	Scientist p3(b, City::SanFrancisco, 3);
	p3.take_card(City::Chicago).take_card(City::Montreal);
	CHECK_THROWS(p3.discover_cure(Color::Blue)); // Illegal not enough cards
	p3.take_card(City::SanFrancisco);
	CHECK_THROWS(p3.discover_cure(Color::Blue)); // Illegal no research
	p3.drive(City::Chicago);
	p3.discover_cure(Color::Blue); // Legal
	
	/* Researcher */
	
	Researcher p4(b, City::SanFrancisco);
	p4.take_card(City::Chicago).
		take_card(City::Montreal).
		take_card(City::SanFrancisco).
		take_card(City::NewYork).
		take_card(City::Madrid);
		
	p4.discover_cure(Color::Blue);
	
	/* Medic */
	
	Medic p5(b, City::Chicago);
	b[City::Chicago] = 5;
	b[City::SanFrancisco] = 5;
	p5.treat(City::Chicago);
	CHECK_THROWS(p5.treat(City::SanFrancisco));
	CHECK(b[City::Chicago] == 0);
	
	/* Virologist */
	
	Virologist p6(b, City::Chicago);
	b[City::Moscow] = 3;
	CHECK_THROWS(p6.treat(City::Moscow));
	p6.take_card(City::Moscow);
	p6.treat(City::Moscow);
	CHECK(b[City::Moscow] == 2);
	CHECK_THROWS(p6.treat(City::Moscow));
	
	/* GeneSplicer */
	
	GeneSplicer p7(b, City::Chicago);
	p7.take_card(City::SanFrancisco).
		take_card(City::Montreal).
		take_card(City::Algiers).
		take_card(City::Bangkok);
	
	CHECK_THROWS(p7.discover_cure(Color::Yellow));
	p7.take_card(City::Cairo);
	p7.discover_cure(Color::Yellow);
	
	/* Field Doctor */
	FieldDoctor p8(b, City::Chicago);
	b[City::SanFrancisco] = 3;
	b[City::Algiers] = 3;
	CHECK_THROWS(p8.treat(City::Algiers));
	p8.treat(City::SanFrancisco);
}

TEST_CASE("General Test") {
	Player p(b, City::Algiers);
	
	CHECK_THROWS(p.drive(City::SanFrancisco));
	
	p.drive(City::Madrid);
	
	CHECK_THROWS(p.drive(City::Madrid));
	CHECK_THROWS(p.fly_direct(City::Cairo));
	
	p.take_card(City::Cairo);
	p.fly_direct(City::Cairo);
	
	CHECK_THROWS(p.fly_direct(City::Algiers));
	CHECK_THROWS(p.fly_charter(City::Moscow));
	
	p.take_card(City::Moscow);
	
	CHECK_THROWS(p.fly_charter(City::Moscow));
	
	p.take_card(City::Cairo);
	p.fly_charter(City::Moscow);
	p.take_card(City::Moscow).
		take_card(City::Tehran).
		take_card(City::Delhi).
		take_card(City::Kolkata).
		take_card(City::Chennai);
		
	CHECK_THROWS(p.discover_cure(Color::Black));
	
	p.drive(City::StPetersburg);
	
	CHECK_THROWS(p.discover_cure(Color::Black));
	CHECK_THROWS(p.build());
	
	p.take_card(City::StPetersburg);
	p.build();
	p.discover_cure(Color::Black);
}

