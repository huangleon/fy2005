#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("��ɽ��", ({ "rabbit" }) );
        set("race", "Ұ��");
        set("age", 5);
        
		set("maze","taoyuan");
		set("target_name","��ɽ��");
		
        set("combat_exp",300000);
        set("long", "һֻ˶��İ�β�͵�Ұ�ã�β��һ��һ�̵ģ������һ���������ɫ��â��\n");
        set_skill("dodge", 300);
        set_temp("apply/attack",150);
        setup();
}


mixed hit_ob(object me,object victim)
{
	int extra, dream;
	string message="";
	extra = 30;
	victim->receive_damage("kee",extra,me);
	message_vision(WHT"\n$N������ɫ��â��������ƬƬ����$n��$n"+WHT"ֻ��������һ����ʹ��\n"NOR,me, victim);
	return;
}
