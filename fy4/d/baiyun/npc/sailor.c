#include <ansi.h>
inherit NPC;

void create()
{
	set_name("ˮ��", ({ "sailor","shuishou" }) );
	set("gender", "����" );
	set("age", 28);
	set("long", "һ������Ʈ���ں��ϵ��ˣ���ͭɫ��Ƥ������ʵ�ļ��⡣\n");
    set("combat_exp", 10000+random(10000));
	set("attitude", "heroism");
    set_skill("unarmed", 50);
    set_skill("parry", 60);
    set_skill("dodge", 70);
    set("chat_chance", 10);
    set("chat_msg", ({(:random_move :)}) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
