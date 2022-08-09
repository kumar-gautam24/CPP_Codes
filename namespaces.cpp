/*A namespace is a scope.Namespaces are used to make logical groupings and to avoid potential naming conflicts within C++ applications.
Use of namespaces incurs no overhead to application size or performance.
To use the contents of a namespace, its contents or those parts of it that are required must be brought into current scope which
 can be achieved in a number of different ways :

    eg.To bring an entire namespace into current scope,
    use the 'using' keyword, eg :

using namespace std;

This brings the whole of the standard template library(STL) into current scope.
This is generally only used in examples;
bringing the entire contents of such a namespace into current scope in this fashion defeats the purpose of namespaces.
To bring a single namespace member into scope, the using keyword can be used to explicitly refer to that item, eg :

    using std::string;

This brings the STL 'string' type into current scope.Alternatively you can simply declare your variable with full namespace syntax within code.eg :

    std::string my_string;

This declares my_string as an object of the STL string type.
*/

/*
 * The header file
 */
#if !defined HEADER_INCLUDE_GUARD
#define HEADER_INCLUDE_GUARD

namespace Utils
{
  class SomethingUseful
  {
  public:
    SomethingUseful(void);
    ~SomethingUseful();
  };
} /* end Utils namespace */
#endif

/*
 * The source file
 */
#include "the header file"
namespace Utils
{
  SomethingUseful::SomethingUseful(void)
  {
    cout << "Doing SomethingUseful";
  }

  SomethingUseful::~SomethingUseful(void)
  {
    cout << "Doing ~SomethingUseful";
  }
} // end Utils namespace

/*
 * Alternative syntax for the source file :
 */

#include "the header file"
Utils::SomethingUseful::SomethingUseful()
{
  cout << "Doing SomethingUseful";
}
Utils::SomethingUseful::~SomethingUseful(void)
{
  cout << "Doing ~SomethingUseful";
}
