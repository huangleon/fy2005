#include <ansi.h>
inherit NPC;

void create()
{
        set_name("Ӧ����", ({ "ying wuwu","ying","wuwu" }) );
        set("long","һ��������������Ϲ�ӣ���ͷ������ɫ���·����ǻ����˵���ɫ��\n");

        set("attitude", "friendly");
	set("age",49);
	set("nickname", HIG"�Ŀ��"NOR);

        set("combat_exp", 2500000+random(2500000));

	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("softsword",200);
	set_skill("parry",700);
	set_skill("dodge",700);
	map_skill("sword","softsword");

        setup();

        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

void heart_beat()
{
	::heart_beat();
	if(query("sad_leave"))
		call_out("sad_leave",2);
}

int do_busy(object who)
{
	object room,ying,yang,hook,sword;
	
	ying=this_object();
	room=environment(ying);
	if(!present(who,room)) return 0;
	if(who->query_skill("move",1)>99
		&&(hook = present("leave hook",who))
		&&(yang = present("yang zheng",room)))
	{
		message_vision(YEL"Ӧ����������һ������$N����������ס$N������Ѩ����$N����һ�ӡ�\n"NOR,who);
		message_vision(HIM"��$N�ڵ���֮ǰ���þ����һ˿������������Ӹ����\n"NOR,who);
		yang->set_temp("����𹳵���",who);
		hook->move(yang);
		if(sword=present("sword",yang))
			if(sword->query("equipped"))
		yang->ccommand("unwield sword");
		yang->ccommand("wield leave hook");
		message_vision(WHT"$N��$n���ʾ�⣺����л��λ"+RANK_D->query_respect(who)+"Ϊ���������С���\n",yang,who);
	}
	else
	{
		message_vision(YEL"Ӧ����������һ������$N����������ס$N������Ѩ����$N����һ�ӡ�\n"NOR,who);
		message_vision(YEL"Ӧ������Цһ��������������������ÿ�ν��⣬�ֶ��˸�������һ�̡���\n\n\n"NOR,who);
	}
	who->start_busy(100000);
	ying->set("busy_object",who);
	
}

void sad_leave()
{
	message_vision(CYN"Ӧ���ﳤ̾һ��������ֽ��������������𹳴���֮�֣�ʱҲ����Ҳ����ת����ȥ��\n\n",this_object());
	destruct(this_object());
}
