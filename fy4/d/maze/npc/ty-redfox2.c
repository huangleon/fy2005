#include <ansi.h>
inherit MAZE_NPC;
int bite();

void create()
{
        set_name(HIY"��β����"NOR, ({ "fire mink","mink" }) );
        set("race", "Ұ��");
        set("age", 21);
        set("long", HIY"
һֻ���˾���β�͵Ļ�������ɫ�ľ����·�ȼ�������Ż��棬�Ľ�צ�ӷ���
�쳣�����ش�Ծ֮����ͬһ�����߰�Ѹ���쳣��\n"NOR);
        
        set("target_name","��β����");
        set("group","fox");   	
    	set("maze","taoyuan");
    	
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			HIY"��������һ��ڵ����ϣ��·�һ�Ż������ȥ��\n"NOR,
    	}) );  
        
		set("combat_exp",450000);
        
        set_skill("dodge", 500);
        set_temp("apply/attack",300);
        
        setup();
        carry_object(__DIR__"obj/ty-skin");
}


int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(name()+RED"��ͬһ�Ż�һ�������������ݺݵس�$N������ҧ�˹�����\n"NOR,target);
		tell_object(target,HIR"������һ����ۣ�����һ��������һ���������ӡ��\n"NOR);
		target->receive_damage("kee",target->query("max_kee")/20,ob);
		COMBAT_D->report_status(target);
		this_object()->start_busy(1);
	}
	return 1;
}
