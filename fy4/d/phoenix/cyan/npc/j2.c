// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
void smt_fight();

void create()
{
	object weapon;
        set_name("������֪��", ({ "konda michiko","konda", "michiko" }) );

        set("gender", "Ů��" );
		set("age",27);

        set("long","��Ȼ������ף�����Ȼ��������毺õ�������Ƴ�������\n");



	set("no_fly",1);
	set("no_arrest",1);

	set("nickname",MAG"����"NOR);
	set("title","��������");

        set("combat_exp", 5000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smt_fight() :),
             }) );


        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("kongshoudao", 200);
        set_skill("ghosty-steps", 220);

		set_temp("no_busy",3);
		set("no_busy",3);

		set("max_kee",12000);

        map_skill("unarmed", "kongshoudao");
        map_skill("dodge", "ghosty-steps");

		setup();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("ҹ��װ", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("�����", ({ "mask" }) );
		weapon->set("armor_worn","����");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wear();



}

void smt_fight()
{
	set("bellicosity",1);
	ccommand("perform yaozhan");
	return;
}

void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (!me)
		me=this_object();
	
	message_vision(HIB"\n������֪��һ���֣�����ͻ������ǰ������\n�ȵ�����ɢ����������ȥ��",me);

	tell_object(me,MAG"\n�������Զ������˲���ͷ���ŷ��ֶ�ǰ��ͷ����ʪ��һƬ���������
Ů�ӳ��־��ÿ��׼��Ҫ��ʵ����һ���Ѳ��Ķ��֡�\n\n"NOR);
	
	tell_object(me,WHT" ңԶ��ɽ�䴫��Ʈ�첻���ĵ���������������Լ������������ɤ����
����֦�ϻ��������ˣ�������ɫ���ഺ�����տ��������ƣ��񳯿��������䣮����

"CYN"�����������۾�����һ���ޱߵľ���Ϯ����£�����\n"NOR);

	me->set_temp("disable_inputs",1);
	call_out("do_no",1,me);

//	me->leftnow();

//	::die();
	return;
}

void do_no(object me)
{
	if (objectp(me)) {
		me->delete_temp("disable_inputs");
		me->leftnow();
		return;
	}
	if (objectp(this_object()))
		::die();
}