inherit NPC;
#include <ansi.h>

void create()
{
	set_name("������Ů", ({ "beauty" }) );
	set("gender", "Ů��" );
	set("title", GRN "��ɴ����"NOR);
	set("age", 18);
	set("long",
        	"һ������ɴ�ĳ�����Ů������ѩ�׵�˫�㣬���������������ͳ�����\n");
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 2);
        set("chat_msg", ({
		"������Ů�����Ÿ�����������裬��ɴƮ�����΢й����\n",
        }) );
	set_skill("unarmed",20);
	set_skill("dodge",100);
	setup();
	carry_object(__DIR__"obj/qinsha")->wear();
}