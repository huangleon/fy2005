#include <ansi.h>
inherit SMART_NPC;

void create()
{

	set_name("��������",({"hua hua","hua"}));
    	set("title",WHT"�����嶾"NOR);
	set("long", "
�����嶾֮�ף�ԭ���䵱�Ļ��̳��ϣ���̰��Ůɫ��ʯ�������ϳ�����
�˱䱾����������һ����ζ��Ͷ֮�ɻ������㼣�鲼��ԭ��\n");

	set("age",59);
	set("gender","����");

	set("combat_exp", 7000000);
	 set("attitude", "aggressive");
	
    	set("reward_npc",1);
    	set("difficulty",5);
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(60) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","taiji-sword",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/a_book");
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
	message("vision",name() + "�����һЦ���ֳ����Ǹ���ü�������θ���\n", 
		environment(),this_object() );
	another = new(__DIR__"bosssong");
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
                        me->set_temp("marks/wanma/�����嶾c",1);
        ::die();
}