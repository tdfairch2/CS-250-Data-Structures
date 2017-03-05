#include "../Logger.hpp"
#include "../Menu.hpp"
#include "../Strings.hpp"

using namespace dal;

float Sum( float a, float b, float c )
{
    dal::Logger::Out( "a, b, c: "
        + Strings::ToString( a ) + "\t"
        + Strings::ToString( b ) + "\t"
        + Strings::ToString( c ),
        "Sum" );

    return a + b + c;
}

int main()
{
    dal::Logger::Setup();

    bool done = false;
    while ( !done )
    {
        Menu::ClearScreen();
        Menu::Header( "MAIN MENU" );

        cout << " ADD THREE NUMBERS " << endl;
        float a, b, c;
        cout << " Input three numbers: ";
        cin >> a >> b >> c;

        float sum = Sum( a, b, c );
        cout << " The sum is " << sum << endl;

        cout << endl;
        Menu::Pause();

        cout << "Add more?";
        string choice = Menu::GetValidStringChoice( {"y", "n"} );
        if ( Strings::ToLower( choice ) == "n" )
        {
            break;
        }
    }

    Logger::Out( "Done with program", "main" );

    dal::Logger::Cleanup();

    return 0;
}
