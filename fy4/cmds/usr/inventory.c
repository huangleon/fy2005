//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, n;
	object *inv, ob, *inv_shown;
	string msg;
	
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	inv = all_inventory(ob);
	n = sizeof(inv);
	if( !n ) {
		write((ob==me)? "─┐╟░─у╔э╔╧├╗╙╨╚╬║╬╢л╬ўбг\n"
			: ob->name() + "╔э╔╧├╗╙╨╨п┤°╚╬║╬╢л╬ўбг\n");
		return 1;
	}
	inv_shown = inv[0..26];
	
	msg = "%s╔э╔╧┤°╓°╧┬┴╨╒т╨й╢л╬ў(╕║╓╪ %d%%, ╨п┤°┴┐ %d/26 )г║";
	if (sizeof(inv)>26)
		msg += HIR"\n╥╤│м╣¤┐╔╨п┤°╫ю┤є╩¤14гм╟ы╛б┐ь╝ї╔┘гм╥╘├т╥┼╩з╬я╞╖гбгб"NOR"\n%s\n";
		else 
		msg += "\n%s\n";
	
//	printf("%s╔э╔╧┤°╓°╧┬┴╨╒т╨й╢л╬ў(╕║╓╪ %d%%, ╨п┤°┴┐ %d/15 )г║\n%s\n",
	printf(msg,
		(ob==me)? "─у": ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
		n,
		implode(map_array(inv_shown, "inventory_desc", this_object()), "\n") );

	return 1;
}

string inventory_desc(object obj) {
	string str, desc;
	object me, left, right;

	return sprintf("  %s%s", obj->query("equipped")? HIC "б╠" NOR: "  ",
			obj->short());
}

int help (object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	inventory[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┐╔┴╨│Ў─у(═ц╝╥)─┐╟░╔э╔╧╦∙╨п┤°╡─╦∙╙╨╬я╞╖бг
╥╗╕Ў═ц╝╥┐╔╨п┤°╡─╒¤│г╬я╞╖╩¤╬к14гм
╧╡═│╘┌═ц╝╥╨п┤°│м╣¤14╝■╩▒╜л▓╗╧╘╩╛╫ю╡╫╧┬╡─╬я╞╖гм═м╩▒╖в│Ў╛п╕цгм
╧╡═│▓╗╘╩╨э═ц╝╥╨п┤°│м╣¤17╝■╡─╬я╞╖бг
 
╫в : ┤╦╓╕┴ю┐╔╥╘ " i " ┤·╠цбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
 
HELP
);
        return 1;
}
