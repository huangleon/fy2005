// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// �˲���֮Ǭ������ ���ﻨ�� ˮ���� 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 80 DMG 77 ATTACK 76K DODGE 76K PARRY 76K
// IMMUNE TO BUSY,ABSORB IRON-CLOTH,POISON ENCHANTED
// �Կ�TK����Ч

// A/D/P���Ը��ڱ�׼8M�����˿�TK��

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
	object armor,weapon;
	set_name("ˮ����", ({ "shui ruxi","shui"}) );
	set("gender", "Ů��" );
	set("title",YEL"������� "NOR CYN"Ǭ������"NOR);
	set("nickname",HIW"���ﻨ��"NOR);
	set("age", 20+random(10));

	set("attitude","friendly");

	set("long",
		"������������������������ϣ�һ��ˮ��ɫ���ɴ��ȹ���ҷ�\n�����䷭�ɣ����ŵ��Ϸ����Ĵ�����˿���ڷ���Ʈ�費������\n�ܱ������㣬��ò�Ѽ������������һ�ۼ�����Ϊ�Ǵ�׹����\n�����ӣ��˿������˷��ȥ��\n"
		);
	set("class","demon");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("str",20);
	set("per",200);
	set("force",2500);
	set("max_force",2500);
	set("force_factor",130+random(100));
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_arrest",1);
	set("real_shui",1);
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);
	
	set_skill("heavendance",220);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("stormdance",220);
	set_skill("move",200);
	set_skill("dodge",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("lingxi-zhi", 170);
	set_skill("divineforce", 200);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);

	set("chat_chance", 1);
        set("chat_msg", ({
                "ˮ��������һ�ߣ�˵����"YEL"�䵱"NOR"����"YEL"��������"NOR"����ʧ��������ʲô�䵱��\n",
                "ˮ����ҡҡͷ����"YEL"ʯ��"NOR"���£������ݰ�������Ҳ̫�����䵱���ˡ�\n",
                "ˮ����̾��������һ���ˣ���֪�������������Ǳ߹�����Σ�����\n",
                "ˮ�������׿��������У���������⻹���ϴξ͸�����������ģ�ʲôʱ����п���ȥ�أ�\n",
                }) );

    set("inquiry", ([
        "̫���ķ�": "��Ц"YEL"�䵱������"CYN"ȥ��"YEL"̫���ķ�"CYN"�н����������ľ���\n��ʧ������ȥ�Ұ���ʱ�䷽��������ؼ����ҵ���",
        "�䵱��":   "��Ц"YEL"�䵱������"CYN"ȥ��"YEL"̫���ķ�"CYN"�н����������ľ���\n��ʧ������ȥ�Ұ���ʱ�䷽��������ؼ����ҵ���",
        "�䵱":   "��Ц"YEL"�䵱������"CYN"ȥ��"YEL"̫���ķ�"CYN"�н����������ľ���\n��ʧ������ȥ�Ұ���ʱ�䷽��������ؼ����ҵ���",
        "����":   "actionˮ�����������߷�˿���ƺ�û���������������",
        "ħ��":   "actionˮ�����������߷�˿���ƺ�û���������������",
        "�������":   "actionˮ�����������߷�˿���ƺ�û���������������",
        "�������":   "actionˮ�����������߷�˿���ƺ�û���������������",
        "�ݰ�":   "actionˮ��������һЦ�����׹˵���Ʃ���㣬���Ǹ���ݰ���",
        "��ݰ�":   "actionˮ��������һЦ�����׹˵���Ʃ���㣬���Ǹ���ݰ���",
        "ʯ��":   "˵ʲô�������ˣ������Ǻ�����Щ����һ����ݰ���������ϧ��",
        "�䵱������":   "�����ŵ�Ҳ���飬��������"WHT"�ݰ�"YEL"ʯ��"CYN"�������ϣ�\n��ȡ�����䵱�ɻ�Ҫ��Щ�����鷳��\nˮ����ƲƲ�������������ʯ�������ĵ��ӣ�Ҳ�Ͳ���������\nʶ�˲��壬�������ң��Ծ�����������Ҳ��ԩ�ˡ�",
        "������":   "�����ŵ�Ҳ���飬��������"WHT"�ݰ�"YEL"ʯ��"CYN"�������ϣ�\n��ȡ�����䵱�ɻ�Ҫ��Щ�����鷳��\nˮ����ƲƲ�������������ʯ�������ĵ��ӣ�Ҳ�Ͳ���������\nʶ�˲��壬�������ң��Ծ�����������Ҳ��ԩ�ˡ�",
        "�ϵ�����":   "����ֻ�����Ǿ���һ�����ӣ�����С�䣬��ֵһ�ᡣ",
        "ľ����":   "����ֻ�����Ǿ���һ�����ӣ�����С�䣬��ֵһ�ᡣ",
         ]) );

	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "divineforce");
    	map_skill("dodge","stormdance");
    	map_skill("move","stormdance");
    	map_skill("blade","heavendance");
    	map_skill("parry","heavendance");
    	

		add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight(this_object()) :),
        }) );

	setup();

	carry_object(__DIR__"obj/longskirt")->wear();
	carry_object(__DIR__"obj/cyin")->wield();

	carry_object(__DIR__"obj/paper5");

    set("reward_npc", 1);
	set("difficulty",20);

}

