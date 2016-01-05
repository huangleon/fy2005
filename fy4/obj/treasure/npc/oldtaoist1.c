#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;

        set_name("���ҵ���", ({"taoist elder","taoist","elder"}) );
        set("gender", "����" );
		set("title","�䵱���");
		set("nickname",HIW"����"NOR);
		set("age",71);
		set("long","��ͯ�պ׷����ɷ���ǣ�һ��������˵�ģ����\n�����䵱�ɾò������ĳ������\n");
        set("combat_exp", 9000000);
      set("attitude", "peaceful");
			set("spawn_location","/d/wudang/pine3");
			set("group","wudang");
			set("max_kee",100000);
			set("max_sen",100000);
			set("max_gin",100000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "���ҵ�������üͷ���ߵ����˵ܵ�����ȥ�ˣ����������ô��ô��\n",
        }) );

		set("no_fly",1);
		set("no_arrest",1);
    		set("real_boss",1);
    set("boss",1);
		set("big_boss",1);
	   
		set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
			(: ccommand("perform dodge.bazhentu") :),
//	       	(: auto_smart_fight(100) :),    
        }) );

		auto_npc_setup("wudang taoist",300,220,0,"/obj/weapon/","fighter_w","taiji-sword",2);
		set("perform_busy_w","wudang/dodge/five-steps/bazhentu");
		set("perform_unarmed_attack","wudang/dodge/five-steps/bazhentu");
		set("perform_unarmed_attack2","wudang/dodge/five-steps/bazhentu");
		setup();

   	weapon=carry_object("/obj/weapon/sword");
    weapon->set_name(HIC"���ҽ�"NOR, ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();
		weapon->set("nodrop_weapon");
    weapon=carry_object("/obj/armor/cloth");
    weapon->set_name("���ڵ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",1);
	set("drop/common_drop",({
		__DIR__"obj/cq2",
	}) );
	set("drop/rare_drop",({
		"none",
	}) );
	
}


void die()
{
	object who = query_max_damage_dealer();
	object lotus;

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);
	::die();
	return;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
