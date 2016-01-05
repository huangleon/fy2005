// where.c
// 06-14-95

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where, *ob_list;
	int i;
        if(!me->query("env/yesiknow")) return notify_fail("╒т╕Ў╓╕┴ю╥╤╛н▒╗╖╧│¤┴╦гб\n");
	if (!str)
		return notify_fail("╓╕┴ю╕ё╩╜г║where <╚╦╬я╗Є╡╡├√>\n"); 
	ob = find_player(str);
	if( !ob ) ob = find_living(str);
/*	if( !ob || !me->visible(ob)) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return 1;
	}*/
	if (!ob) return notify_fail("╧╓╘┌├╗╒т╕Ў╚╦бг\n");
	where = environment(ob);
	if (!where) return notify_fail("╒т╕Ў╚╦▓╗╓к╡└╘┌─╟└я╥обгбгбг\n");
	printf("%s(%s)╧╓╘┌╘┌%s(%s)бг\n",
		(string)ob->name(),
		(string)ob->query("id"),
		(string)where->query("short"),
		(string)file_name(where));
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	where <═ц╝╥╡─ ID>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю╩╟╙├└┤╡├╓к═ц╝╥─┐╟░╦∙╘┌╡─╬╗╓├.

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
HELP
	);
	return 1;
}

