inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("��������", ({ "male camel","camel" }) );
	set("race", "����");
	set("gender", "����");
	set("age", 3);
    	set("long", "һƥ��Į�г����ĵ������գ����ں���ЪϢ��\n");
        
	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
     		CYN"���յ���ͷȥ���˼�����ݣ�ת�״������㼸�ۣ�������Ȥ��\n"NOR,
        }) );
        set("combat_exp", 3000000);
	set_temp("apply/attack", 300);
	set_temp("apply/armor", 100);
	set_temp("apply/dodge",300);
	set_temp("apply/damage",200);
	setup();
	carry_object(__DIR__"obj/an")->wear();
}


void die(){
	object spouse;
	
	if (spouse=present("female camel",environment(this_object())))
	if (!userp(spouse)) {
		spouse->die_next();
	}
	::die();
}