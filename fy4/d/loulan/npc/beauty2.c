inherit NPC;
#include <ansi.h>

void create()
{
	set_name("��װ���", ({ "slave girl","girl" }) );
	set("gender", "Ů��" );
	set("title", MAG "��������"NOR);
	set("age", 18);
	set("long",
		"һ������ɫ��װ����Ů��б���ڻ�Ƥ���ԣ�Ū�Ź��ҡ���\n");
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 1);
        set("chat_msg", ({
		"��װ����Ღ���٣�һ�������������ӡ���\n",
	}) );
	set_skill("unarmed",20);
	set_skill("dodge",100);
	setup();
	carry_object(__DIR__"obj/gongzhuang")->wear();
}
