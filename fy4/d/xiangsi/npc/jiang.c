// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������Ů", ({ "girl" }) );
	set("gender", "Ů��" );
	set("age", 19);
	set("per", 36);
	set("str", 24);
	set("score",-1);
	set("title","����̶��"NOR);
	set("nickname",CYN"���������"NOR);
	set("attitude", "friendly");

	set_temp("condition_type",WHT" <��ԡ��>"NOR);

	set("no_arrest",1);

	set("NO_KILL","��һ����Ů����Ҳ�µ����֣�\n");

	setup();

}
