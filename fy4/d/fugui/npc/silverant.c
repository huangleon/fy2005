#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name(HIC"������"NOR, ({ "silver ant", "ant" }) );
        set("long","
�����ϴ��ż������������·������ϻ����Ÿ�����ߣ����������Ǹ�
�ð������ɵ�С���֣�ʵ��˵�����Ĺ��ؿɲ���\n");
    	set("chat_chance",2);
		set("chat_msg",	({
				"
������̧ͷ���������ϵİ��ƣ���̾һ����������ʮ�����ˣ�����ɽկ��ĵ���
�����˺������������޷��ñ����������ˣ�����ʲô��Ȥ���ԡ���\n",
		"�����Ϻݺݵ��������˵Ľ�ղ�����ôǿ�������װ����ܴ�������͵�㱦�������Ҳ�á���\n"
		
		})  );

        set("combat_exp", 500000 + random (80000));

	set_skill("iron-cloth",100);
	set_skill("jin-gang",80);
	set_skill("unarmed",120);
	set_skill("bloodystrike",100);
	map_skill("iron-cloth","jin-gang");
	map_skill("unarmed","bloodystrike");
	
		set("perform_busy_u", "lama/unarmed/bloodystrike/fofawubian");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{	
	object jinlian;
	if (ob->query("name")==HIW"���÷���"NOR ) 
	{
		REWARD_D->riddle_set(this_player(),"�ɹ�����/������",1);
		write("����������һ�£�ϲ���ݺᣬ��������������ɱ�����Ǹ����ĸ���ͺ¿��
ɱ�����ɸ��ã�������ƥ��һ��������ʹ�࣡��\n");
  	  	command("thank "+this_player()->query("id"));
		if (mapp (this_player()->query("riddle/�ɹ�����")))
		if (sizeof(this_player()->query("riddle/�ɹ�����"))==4)
			REWARD_D->riddle_done( this_player(),"�ɹ�����",50,1);  	  	
  	  	return 1;
	}
	if (ob->query("name")=="������") 
	{
		command("thank "+this_player()->query("id"));
		this_player()->set_temp("marks/silverant",1);
		write("����������һ�£������������õ������ӣ��ø�����ͺ¿�ްɣ�������.....��\n");
  	  	return 1;
	}
	write("�����ϻ���ҡ��ҡͷ��\n");
	return 0;
}		
