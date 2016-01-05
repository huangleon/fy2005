// ilist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("╓╕┴ю╕ё╩╜г║ilist <╬я╝■╗Є╡╡├√>\n");

	ob = present(arg, me);
	if( !ob ) ob = present(arg, environment(me));
	if( !ob ) ob = find_object(resolve_path(me->query("cwd"), arg));
	if( !ob ) return notify_fail("├╗╙╨╒т╤∙╬я╝■╗Є╒т╤∙╬я╝■├╗╙╨▒╗╘╪╚ыбг\n");

	printf("%O╓▒╜╙╗Є╝ф╜╙╝╠│╨╥╘╧┬╡╡░╕г║\n    %s\n", ob,
		implode(deep_inherit_list(ob), "\n    "));
	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	ilist <╬я╝■╗Є╡╡├√>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
 
┴╨│Ў╥╗╕Ў╬я╝■╦∙╝╠│╨╡─╦∙╙╨╬я╝■бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
);
        return 1;
}
 
