#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("����", ({"tiexue apprentice","apprentice"}) );
        set("gender", "Ů��" );
		set("title","��ѩ����");
		set("long","�⣮�������ֱ��Ϊ�Լ�������������ѩ����ķ��棡��\n");
        set("combat_exp", 8000000);
        set("attitude", "peaceful");
        
	set("no_fly",1);
	set("no_arrest",1);
		set("age",23);
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	set("NO_ASK","�������������ϣ������µף���δ������ţ�\n");
	set("NO_KILL","�������ϣ������µף�����������ţ�\n");
	set_temp("condition_type",NOR CYN" <ɽ����>"NOR);
	
	auto_npc_setup("tiexue apprentice",300,220,1,"/obj/weapon/","fighter_w","diesword",1);
//	set("perform_busy_u","legend/blade/shortsong-blade/daojianruomeng");
	set("perform_busy_d","legend/blade/shortsong-blade/daojianruomeng");
	set("perform_weapon_attack","legend/blade/shortsong-blade/daojianruomeng");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void unconcious()
{
	die();
}

void die()
{
	object *sy_inv,obj;
	int j;
	sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			obj = sy_inv[j];
			destruct(obj);
		}
		set("NO_CORPSE",CYN"\nˮ������Ӱ��������"+name()+"��ʬ���ߵ���Ӱ������\n"NOR);
	::die();
}
/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
