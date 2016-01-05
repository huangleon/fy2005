// emote.c (Mon  09-04-95)

#include <ansi.h>
inherit F_CLEAN_UP;
#define NEW_PERIOD 32400
int  check_legal_name(string name); 
int main(object me, string str)
{
    if (!str) {
        write(CYN"─у┐┤╞Ё└┤▒э╟щ╖с╕╗бг\n"NOR);
        return 1;
    }
        if(me->query("chblk_on"))
                return notify_fail("─у╡─╞╡╡└▒╗╣╪┴╦гб\n");
        if((int)me->query("mud_age") < NEW_PERIOD)
                return notify_fail("─у╓╗┐╔╥╘╩╣╙├гиsayгйбг\n");
/*      str = replace_string(str, "$BLK$", BLK);
        str = replace_string(str, "$RED$", RED);
        str = replace_string(str, "$GRN$", GRN);
        str = replace_string(str, "$YEL$", YEL);
        str = replace_string(str, "$BLU$", BLU);
        str = replace_string(str, "$MAG$", MAG);
        str = replace_string(str, "$CYN$", CYN);
        str = replace_string(str, "$WHT$", WHT);
        str = replace_string(str, "$HIR$", HIR);
        str = replace_string(str, "$HIG$", HIG);
        str = replace_string(str, "$HIY$", HIY);
        str = replace_string(str, "$HIB$", HIB);
        str = replace_string(str, "$HIM$", HIM);
        str = replace_string(str, "$HIC$", HIC);
        str = replace_string(str, "$HIW$", HIW);
        str = replace_string(str, "$NOR$", NOR);*/
	if( strsrch(str, "$ME$") == -1 )
		str = "$ME$"+ str ;
//		write("─у╩ф╚ы╡─╫╓┤о╓╨▒╪╨ш║м╙╨$ME$\n");
//	else{
	str = replace_string(str, "$ME$", me->name());
	if(check_legal_name(str))
	CHANNEL_D->do_channel(me, "fy", str,1);
//	}

    return 1;
}
 
int help(object me)
{
	write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	cfy <╢п╫ў┤╩>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╚├─у▒э┤я╥╗╕Ў╧╡═│├╗╙╨╘д╔ш╡─╢п╫ў┤╩, ╧╡═│╗с╜л─у╦∙╩ф╚ы
╡─╬─╫╓╓╨╡─$ME$╠ц╗╗│╔─у╡─╨╒├√сс╧╘╩╛╘┌╖ч╘╞╞╡╡└└ябг╚ч╣√├╗╙╨$ME$гм
╘Є╧╡═│╗с╫╘╢п╘┌─у╩ф╚ы╡─╨┼╧в╟░╠э╝╙─у╡─├√╫╓бг

▒╚╚ч─у╡─├√╫╓╩╟░в╠·

ги1гй└¤: cfy $ME$╫°┴╦╧┬└┤бг
┤є╝╥╛═╗с┐┤╡╜		[31mб╛╖ч╘╞б┐░в╠·╫°┴╦╧┬└┤бг[0m

ги2гй└¤: cfy ╠ь╔╧╡Ї╧┬╕Ў$ME$└┤бг
┤є╝╥╛═╗с┐┤╡╜		[31mб╛╖ч╘╞б┐╠ь╔╧╡Ї╧┬╕Ў░в╠·└┤бг[0m

╧р╣╪╓╕┴ю: semote, cemote

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
	);
        return 1;
}

int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        while(i--) {
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("╢╘▓╗╞Ёгм╟ы─·╙├╓╨╬─бг\n");
                        return 0;
                }
        }
	return 1;
}
