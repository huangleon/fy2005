
inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("�ݻ���", ({ "horse" }) );
	set("race", "����");
	set("gender", "����");
	set("age", 3);
    	set("long", "һƥ�ݹ���᾵ĵĻ���ë��ʧȥ�����յĹ���\n");
        
	set("int",40);
	set("cor",80);
	set("str",50);
	set("attitude", "peaceful");
	set("chat_chance", 1);
        set("chat_msg", ({
     			"�����ԡ������ԣ������쳤Х�˼���\n",
        }) );
        set("combat_exp", 2000000);
	set_temp("apply/attack", 300);
	set_temp("apply/armor", 100);
	set_temp("apply/dodge",300);
	set_temp("apply/damage",200);
	setup();
}
