#include <ansi.h>
inherit NPC;

void create()
{
    set_name("Ů����", ({ "female tufei" }) );
    set("nickname", HIM "���ֽ��� ������ü"NOR);
    set("title",  "����կ ѹկ����"NOR);
	set("gender", "Ů��");
    set("per", 5);
	set("age", 19);
	set("long",     
		"�񻢸���ȻҲ��Ů�ˣ����ǲ�����װ����ǹ�����Ǵ󶼸����ഺ���٣�\n��Ľ������������ڽ����չ�ԡ��һ�߳��������۶���\n");
	set("combat_exp", 11000);
	set("score", 100);
	set("attitude", "friendly");
	set_skill("unarmed", 75);
	set_skill("tenderzhi",60);
	set_skill("parry", 15);
	set_skill("dodge", 50);
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/doudu")->wear();
}
