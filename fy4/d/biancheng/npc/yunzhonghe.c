#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("���к�",({"yunzhong he","yunzhong","he"}));
    	set("title",WHT"�����嶾"NOR);
	set("long", "
�����嶾֮�ף�ԭ���䵱�Ļ��̳��ϣ���̰��Ůɫ��ʯ�������ϳ�����
�˱䱾����������һ����ζ��Ͷ֮�ɻ������㼣�鲼��ԭ��\n");
	set("age",59);
	set("gender","����");
	set("combat_exp", 7000000);
 	set("attitude", "aggressive");
	
	set("cor", 40);
	set("cps", 40);
	set("agi",40);
	set("fle",100);
    	
    	set("reward_npc",1);
    	set("difficulty",5);
	
//	setting up special NPC function: healer, defense, zombie-killer
// 	defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
	
//	set("defense_type",random(2)+1);	
//	set("zombie-killer",1);
//	set("officer-killer",1);
//	set("dungeon_npc","check");
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,0,"/obj/weapon/","fighter_w","nine-moon-sword",2);
	setup();
	carry_object("/obj/armor/cloth",([	"name": "��ɼ",
    						"long": "һ��˿��ĵ�������������һֻ�ס�\n",
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
	message("vision",name() + "�����һЦ���ֳ����Ǹ��������⣬����һ�Ѵ���ӵĺ��ƹ�\n", 
		environment(),this_object() );
//	environment(this_object())->reset();
	another = new(__DIR__"bosshu");
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
                        me->set_temp("marks/wanma/�����嶾e",1);
        ::die();
}