// teacher.c
//Modified by justdoit 04/11/2001

inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("����", ({ "xu ning" }) );
    	set("nickname", HIY "������������ȥ"NOR);
    	set("gender", "����" );
    	set("age", 32);
    	create_family("��¹�", 4, "");
    	set("skill_public",1);
}

int recognize_apprentice(object ob)
{
	return 1;
}
