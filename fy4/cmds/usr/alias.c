// alias.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i;
	mapping alias;
	string verb, replace, *vrbs;

	if( !arg ) {
		alias = me->query_all_alias();
		if( !sizeof(alias) ) {
			write("─у─┐╟░▓в├╗╙╨╔ш╢и╚╬║╬ aliasбг\n");
			return 1;
		} else  {
			write("─у─┐╟░╔ш╢и╡─ alias ╙╨г║\n");
			vrbs = keys(alias);
			for(i=0; i<sizeof(vrbs); i++)
				printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
			return 1;
		}
	}

	if( sscanf(arg, "%s %s", verb, replace)!=2 )
		me->set_alias(arg, 0);
	else if( verb=="alias" )
		return notify_fail("─у▓╗─▄╜л \"alias\" ╓╕┴ю╔ш╢и╞ф╦√╙├═╛бг\n");
	else if( verb=="" )
		return notify_fail("─у╥к╔ш╩▓ўс aliasг┐\n");
	else
		return me->set_alias(verb, replace);
		
//	write("Ok.\n");
	return 1;
}

int help (object me)
{
	write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	alias <╙√╔ш╢и╓о╓╕┴ю> <╧╡═│╠с╣й╓о╓╕┴ю>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
 
╙╨╩▒╧╡═│╦∙╠с╣й╓о╓╕┴ю╨ш╥к╩ф╚ы║▄│д╡─╫╓┤о, ╘┌╩╣╙├╩▒(╙╚╞ф╩╟╛н│г╙├╡╜╡─)
╗Є╨э╗с╕╨╛ї▓╗╖╜▒у, ┤╦╩▒─у(═ц╝╥)╝┤┐╔╙├┤╦╥╗╓╕┴ю╔ш╢и▓в╠ц┤·╘н╙╨╓о╓╕┴юбг
 
бї└¤:
	'alias sc score' ╗с╥╘ sc ╚б┤· score ╓╕┴юбг
	'alias' сс▓╗╝╙▓╬╩¤╘Є┴╨│Ў─у╦∙╙╨╡─╠ц┤·╓╕┴юбг
	'alias sc' ╗с╧√│¤ sc ╒т╕Ў╠ц┤·╓╕┴юбг (╚ч╣√─у╙╨╔ш╡─╗░)
 
╞ф╓╨┐╔╥╘╙├ $1, $2, $3 .... └┤╚б┤·╡┌╥╗бв╡┌╢■бв╡┌╚¤╕Ў▓╬╩¤гм
╗Є╩╟ $* ╚б┤·╦∙╙╨╡─▓╬╩¤гм╚чг║
	'alias pb put $1 in $2'

╘Є├┐╡▒─у(═ц╝╥)┤Єг║
	pb bandage bag

╛═╗с╚б┤·│╔г║
	put bandage in bag

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
	
HELP
);
        return 1;
}
