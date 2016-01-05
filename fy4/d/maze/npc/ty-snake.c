#include <ansi.h>
inherit MAZE_NPC;
int bite();

void create()
{
        set_name(HIW"�׻���"NOR, ({ "white snake","snake" }) );
        set("race", "����");
        set("target_name","�׻���");
        set("age", 1);
        set("long", "
����������ޭ�ߣ����ں��񣬵���ȡ���һ��ֵĶ��κ�İ׻��ߣ�ͨ�����ַ�ɫ�� 
��ϲ���ˣ������쳣�� \n");

		set("maze","taoyuan");
	
        set("group","snake");
        
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			WHT"�׻��߱���ɫ����һ��һ����Ѫɫ�������������졣\n"NOR,
    	}) );  
       
		set("combat_exp",400000);
        set_skill("dodge", 400);
        set_temp("apply/attack",200);
        setup();
}


int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(WHT"�׻�����һ֧����֮����ͻȻֱͦͦҧ��$N�Ĳ��ӡ�\n"NOR,target);
		tell_object(target,HIB"�㰥��һ����������������������Ķ���ӡ��\n"NOR);
		target->receive_damage("kee",target->query("max_kee")/20,ob);
		COMBAT_D->report_status(target);
		ob->start_busy(1);
	}
	return 1;
}
