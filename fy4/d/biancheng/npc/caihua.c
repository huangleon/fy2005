#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("�ɻ���",({"caihua feng","feng"}));
    set("title",WHT"�����嶾"NOR);
	set("long", "
���˵���Ƥ����������ȴ���Ǵ���΢Ц������Ц�ݱ����ǿ������ϵġ���\n");
	set("age",39);
	set("gender","Ů��");
	set("combat_exp", 6200000);
	set("attitude", "aggressive");
	
	set("reward_npc",1);
    set("difficulty",3);
    	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	      	(: auto_smart_fight(20) :),    
       }) );
	
	auto_npc_setup("liaoyin",200,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
	set_skill("tanzhi-shentong",170);
	
	setup();
	carry_object("/obj/armor/cloth",([	"name": RED"����������"NOR,
    						"long": "һ�����������䣬�����úܡ�\n",
    						 "value":	1,
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
	message("vision",name() + "�����һЦ���ֳ����Ǹ�������Ц�ĳ´��ġ�\n", 
		environment(),this_object() );
	another = new(__DIR__"bosschen");
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
                        me->set_temp("marks/wanma/�����嶾b",1);
        ::die();
}

