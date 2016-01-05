// beggar.c

#include <ansi.h>

inherit NPC;
string desc();

void create()
{
        int i,amun;
        string *order = ({"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��"});
		string *orderr = ({"����", "����","СС", "ëë", "����"});
        set_name( order[random(13)] + orderr[random(5)], ({ "kid", "small kid" }) );
		set("title", "�ϻ�Сͯ");
		set("gender", "����" );
		set("age", random(5)+4);
		set("int", 26);
		set("long",	(: desc :));
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );

		set("attitude", "peaceful");
		set("combat_exp", 2000);
        set_skill("unarmed", 1+random(10));
        set_skill("taiji", 10+random(10));
        map_skill("unarmed", "taiji");
		setup();
		carry_object("/obj/armor/cloth")->wear();
}

string desc(){
	
	object me = this_player();
	object owner;
	owner = query("lama_owner");
	
	if (!owner || owner!= me)	
		return "һ������������С�������ڵ��ϱı���������ˣ��\n";
		
	return "һ���������µ�С������Ȼ�����¾ɣ�ȴ��һ��߹�����ʡ�\n";
}




int accept_object(object me, object obj)
{
    object room, owner;
    if (me != query("starter"))	return 0;
    	
    if (REWARD_D->riddle_check(me,"��ͯת��") == 4)
	if (obj->name() == "��ľ����") {
		owner = query("lama_owner");
		if (!owner)
		{		
			message_vision(CYN"Сͯ˫�ƺ�ʮ�����Զ�֮����ǧ�ٲ�ȣ����ܵ�֪��\n"NOR, me);
			REWARD_D->riddle_set(me,"��ͯת��", 999);	// failed
			me->set("timer/lingtong", time());		
			room = find_object("/d/resort/lake2");
        	room ->ending(me, 0);
        	return 1;
		}		
		message_vision(CYN"Сͯ˫�ƺ�ʮ����
		
������ƣ��ľ�������

���н������񿪵���֮�š�

�������飬�����ǧ���硣

�󱯴�Ը����ʥ��ȡ�
	
˵�գ���$N΢΢һЦ��\n"NOR, me);					;
		
		REWARD_D->riddle_set(me,"��ͯת��", 6);
        room = find_object("/d/resort/lake2");
        room ->ending(me, 1);
        return 1;
	}
	return 0;
}

