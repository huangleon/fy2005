inherit NPC;
#include <ansi.h>

void create()
{
	set_name("Ұ��", ({ "bear"}) );
	set("race", "Ұ��");
	set("gender", "����");
	set_temp("condition_type",YEL"<������>"NOR);
	set("age", 6);
	set("long", "
����һֻƤ������Ұ�ܣ������׶������ޱȡ�����������������
������˯�����\n");
	
	set("chat_chance",1);
    	set("chat_msg",({
		CYN"\nҰ�ܷ��˸�������������˯�����\n\n"NOR,
    	}) );  
	
	set("combat_exp", 200000);
		
	set_temp("apply/attack", 50);
	set_temp("apply/dodge",50);
	set_temp("apply/move",40);
	set_temp("apply/armor", 100);
	setup();
	carry_object(__DIR__"obj/palm_w");
}
