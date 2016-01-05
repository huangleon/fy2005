// File : /cmds/arch/cpstat.c
// annie 07.04.2003 dancing_faery@hotmail.com
//
// Àý×ÓNPC£º/d/neon_playground/npc/slime.c

#include <dbase.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_ANNIE;

int help(object me);

int main(object me, string arg)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    string text,*tmp, id, spec;
    int loop;
	string tmp1,tmp2;
    object ob, ob1;
	int flag;
	mapping skl,map;
	string *sname,*mapped;
	string name;
	
	flag = 0;	// ÊÇ·ñ¸´ÖÆÁÙÊ±Ó³Éä£¿1:¸´ÖÆ 0:²»¸´ÖÆ

	seteuid(geteuid(me));

	if (!arg)
		return notify_fail ("\n[USAGE]\n¡¡¡¡cpstat <source> <destination>\n");
    
    sscanf (arg, "%s %s", tmp1,tmp2);

	if (!tmp1 || !tmp2)
		return notify_fail ("\n[USAGE]\n¡¡¡¡cpstat <source> <destination>\n");
	
    ob=present(tmp1, environment(me));
    ob1=present(tmp2, environment(me));
	if (!ob || !ob1)
		return notify_fail ("\n[USAGE]\n¡¡¡¡cpstat <source> <destination>\n");

	if (!ob->is_character())
		if (!ob1->is_character())
			return notify_fail ("Cpstat£º±¾Ö¸ÁîµÄ¸´ÖÆÔ´ÓëÄ¿±êÔ´±ØÐëÊÇÉúÎï¡£");
	
	if (!wizardp(ob1))
		return notify_fail("½ûÖ¹¸´ÖÆµ½·ÇÎ×Ê¦Ä¿±ê¡£\n");
		
	name = ob1->name();
	id = ob1->query("id");
	
	tell_object(me,annie_mimic(ob,ob1));
    
    ob1->set("name",name);
    ob1->set("id", id);
    
    return 1;
}
 
//  This function is used to sort the key array. 
static int sort_keys(string one, string two)
{
    return strcmp(one, two);
}

int help(object me)
{
    write( @LONG
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Ö¸ÁîËµÃ÷:

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
LONG);
 
  return 1;
}
 
