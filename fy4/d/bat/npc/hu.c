#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("������", ({ "hu tiehua","hu" }) );
	set("title",HIB "�޾�����" NOR);
	set("gender", "����" );
	set("age", 35);
	set("no_heal",1);
    set("long","���⣬������������Ҳҵĺ����ӣ�Ҳ�������������������Ц�ݣ�
һ˫�ֺ������Ĵ��۾�, �����ǳ�������õ����Ѻ����������������ӡ�\n");
    set("combat_exp", 4600000);
	set("attitude", "friendly");
		
	set("chat_chance", 1);
    set("chat_msg", ({
               	"������˵������������ƽ����Ȯ��ѽ ��\n",
				"������ĬȻ���Σ�˵������֪�ϳ������������� ��\n",
    }) );
    
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
     }) ); 		

	auto_npc_setup("wang",220,200,0,"/obj/weapon/","fighter_u","luori",1);
	set_skill("fengyu-piaoxiang", 250);
	
	setup();	
	carry_object("/obj/armor/cloth",([	
    						"name":  "ȾѪ�ĳ���",
    						"long": "һ������������Ѫ����㣬��Ŀ���ġ�\n",
    						 ]))->wear();

}


/*
void die()
{
	int i;
	object killer,owner;
	if(objectp(killer = query_temp("last_damage_from")))
        if(owner=killer->query("possessed")) {
		killer=owner;
	} 
        killer->set_temp("marks/murderhu", 1);
	::die();

}

void init()
{	
	::init();
	add_action("do_killing", "kill");
    
}

int do_killing(string arg)
{
    	object player, victim;
    	string id;
    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
		return notify_fail("����û������ˡ�\n");
    	if(living(victim))
    	{
        	id=victim->query("id");
       		if(victim == this_object())
        	{
            	message_vision(HIW
"$NЦ����������ԭ���ƵĽ赶ɱ��֮���ˣ������������ң�����������̽��ʵ��\n"NOR, this_object());
            	return 0;
        	} 
    	}
    	return 0;
}*/