// cat.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("╓╕┴ю╕ё╩╜ : more <╡╡├√>|<╬я╝■├√> \n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("├╗╙╨╒т╕Ў╡╡░╕бг\n");
		file = base_name(ob) + ".c";
	}
	me->start_more("", read_file(file), 0);
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	more <╡╡░╕>|<╬я╝■├√>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╖╓╥│╧╘╩╛╡╡░╕─┌╚▌бг
 
more ─г╩╜╧┬╡─╓╕┴ю:
q      : └ы┐к more.
b      : ╧╘╩╛╟░╥╗╥│╡──┌╚▌.
[ENTER]: ╧╘╩╛╧┬╥╗╥│╡──┌╚▌.

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}
