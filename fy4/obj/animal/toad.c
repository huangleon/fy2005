#include <ansi.h>
inherit NPC;


void create()
{
        set_name("���", ({ "toad" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("combat_exp",1000);
        set("long", "һֻ���ϳ�������ѿ�֮������󡡣\n");
        set("verbs", ({ "bite" }) );
	set("limbs", ({
		"ͷ��",	"����",	"�ز�",	"��",	"����",	
		"ǰ��",	"����"
	}) );     
	set("death_msg",CYN"\n���׶��ӳ���һ����¡������� \n"NOR);
	set("self_go_msg",1);
	set("arrive_msg","ϤϤ���������˹�����");
	set("leave_msg","һ���̵��ܵ��ˡ�");
        set_skill("dodge", 80);
        setup();
}

			