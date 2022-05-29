#include "settings.h"
#include "searchbox.h"

#include <FlatSelector.h> // ссылка на чужие объявления
#include "ArgumentsParser.h"

#include <regex> // для замены <br> на \n в описании квартир

class FlatWrapper: public Object {
public:
  FlatWrapper(FlatAndTravelTime _flat): flat(_flat) {};
  std::unique_ptr<Wt::WTemplate> info();
private:
  FlatAndTravelTime flat;
};

class OverflowProject : public Wt::WApplication
{
public:
  OverflowProject(const Wt::WEnvironment& env);
  SearchBox *searchbox;
};

int run_server(int argc, char **argv);