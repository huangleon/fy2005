// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
	if( !file ) return notify_fail("÷∏¡Ó∏Ò Ω£∫edit <µµ√˚>\n");

	if( in_edit(me) ) return notify_fail("ƒ„“—æ≠‘⁄ π”√±‡º≠∆˜¡À°£\n");

	seteuid(geteuid(me));
	ed(resolve_path(me->query("cwd"), file));
	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36mŒ◊ ¶÷∏¡Ó∏Ò Ω : 	edit <µµ√˚>, edit here[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

÷∏¡Ó∏Ò Ω : edit <µµ√˚>, edit here

¿˚”√¥À“ª÷∏¡Óø…÷±Ω”‘⁄œﬂ…œ±‡º≠µµ∞∏°£
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   
HELP
    );
    return 1;
}
