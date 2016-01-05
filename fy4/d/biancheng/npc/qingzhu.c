#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("������",({"qingzhu she","qingzhu","she"}));
    	set("title",WHT"�����嶾"NOR);
	set("long", "�����ߵĶ�ֻ�����������ֵ��˲�֪����������\n");

	set("age",59);
	set("gender","����");
	set("combat_exp", 6000000);
	 set("attitude", "aggressive");
	
    	set("reward_npc",1);
    	set("difficulty",5);
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(60) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","herb",1);
	setup();
	carry_object("/obj/armor/cloth",([	"name": "��Ƥ��",
    						"long": "��ʵ��ֻ��һ������ͨͨ�Ľ����£����ĵ�͸���̹⡣\n",
    						 ]))->wear();    
}


int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object another;
	message("vision",name() + "�����һЦ���ֳ����Ǹ�������Χȹ�д����˵Ķ����ġ�\n", 
		environment(),this_object() );
	another = new(__DIR__"bossding");
	another->move(environment(this_object()));
	destruct(this_object());
}


void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        if(me->query("marks/wanma/�ײ�֮��"))
                        me->set_temp("marks/wanma/�����嶾d",1);
        ::die();
}