#include <ansi.h>
inherit SMART_NPC;
string smart_fight();

void create()
{
        set_name("ʦ̫", ({ "sanqing nun","nun" }) );
        set("gender", "Ů��");
        set("title","���幬");
        set("age", 42);
        set("long","��ԭ�Ƕ����Ƴ���ǰ������Ѿ�����Ѹ��涡���ƶ����ˡ�\n");
        set("combat_exp", 8000000);
        set("attitude", "peaceful");
	set("no_fly",1);
	set("no_arrest",1);

        set("fy41/sq_bolt_1",1);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );

	set("NO_ASK","�������������ϣ������µף���δ������ţ�\n");
	set("NO_KILL","�������ϣ������µף�����������ţ�\n");
	set_temp("condition_type",NOR CYN" <ɽ����>"NOR);

	auto_npc_setup("nun",200,200,0,"/obj/weapon/","fighter_w","necromancy",2);
        setup();    
	carry_object("/obj/armor/cloth")->wear();
	setup();
}

string smart_fight()
{
	object me = this_object();
	if (query_busy())
		return 0;
	message_vision(HIG"$N�����૵��������ģ�����һ�ӣ����о�����ɫ��â����ʱ��Ϊ���ɣ�\n"NOR,me);
	message_vision(HIC"\nһ���������ˮ������\n"NOR,me);
	message_vision(WHT"$N����ʽ����ˮ��������Ϊ�춼ˮ����ɢ����һ��΢�����衣\n"NOR,me);
	message_vision(HIW"\nһ�Ű׹�����ˮ������\n"NOR,me);
	message_vision(WHT"$N����ʽ����ˮ��������Ϊ�춼ˮ����ɢ����һ��΢�����衣\n"NOR,me);
	message_vision(HIM"\nһ���Ϲ�����ˮ������\n"NOR,me);
	message_vision(WHT"$N����ʽ����ˮ��������Ϊ�춼ˮ����ɢ����һ��΢�����衣\n"NOR,me);
	start_busy(2);
	return 0;
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
