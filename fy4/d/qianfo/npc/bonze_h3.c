// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int jice();

void create()
{
	object weapon;
        set_name("������ʦ", ({ "hui qi", "huiqi" }) );
        set("gender", "����" );
        set("class", "bonze");
	set("title","�˹����»��ֱ���ʦ");
	set("long","
������ʦ���ױ����˹����³��ң����𱲷ֻ��������˹���ʦ��ʦ�壬ֻ��
��������������¶����������ж���Ϊ�֡�\n");
        set("age", 89);
        set("combat_exp", 6000000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );

		set("death_msg",CYN"\n$N��е����㡫����������������\n"NOR);

            set("inquiry",([
 		"������"  : (: jice :),
           ]) );
		setup();

        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
    	auto_npc_setup("ouyang",220,200,0,"/obj/weapon/","fighter_w","thunderwhip",1);
}





int jice()
{
	object me;
	me = this_player();
	if (me->is_fighting())
	{
		message_vision("$N��ɫһ�䣬ǿ���򶨵������Ĳ������¾��ӣ���λʩ������ȥ����˴����ա�\n",this_object(),me);
		return 1;
	}
	if(REWARD_D->riddle_check(me,"̽��׷Դ") != 5)
	{
		message_vision("$N��ɫһ�䣬ǿ���򶨵������Ĳ������¾��ӣ���λʩ������ȥ����˴����ա�\n",this_object(),me);
		return 1;
	}

	if (query("doing"))
	{
		message_vision("$N��ɫһ�䣬ǿ���򶨵������Ĳ������¾��ӣ���λʩ������ȥ����˴����ա�\n",this_object(),me);
		return 1;
	}

	message_vision(WHT"$N����ɫ���ûҰ�������ƵƵ�����\n"NOR,this_object(),me);
	message_vision(CYN"$N���ɵ����㣬����˭��������֪�����£�\n"NOR,this_object(),me);

	tell_object(me,HIR"\n�����ǻ����˲���ƭ�㣬������ʦ��Ȼ�����⣬���ְգ�\n"NOR);

	set("doing",1);

	REWARD_D->riddle_set(me,"̽��׷Դ",6);

	return 1;
}

void die()
{
	object me = query_temp("last_damage_from");
	if(!me || REWARD_D->riddle_check(me,"̽��׷Դ") != 6)
	{
		::die();
		return ;
	}


	message_vision(CYN"$N��������������������������ϸ����������������ô����\n"NOR,this_object(),me);
	message_vision(CYN"$NŻ��һ����Ѫ���ҲҶ�Ц������Ҳ�ã��ҾͲ��ᣮ���ٰ���������ǰ���ˣ���\n"NOR,this_object(),me);
	message_vision(CYN"$N��ָץ�ڵ��ϣ����������ҷ𣮣����ȣ�����������\n"NOR,this_object(),me);
	REWARD_D->riddle_set(me,"̽��׷Դ",7);


	tell_object(me,HIR"\n���·��·ת����Ȼ�������Σ�����Ҳֻ�ܻ���ϼɽ���һ������ʸ������\n"NOR);
	::die();
	return ;
}
