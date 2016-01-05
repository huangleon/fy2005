// ban.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		BAN_D->print();
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("▓╗─▄╜√╥╘ *, +, ? ╜с╬▓╡─╡╪╓╖бг\n");
		else
			BAN_D->add(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		BAN_D->delete(site);
	else if (sscanf(arg, "-a + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("▓╗─▄╝╙╚ы╥╘ *, +, ? ╜с╬▓╡─╡╪╓╖бг\n");
		else
			BAN_D->add_allow(site);	
	}
	else if (sscanf(arg, "-a - %s", site) == 1)
		BAN_D->delete_allow(site);
	else 
		write("╓╕┴ю╕ё╩╜г║ban -▓╬╩¤ [+|- site]\n");

	return 1;

}

int help(object me)
{
	write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ :		ban [-a] [+|-] site [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╠ї├№┴ю╩╟╙├└┤╖└╓╣╙╨╚╦╨ю╥т╡╖┬╥бг

+	╩╟╜√╓╣▒Ё╚╦╖├╬╩
-	╩╟╔╛│¤ban╡Ї╡─╡╪╓╖
-a	╩╟╝╙╚ы╘╩╨э╜°╚ы╡─╡╪╓╖

▒╚╚ч─у┐╔╥╘ ban + 211.100гм╚╗║єban -a + 211.100.99.11
╒т╤∙╛═ban╡Ї┴╦╒√╕Ў211.100═°╢╬гм╡л╩╟╘╩╨э211.100.99.11╒т╕Ўip╜°╚ы

┐╔╥╘▓╔╙├?║═*╡╚═и┼ф╖√

╧р╣╪├№┴ю	nuke
		
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

HELP
	);
	return 1;
}
