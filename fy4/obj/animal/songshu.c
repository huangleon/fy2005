#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("С����", ({ "squirrel", "song shu" }) );
    	set("race", "Ұ��");
    	set("age", 3);
    	set("long", "һ����������۾���С����\n");
    	set("max_kee", 120);

	set("chat_chance", 1);
	set("chat_msg", ({
		"С������������Ծ�š�\n",
		"С���������һ���ɹ��������ڣ������ְ���˦��һ�ߡ�\n",
		(: random_move :)
	}) );
    	set_skill("dodge", 100);
	set("combat_exp", 100);

    	setup();
}


