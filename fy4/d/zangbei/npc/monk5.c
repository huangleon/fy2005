#include <ansi.h>
inherit SMART_NPC;
int talkshow();

void create()
{
	set_name("ֱ���µ�����",({"zhigong lama","lama"}));
	set("long", "����ֱ���´�ɨ��Ժ�����\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 1200000);
	
   	set("inquiry", ([
		"ת��":		"����ǧת���������ã�\n", 
		"˾������": "��ﾫ��ͷ���Եģ��Ҿ�֪����û�����ġ�\n",
   	]));
   		
	set("chat_chance", 10);
        set("chat_msg", ({
		(: talkshow() :), 
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(50) :),    
        }) );
	
	auto_npc_setup("wang",120,160,0,"/obj/weapon/","fighter_u","yizhichan",1);
	
	setup();
	carry_object(__DIR__"obj/lamacloth")->wear();
	
}

int talkshow() {
	object room,*env,ob;
	int i;
	
	ob = this_object();
	env = all_inventory(environment(ob));
	for (i=0;i<sizeof(env);i++) {
		if (userp(env[i])) {
			message_vision("$N����¯�����һ���㣬��ͷ���֣����ﲻ֪�������Щʲô��\n",ob);
			return 1;
		}
	}
	
	room=find_object(AREA_ZANGBEI"pine1");
	if (!objectp(room)) room= load_object(AREA_ZANGBEI"pine1");
	message("vision","\nž��һ�������£�������ֱ���µ�����ͷ����\n",room);
	message("vision","�����Ĺ����ˣ�ָ���������Ͻǵ������ƿڴ��X����������������㣡����\n",room);
	env=all_inventory(room);
	for (i=0;i<sizeof(env);i++)
		if(userp(env[i])) env[i]->set_temp("marks/zangbei/����",1);
	return 1;
}

