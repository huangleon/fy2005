#include <ansi.h>

inherit NPC;

void imbue_event(object me);

void create()
{
        set_name("С��", ({ "xiao fang","fang" }) );
        set("gender", "����" );
        set("long",
                "һ���������⡢Ư������Ĺ¶����ӡ�\n"
                );
        set("title", HIW"����"NOR);
        set("attitude", "peaceful");

	set("age", 28);
        set("per", 30);

        set("combat_exp", 5000000);

	set("no_busy",10);
        set("class","fighter");

        set("chat_chance", 1);
        set("chat_msg", ({
                "С��Զ�����Ŵ����ʥĸѩ�壬����ɤ�ӵ�����ӥ������һ�����ҵ�\n�㣬�ҵ�һ���úû��ŵ��㡭��\n",
                }) );

        set_skill("unarmed", 200);
        set_skill("parry", 140);
        set_skill("dodge", 200);
        set_skill("sword", 200);
    	set_skill("doomforce", 150);
    	set_skill("lingxi-zhi", 160);
    	set_skill("doomsteps", 150);
    	set_skill("doomsword",130);

    	map_skill("unarmed", "lingxi-zhi");
    	map_skill("sword", "doomsword");
    	map_skill("dodge", "doomsteps");
        map_skill("parry","doomsword");

	set("chat_chance_combat", 30);
	set("chat_msg_combat",({
                      (:perform_action,"sword.hunranyijian":),
	}));

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/icesword")->wield();
}


int accept_object(object me, object obj)
{
        if(obj->query("name") == BLU"ħ�۽�"NOR && obj->query("owner_id") == me->query("id"))
        {
        	message_vision("$N��������ħ�۽������������˸���԰׵����Ϸ�����Ѫɫ��\n", this_object());
        	message_vision("$N��$n�м��ص��˵�ͷ������绹���ţ�����֪���������š�\n",this_object(),me);
		if (!REWARD_D->imbue_check(me, "�۳�ķ�ӥ"))
		{
			imbue_event(me);
		}
		if (!REWARD_D->check_m_success(me, "�۳�ķ�ӥ"))
		{
			REWARD_D->riddle_done(me, "�۳�ķ�ӥ",100,1);
		}
		return 1;
	}
	else
	{
		write("С�����ֵ��������Ӳ��������������²��ܽ������Ķ�������\n");
		return 0;
	}
}


void imbue_event(object me){
	object weapon, *inv, obj;
	string prop;
	int i;
	mapping data;
	
	if(!interactive(me) || environment(me) != environment(this_object())) {
		return 0;
	}
	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}
	}
	if(!objectp(weapon)){
		if(!objectp(obj)){
			message_vision(HIC"��ϲ����ˮһ��һ�ε����ڵ��ϡ�����\n"NOR, me);
		} else {
			message_vision(HIC"��ϲ����ˮһ��һ�ε���$N��" + obj->name() + HIC"���ֻ��䵽���ϡ�\n"NOR, me);
		}
	}else {
		message_vision(HIC"��ϲ����ˮһ��һ�ε�����$N��" + weapon->name() + HIC"�ϣ���һ��������˾�Ө�����ı�������� \n"NOR,
				me);
		message_vision(HIC"�������" + weapon->name() + HIC"��ɢ������ʵĹ�â������ת˲������ʧ�޺ۡ�\n"NOR, me);
	}	
		
	data = ([
		"name":		"�۳�ķ�ӥ",
		"target":	me,
		"att_1":	"agi",
		"att_1c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);	
		
	return;
}

