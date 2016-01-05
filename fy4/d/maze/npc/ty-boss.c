#include <ansi.h>
inherit MAZE_NPC;
int bite();

void create()
{
        set_name("�һ�����", ({ "mist spirit","spirit" }) );
        set("race", "Ұ��");
        set("age", 231);
        set("long", MAG"
�����ɻ��ζ���������ɵ��������·�һ�ŷ�ɫ�������������壬�����Ǳ��� 
�����ˣ�������ͷ���������¡��� \n"NOR);
        set("group","ghost");
		set("combat_exp",500000);
    	set("target_name","�һ�����");
	
        set("maze","taoyuan");
        
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
			(: bite()  :),     
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		MAG"�һ���������һ�������������Ϣ����������Ʈ���š���\n"NOR,
    	}) );  

        set("NO_CORPSE",MAG"�һ�����һ���ҽУ�����һ��������ʧ�ˣ�\n\t��������һ�ξ�Ө��¶�顣\n"NOR);
        
        set_skill("dodge", 600);
        set_temp("apply/attack",250);
        
        setup();
        carry_object(__DIR__"obj/ty-mist");
}

int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(MAG"�һ������·�һ��������$N������������$Nֻ��һ��ͷ��Ŀѣ��\n"NOR,target);
		tell_object(target,HIB"����û����˯��\n"NOR);
		target->receive_wound("kee",target->query("max_kee")/20,ob);
		COMBAT_D->report_status(target);
		ob->start_busy(1);
	}
	return 1;
}

