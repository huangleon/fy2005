#include <ansi.h>
inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
	object *ulist, *ilist;
	int i, j=0;
	int k=0, num;
	string file;
	
 	ulist = objects();
	i = sizeof(ulist);
	write(HIR"\n╒¤╘┌╟х└э╬я╞╖┴╨▒эгогого\n"NOR);
	while (i--) {
		if (!ulist[i])
			continue;
		if (environment(ulist[i]))
			continue;
		if (ulist[i]->query("short"))
			continue;
		if (sscanf(file_name(ulist[i]),"/adm/%s",file) == 1)	// daemons
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/user#%d",num) == 1)// players
			continue;
		if (!ulist[i]->query("name"))	// ╠ь╓к╡└╩╟╩▓├┤╢л╬ў
			continue;
		if (ulist[i]->query("kee"))
			k++;
		else
			j++;
		if (!arg || arg != "-s")
		{
			write("┤▌╗┘┴╦╬▐╗╖╛│╡─"+ulist[i]->query("name")+"("+ulist[i]->query("id")+")");
			write ("бг\n");
		}
		destruct(ulist[i]);
	}
	write(HIG"гогого╟х└э╜с╩°бг\n"NOR);
	write(HIW"╥╗╣▓╟х│¤┴╦"+(j+k)+"╕Ў╬▐╗╖╛│╡─╬я╞╖гм╞ф╓╨╙╨"+k+"╕Ў╩╟╔·╬ябг\n\n"NOR);
	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	recycle[-s] [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╟х└э╬▐╗╖╛│╡─╦∙╙╨╬я╞╖бг
* ▒╛╓╕┴ю╬┤╚╧╒ц┐╝┴┐гм╩╣╙├╟░╟ы╫в╥т┐╔─▄╥¤╖в┤э╬єбг	 annie.08.2003

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
);
        return 1;
}

/*

ббббббббббббббиXиY
ббббббббббббббиUиtиr
ббббббббббббббиUйжиtиr
ббббббббббббббиUйжйжиtиr
ббббббббббббббиUйжйжйжйж
бббббббббббббби^иkиkиkи_

бббббббббббббб- FengYun - бббббб
ббббббббббббannie 08.2003
ббббббdancing_faery@hotmail.com
*/