int kill_ob(object who)
{
	object me;
	int exp_r,busyst;
	::kill_ob(who);
	stop_busy();
	smart_fight(who);
	return 1;
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}


void force_busy(int busy)
{
	message_vision(CYN"\nˮ������ȹƮ�ɣ�����������֮�⡣\n"NOR, this_object());
	return;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	message_vision(CYN"\nˮ������ȹƮ�ɣ�����������֮�⡣\n"NOR, this_object());
	return;
}


void smart_fight(object who)
{
	object me,target,item;
	object * tar;
	object shadow,hisweapon,newweapon;
	int i,j,temp,num,temp1,num1;

	me = this_object();

	if (who != me)
		target = who;
	else
		target = select_opponent();
	
	ccommand("perform force.baocanshouque");

	tar = me->query_enemy();
	if (sizeof(tar) > 1)
	{
		message_vision(WHT"\n$N���ĵ�̾�����ж�Ϊʤ����ʲôӢ���о�������\n$Nһ��ˮ�䣬һ������ɫ��˿�߷ɼ�����������������ȥ��\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

// Ϊ����parry busy��Ч(��,̫����),���ﲻʹ��mimic function....
			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
			tar[i]->add("force_factor",query("force_factor")/2);
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,WHT"����ɫ��˿�߷���$N��$N����һ�����ȣ����ɼ�����$n��ȥ��"NOR);
			tar[i]->add("force_factor",-query("force_factor")/2);
			tar[i]->perform_busy(j+random(2));	// busy 0~1.
			target->add_temp("no_check_pfm_win",-1);
		}
	}

	target = select_opponent();
	if (!target->query_temp("annie/chillingheart") && target->query("kee") > 0)
	{
		target->set_temp("annie/chillingheart",1);
		message_vision(WHT"\n$N"WHT"��ʽ��ܣ������鰴��ǰ��������$n"WHT"��\n"HIW"$n"HIW"����$N"HIW"�峺����������ͻ�������߹Ǳ��紵�����Ŀ���������\n"NOR,me,target);
		target->receive_damage("kee",target->query("combat_exp") / 7500, me);
		call_out("do_chilling",3,me,target,5+random(5));
	}
	return;
}

void do_chilling(object me,object target,int count)
{
	if (!target)	// �뿪ս����ͬ��������Ƶ�ʱ�����condition�죬���ɽ����
		return ;
	if (!me)
	{
		target->set_temp("annie/chillingheart",0);
		tell_object(target,HIW"���еġ�"HIC"ǧ������"HIW"�����ڷ������ˡ�\n"NOR);
		return;
	}
	if (count > 0)
	{
		count = count - 1;
		tell_object(target,HIW"���еġ�"HIC"ǧ������"HIW"�������ˣ�\nһ˿һ�Ƶĺ���͸������������\n"NOR);
		target->receive_damage("kee",target->query("combat_exp") / 7500, me);
		call_out("do_chilling",3,me,target,count);
	}
	else
	{
		target->set_temp("annie/chillingheart",0);
		tell_object(target,HIW"���еġ�"HIC"ǧ������"HIW"�����ڷ������ˡ�\n"NOR);
	}
	return;
}


void die()
{
	object me,owner,enemy,paper,*sy_inv,things;
	int j;
	me = this_object();
	if (!query_temp("last_damage_from"))
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		::die();
		return;
	}
	if (environment(me)->query("short") != "������")
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		::die();
		return;
	}
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	if (paper = present("paper"))
		paper->move(environment());
	enemy->set("annie/demon_killed_shui",1);	
	// not killed_shui,����һ�μ��� // �������ȡ��
	message_vision(CYN"\n$N΢һ��ü���ߵ���ȴ�������ֱ��£���ϧ��������˷Ѹ����Ǹ��ݰ���
$N����������ס��������Ե���պ��Ե������������\n$N��������һ����������Ʈ�ɶ�����ʧ������������ƺ��С�\n$n׷����ʯһ����ֻ����ã�ƺ�������������ȴ���ﻹ��$N����Ӱ��\n\nһ��СֽƬƮƮ���Ƶ��䵽���ϡ�\n\n"NOR,me,enemy);
//	REWARD_D->riddle_done(enemy,"����",100,1);
	destruct(me);
	return;
}

