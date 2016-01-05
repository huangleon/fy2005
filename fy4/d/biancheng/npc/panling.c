#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("����",({"pan ling","pan"}));
    	set("title",WHT"�����嶾"NOR);
	set("long", "
������Ȼ�������ࡢ���͡����壬ȴ��һֻ�ܺÿ����֣���ָ�ܳ���
Ҳ�ܸɾ���\n");

	set("age",39);
	set("gender","����");
	set("combat_exp", 7000000);
	set("attitude", "aggressive");
	
    	set("reward_npc",1);
    	set("difficulty",5);
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,0,"/obj/weapon/","fighter_w","nine-moon-claw",1);
	setup();
	carry_object("/obj/armor/cloth",([	"name": HIG"������"NOR,
    						"long": "һ�������ѣ�����˵��������֡�\n",
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
	message("vision",name() + "�����һЦ���ֳ����Ǹ���ʵ�Ĳ�������ʵ������ϰ塣\n", 
		environment(),this_object() );
	another = new(__DIR__"bosszhang");
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
                        me->set_temp("marks/wanma/�����嶾a",1);
        ::die();
}


