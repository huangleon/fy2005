// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) return notify_fail("─у╥к╠ц╫╘╝║╚б╩▓ўс┤┬║┼г┐\n");
	if( strlen(arg) > 40 )
		return notify_fail("─у╡─┤┬║┼╠л│д┴╦гм╧ы╥╗╕Ў╢╠╥╗╡у╡─бв╧ь┴┴╥╗╡у╡─бг\n");

	if (arg=="none") {
		me->delete("nickname");
		return notify_fail("─у╚б╧√┴╦╫╘╝║╡─┤┬║┼бг\n");
	}

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
	write("Ok.\n");
	return 1;
}
int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	nick <═т║┼, ┤┬║┼>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╚├─у╬к╫╘╝║╚б╥╗╕Ў╧ь┴┴╡─├√║┼╗Є═╖╧╬гм─у╚ч╣√╧г═√╘┌┤┬║┼╓╨
╩╣╙├ ANSI ╡─┐╪╓╞╫╓╘к╕─▒ф╤╒╔лгм┐╔╥╘╙├╥╘╧┬╡─┐╪╓╞╫╓┤ог║

$BLK$ - ║┌╔л		$NOR$ - ╗╓╕┤╒¤│г╤╒╔л
$RED$ - ║ь╔л		$HIR$ - ┴┴║ь╔л
$GRN$ - ┬╠╔л		$HIG$ - ┴┴┬╠╔л
$YEL$ - ═┴╗╞╔л		$HIY$ - ╗╞╔л
$BLU$ - ╔ю└╢╔л		$HIB$ - └╢╔л
$MAG$ - ╟│╫╧╔л		$HIM$ - ╖█║ь╔л
$CYN$ - └╢┬╠╔л		$HIC$ - ╠ь╟р╔л
$WHT$ - ╟│╗╥╔л		$HIW$ - ░╫╔л
 
╞ф╓╨╧╡═│╫╘╢п╗с╘┌╫╓┤о╬▓╢╦╝╙╥╗╕Ў $NOR$бг

╚ч╣√─у╧ы╚е│¤╫╘╝║╡─┤┬║┼гм┐╔╥╘╩╣╙├б░nick noneб▒бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 

HELP
        );
        return 1;
}
