#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("��ʿ", ({"wudang taoist","taoist"}) );
        set("gender", "����" );
		set("title","�䵱���");
		set("age",71);
		set("long","��ͯ�պ׷����ɷ���ǣ�һ��������˵�ģ����\n�����䵱�ɾò������ĳ������\n");
        set("combat_exp", 8000000);
        set("attitude", "peaceful");
 	set("no_fly",1);
	set("no_arrest",1);
       
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	set("NO_ASK","�������������ϣ������µף���δ������ţ�\n");
	set("NO_KILL","�������ϣ������µף�����������ţ�\n");
	set_temp("condition_type",NOR CYN" <ɽ����>"NOR);
	
	auto_npc_setup("wudang taoist",300,220,1,"/obj/weapon/","fighter_w","taiji-sword",2);
	set("perform_busy_w","wudang/dodge/five-steps/bazhentu");
	set("perform_unarmed_attack","wudang/dodge/five-steps/bazhentu");
	set("perform_unarmed_attack2","wudang/dodge/five-steps/bazhentu");
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
