// ff.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string dest, func, file;

	if(!arg || sscanf(arg, "%s %s", dest, func)!=2 )
		return notify_fail("╓╕┴ю╕ё╩╜г║ff <╬я╝■> <║п╩¤├√│╞>\n");

	if( dest=="me" ) ob = me;
	else if( dest=="here" ) ob = environment(me);
	else ob = present(dest, me);

	if( !ob ) ob = present(dest, environment(me));
	if( !ob ) ob = find_object(resolve_path(me->query("cwd"), dest));
	if( !ob ) return notify_fail("╒т└я├╗╙╨б╕" + dest + "б╣бг\n");

	file = function_exists(func, ob);
	if(!file)
		printf("╬я╝■ %O ▓в├╗╙╨╢и╥х %s ╒т╕Ў║п╩¤бг\n", ob, func);
	else
		printf("╬я╝■ %O ╡─ %s ║п╩¤╢и╥х╘┌ %s.cбг\n", ob,	func, file );
	return 1;
}

int help()
{
	write(@TEXT
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	ff <╬я╝■> <║п╩¤├√│╞>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
╓╕┴ю╕ё╩╜г║ff <╬я╝■> <║п╩¤├√│╞>

╒т╕Ў╓╕┴ю┐╔╥╘╒╥│Ў╓╕╢и╬я╝■╓╨╡──│╕Ў║п╩¤╢и╥х╘┌──╥╗╕Ў╡╡░╕└ябг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
TEXT
	);
	return 1;
}
