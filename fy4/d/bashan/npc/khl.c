#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("��ˮ", ({ "sinny"}) );
        set("gender", "����" );
        set("title","�����ɫʹ����");
        set("age", 32);
        set("long", "\n");
        set("combat_exp", 8000000);
        set("attitude", "friendly");
	set("no_fly",1);
	set("no_arrest",1);
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	set("NO_ASK","�������������ϣ������µף���δ������ţ�\n");
	set("NO_KILL","�������ϣ������µף�����������ţ�\n");
	set_temp("condition_type",NOR CYN" <ɽ����>"NOR);


	auto_npc_setup("sinny",300,220,1,"/obj/weapon/","fighter_w","xuanyuan-axe",2);
	
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
