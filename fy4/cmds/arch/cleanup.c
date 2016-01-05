// cleanup.c

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where, *ob_list;
	int old_size, i;

	if (!str) return notify_fail("╓╕┴ю╕ё╩╜г║cleanup <╡╡├√>\n"); 

	str = resolve_path(me->query("cwd"), str);
	ob_list = children(str);
	old_size = sizeof(ob_list);
	ob_list->clean_up();
	for(i=0; i<sizeof(ob_list); i++)
		if( ob_list[i] && clonep(ob_list[i]) && !environment(ob_list[i]) )
			destruct(ob_list[i]);
	ob_list -= ({ 0 });
	printf("╟х│¤ %d ╕Ў╬я╝■бг\n", old_size - sizeof(ob_list));
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	cleanup <╡╡├√>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╢╘╦∙╙╨╓╕╢и╡╡├√╡─╬я╝■║Ї╜╨ clean_upгм▓в╟╥╟х│¤╦∙╙╨▒╗╕┤╓╞│Ў└┤╡─гм
╡л╩╟╙╓├╗╙╨▒╗╖┼╘┌┴э╥╗╕Ў╬я╝■╓╨╡─╔в╩з╬я╝■бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
	);
	return 1;
}

