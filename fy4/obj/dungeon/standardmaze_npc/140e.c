// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
void smart_fight();
#include <combat.h>

void create()
{
	object weapon;
        set_name("�ᴺ��", ({ "yi chunqiu","yi","chunqiu" }) );
        set("title",WHT"��ī����"NOR);
		set("nickname",MAG"�����ŵ�Ц�ҳ�"NOR);
        set("gender", "����" );
		set("class","moon");

		set("age",33);
        set("combat_exp", 10000000);

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );
//		set_temp("apply/haste",200);

        set_skill("unarmed", 250);
        set_skill("luoriquan", 250);
        set_skill("iron-cloth", 220);
        set_skill("xisui", 220);
        set_skill("magic", 220);
        set_skill("force", 220);
        set_skill("snowforce", 220);
        set_skill("music", 220);
        set_skill("blade", 220);
        set_skill("sword", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("chillblade", 220);
        set_skill("qiuzhi-sword", 180);
        set_skill("tie-steps", 220);
        set_skill("stormdance", 200);
        set_skill("lingxi-zhi", 200);
        set_skill("calligraphy",250);


        map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "calligraphy");
        map_skill("blade", "chillblade");
        map_skill("magic", "music");
        map_skill("force", "snowforce");
        map_skill("sword", "qiuzhi-sword");
        map_skill("parry", "qiuzhi-sword");
        map_skill("dodge", "tie-steps");

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("������ī��", ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();


		weapon=carry_object("/obj/weapon/fist");
		weapon->set_name("һ�㴺���", ({"pen" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->set("weapon_wielded","��");
		weapon->wield();
//		weapon->set("weapon_wielded","��");
}




void smart_fight()
{
	object ob,target;
	mapping buff;
	object *enemy;
	string msg;
	int i;
	object me = this_object();

	switch (random(4))
	{
	case 0:
		if (!present("��",environment()))
		{
			message_vision(MAG"\n�ᴺ��ʷ����ת�ۼ����ڵ�������һ�����ġ������֡�\n"NOR,me);
			target = new("/obj/treasure/npc/obj/ward2");
			target->move(environment());
			target->heal_ob(me,24);			// +1 busy every 5 turns
			perform_busy(2);
			return;
		}
		break;
	case 1:
		if (!present("��",environment()))
		{
			message_vision(RED"\n�ᴺ��ʷ����ת�ۼ����ڵ�������һ�����ġ��ˡ��֡�\n"NOR,me);
			target = new("/obj/treasure/npc/obj/ward3");
			target->move(environment());
			target->heal_ob(me,24);			// 300+ random(500) kee damage every 5 turns
			perform_busy(2);
			return;
		}
		break;
	
	}
	
/*
	if (!present("��",environment()) && (query("kee") < query("max_kee") / 3 || query("gin") < query("max_gin") / 3 || query("sen") < query("max_sen") / 3))
	{
		message_vision(CYN"\n�ᴺ��ʷ����ת�ۼ����ڵ�������һ�����ġ������֡�\n"NOR,me);
		target = new("/obj/treasure/npc/obj/ward");
		target->move(environment());
		target->heal_ob(select_opponent(),24);
		perform_busy(2);
		return;
	}*/

	if (is_busy())
		return;

	target = select_opponent();

	message_vision(WHT"\n$N��Ȼ���˴󷢣���ͷɢ���������ú���һ£����һƪ��֮ɥ����������ˮ��һ���ǳɣ�\n",me);
	add_temp("apply/attack",150);
	add_temp("apply/damage",100);
	msg=HIC"��֮���ף�\n"NOR WHT"$N����Ʈ�ݣ�����ʵ����ݺ�֮����������Ͱ���$n��ȥ��"NOR;
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);

	msg=HIC"��ɥ��֮������Ĺ���ݱ������\n"NOR WHT"$N���δ󿪴��أ�һ��һ�����Ǳ��ߣ���籩�������$n��"NOR;
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);

	msg=HIC"����׷Ω������\n"NOR WHT"$N���ⶸ�䣬���ֳٻ����أ�����ǧ��֮������$n��"NOR;
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);


	msg=HIC"����������Ľ�ݾ���ʹ���ĸΣ�\n"NOR WHT"$w"WHT"�������ɣ�����Ҳ���أ��Ƴ��֮��������Ҳ�վ��������֮�ѣ�"NOR;
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);

	i=3;
	add_temp("apply/damage",-100);
	add_temp("apply/attack",-150);
	perform_busy(i);
	return;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/


