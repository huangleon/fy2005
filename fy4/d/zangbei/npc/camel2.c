inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("�������", ({ "female camel","camel" }) );
	set("race", "����");
	set("gender", "����");
	set("age", 3);
    	set("long", "һƥ��Į�г����ĵ������գ����ں���ЪϢ��\n");

	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
     		CYN"�����ս�ͷ�������յ������˼��£������ܵ����ӡ�\n"NOR,
        }) );
        set("combat_exp", 2000000);
	set_temp("apply/attack", 300);
	set_temp("apply/armor", 100);
	set_temp("apply/dodge",300);
	set_temp("apply/damage",200);
	setup();
	carry_object(__DIR__"obj/an")->wear();
}


void	die_next(){
	object ob=this_object();
	call_out("die_next_2",6,ob);
	
}

void 	die_next_2(object ob) {
	if (objectp(ob) && ob)
		message_vision(HIR"\n����ǰϥ���£��������յ�ʬ�巢����ҵ�˻�������ۿ����ƺ��������¡���\n"NOR,ob);
	die();
}