// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
void smt_fight();

void create()
{
	object weapon;
        set_name("��ڣ", ({ "samurai iizuka","iizuka", "samurai" }) );

        set("gender", "����" );
		set("age",47);

        set("long","һ��˫�ֳֳ����������������ɱ�������ˡ�\n");



	set("no_fly",1);
	set("no_arrest",1);

	set("nickname",MAG"����"NOR);
	set("title","��������");

        set("combat_exp", 2900000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smt_fight() :),
             }) );


        set_skill("blade", 240);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("ittouryu", 300);
        set_skill("ghosty-steps", 220);

		set_temp("no_busy",3);
		set("no_busy",3);

		set("max_kee",16000);

        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("dodge", "ghosty-steps");

		setup();

        weapon=carry_object("/obj/weapon/blade/pxblade");
        weapon->set_name(RED"Ұ̫��"NOR, ({ "no-dachi" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("�����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("����", ({ "hat" }) );
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wear();



}

void smt_fight()
{
	set("bellicosity",1);
	ccommand("perform hyakki");
	return;
}

void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (!me)
		me=this_object();
	
	message_vision(HIR"\n��ڣ������Ѫ�������е����˸¡�������\n"NOR+CYN"������һ������ͷ��\n"NOR,me);

	if (REWARD_D->riddle_check(me,"�ع�����") == 3) 
		REWARD_D->riddle_set(me,"�ع�����",4);

	tell_object(me,HIC"\nڤڤ֮������һ�������������е�������ǰҹħ̳�����Ƽ���ȡ�����������ճ������鱨��
�ְ���ҥ����������ԭ����֪��������ڴ�����ҵ�������御������������Щ����������\n\n"NOR);
	
	tell_object(me,HIY"�������ı��ˣ�\n"NOR);

	me->set("quest/short", WHT"����������"CYN+"��Ѫƽ��"+WHT"���֮��"NOR);
	me->set("quest/location", "��ϼɽ��");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());

	new("/obj/food_item/newbie_food")->move(me);

	::die();
	return;
}