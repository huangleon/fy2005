
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("���Ҹ�Ů", ({ "funu" }) );
	set("gender", "Ů��" );
	set("title", HIR "���ܴݲ�"NOR);
	set("age", 18);
	set("long",
		"һ�����ܴݲе����Ҹ�Ů\n");
	set("attitude", "friendly");
	set("per",30);
	set("combat_exp", 10000);
	setup();
	carry_object(__DIR__"obj/nocloth")->wear();
}
