#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("����", ({"shaolin monk","monk"}) );
        set("gender", "����" );
		set("title","���ָ�ɮ");
		set("long","���Ǹ���ü��ɮ����Ŀ���飬����ûһ���꣬Ҳ�о�ʮ\n�꣬����ׯ�سֳɣ�һ����֪�Ǹ��е���ɮ��\n");
        set("combat_exp", 8000000);
        set("attitude", "peaceful");
        
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

		set("age",93);
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	set("NO_ASK","�������������ϣ������µף���δ������ţ�\n");
	set("NO_KILL","�������ϣ������µף�����������ţ�\n");
	set_temp("condition_type",NOR CYN" <ɽ����>"NOR);
	
	auto_npc_setup("shaolin monk",300,220,1,"/obj/weapon/","fighter_w","tianlongwhip",1);
	set("perform_busy_u","shaolin/whip/tianlongwhip/sizhuatianlong");
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
