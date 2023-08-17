#include "team_fa_lib.h"


/**
* _kudos_person - Kudos a person.
* @_person: The person to give kudos to.
*/
void _kudos_person(struct _Person _person)
{
_printf("Congratulations to you %s! You are %d", _person._name, _person._month);
_printf("-months into ALX SE Programme, you deserve been celebrated");
_printf(" for the win so far.\n\n\n");
}

/**
* main -The program Entry point.
*
* Return: Always 0 (success).
*/
int main(void)
{
/* Create a person named Favour */
struct _Person favour = {"Favour Abalogu", 3};

/* Create a person named Azeez */
struct _Person azeez = {"Azeez Saka", 3};

_kudos_person(favour); /* Kudos Favour */
_kudos_person(azeez);   /* Kudos Azeez */

return (0);
}
