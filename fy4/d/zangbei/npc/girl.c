inherit NPC;
#include <ansi.h>

void create()
{
	set_name("ϴ����Ů", ({ "laundry girl","girl" }) );
	set("gender", "Ů��" );
	set("cor",20);
	set("age", 18);
	set("long","
�����ĺ�ɫ���������ɫ�������ֱۻ�Բ����ɫ��ͭ������ͭ�ζ�����
һ��������Χȹֱ�����ű���\n");
	set("combat_exp", 240000);
	set("attitude", "friendly");
	set("chat_chance",1);
    	set("chat_msg",({
		"\n��Ů���ź��������س����ƺ�����ʲô���¡�\n\n"NOR,
    	}) );  
	    		
	set_skill("hammer",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("unarmed",200);
		
	setup();
	carry_object(__DIR__"obj/tcloth2")->wear();
	carry_object(__DIR__"obj/l_hammer")->wield();
}

	