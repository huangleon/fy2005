// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// ��ʹ���κ�dodge/parry/iron-cloth
// 20M exp,long gks.
// solo? impossible! ������һ����double healer,��buffup�ȵȵ�team��

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("������", ({ "jiang duanxian","jiang"}) );
	set("title",HIW"���Ƶ�һ����"NOR);
	set("nickname",CYN"������ɽ"NOR);
	set("gender", "����" );
	set("age", 20+random(10));
	set("long","������������һ�ۣ�˵������ʲô����û������ħ����ʲô����\n\n");

	set("attitude","friendly");

	set("class","demon");
    	set("combat_exp", 20000000);	
    	set("score", 10000);
	set("per",200);
	
	set("force_factor",130+random(100));
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_arrest",1);

	set("boss",1);

	set("chat_chance", 1);
	set("chat_msg", ({
			"������Ц������ȣ�����Ǽ�����ɫ��\n",
			"�����Ҹ������죬��Ȼ��̾����ĳ��ƽ��ʮ���ޡ�\nһ�޲��˟o�У����޼t��������޽��˲�Ϣ���ĺ����B�כ��������̨��©�������m�~�ཹ��\n�ߺ޺����������˺޼ܻ����̡��ź���ҹ���ã�ʮ��޵�}��򳡣ʮһ��δ�p������ʮ�������o����\n",
			"������ҡҡͷ����ʲô���������죬�ҿ�Ҳ����������\n",
			"������̾�˿��������ϴ�������ʮ���ﾡ������Ҳ���˽�ĳһ���ֽţ���ϧ��ϧ��\n",
			"������������һ�ۣ�˵������ħ������ħ����Ҫ���������������Ź�񫡣\n",
			"�����Ҹ�����������������������ֵ��ļһ������黨���ң���ʲô��ħ����\n",
			}) );

	set("resistance/gin",40);
	set("resistance/kee",40);
	set("resistance/sen",40);

	set("max_kee",256000);
	set("max_gin",192000);
	set("max_sen",128000);
	
	set_skill("heavendance",220);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("stormdance",360);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("hanshan-strike", 200);
	set_skill("divineforce", 200);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);

	
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "hanshan-strike");
	map_skill("force", "divineforce");
    	map_skill("blade","heavendance");
    	
	set_temp("counter_action_extra",1);
	set_temp("counter_msg",CYN"$N������ת�����β������ͣ��������أ�\n"NOR);


        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

	setup();


    set("reward_npc", 1);
	set("difficulty",40);

	set_temp("apply/dodge",-999);

}

int kill_ob(object who)	
{
	object me;
	int exp_r,busyst;
	::kill_ob(who);
	stop_busy();
	smart_fight();
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

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	if (random(8))	// ÿtick��8��busy? *addoil
		message_vision(CYN"\n������������ǣ������������仯�޷���\n"NOR, this_object());
	else
		start_busy(1);
	return;
}


void smart_fight()
{
	object me,target,item;
	object * tar;
	object shadow,hisweapon,newweapon;
	int i,j,temp,num,temp1,num1;

	me = this_object();

	if (random(5))
		ccommand("perform force.baocanshouque");

	if (ccommand("perform force.check_gspm") && !random(5))
		ccommand("perform force.guishenpomie");
	
	tar = me->query_enemy();
	if (sizeof(tar) > 1 && random(2) && time()>query("annie/bf")+4)	// 4��һ��
	{
		set("annie/bf",time());
		message_vision(WHT"\n$N���ƻ��������ƻ�Ȧ����Ȼһ����ȣ�����Ť��Բת�ľ�������������˶������ᡣ\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK," ");
			target->add_temp("no_check_pfm_win",-1);
		}
		start_busy(1);
	}

	if (is_busy())
		return;

	if (!random(3) && time()>query("annie/mb")+10)	// 10��һ��
	{
		set("annie/mb",time());
		message_vision(WHT"\n$N˫ָһ�飬ָ��������������磬Ϯ�����ˣ�\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			target = tar[i];
			target->set("force",target->query("force")/2);
			tell_object(target,CYN"��ֻ��������һ�飬��Ϊ������ָ�����ˣ�"NOR);
		}
		start_busy(1);
	}


	if (is_busy())
		return;

	target = select_opponent();

	if (!random(3) && time()>query("annie/cr")+6)	// 6��һ����
	{
		set("annie/cr",time());
		message_vision(HIY"\n$N��������ʹ��������������֮ʽ���ĳ�һ������Ϯ��$n��\n"NOR,me,target);
		if (random(9))
		{
			message_vision(HIY"$nֻ��һ�����������ľ����纣����������Լ����ϣ�\n"NOR,me,target);
			target->receive_damage("kee",target->query("max_kee") / 5-100,me);
			target->receive_wound("kee",target->query("max_kee") / 10-100,me);
			if (random(6))
			{
				COMBAT_D->report_status(target);
				message_vision(HIY"\n$n�����ת��һ��Ȧ�ӣ�������׮վ�ȣ���Ȼ�ؿ���һ���ʹ�������ش���\n"NOR,me,target);
				target->receive_damage("kee",target->query("max_kee") / 5-100,me);
				target->receive_wound("kee",target->query("max_kee") / 10-100,me);
				if (random(3))
				{
					COMBAT_D->report_status(target);
					message_vision(HIY"\n$n��ת������Ȧ�����ν�ֹ��ͻ�ֻ���һ�𣬵����ڵء�\nԭ����������ʽ�������������������㾢���������ȫչ����\n"NOR,me,target);
					target->receive_damage("kee",target->query("max_kee") / 5-100,me);
					target->receive_wound("kee",target->query("max_kee") / 10-100,me);
					target->perform_busy(1);
					COMBAT_D->report_status(target);
				}
				else
				{
					message_vision(HIR BLK"$n�۵����һ����Ѫ��������������ǿ��׮վ�ȡ�\n"NOR,me,target);
					target->perform_busy(1);
					COMBAT_D->report_status(target);
				}
			}
			else
			{
				message_vision(HIR BLK"$n�۵����һ����Ѫ��������������ǿ��׮վ�ȡ�\n"NOR,me,target);
				target->perform_busy(1);
				COMBAT_D->report_status(target);
			}
		}
		else
		{
			message_vision(HIR BLK"$n��״�󾪣����������������ն����\n\n"NOR,me,target);
			target->perform_busy(1);
		}
		start_busy(1);	// 1/8����busy..
	}

	if (is_busy())
		return;

	if (!target->query_temp("annie/boss_needle") && target->query("kee") > 0 && !random(3))
	{
		target->set_temp("annie/boss_needle",1);
		message_vision(HIB"\n$N˫ָһ����һ��ϸ�緢˿��Ѹ���ε��������������$n��\n"NOR,me,target);
		target->receive_damage("kee",target->query("combat_exp") / 6000, me);
		call_out("do_chilling",5,me,target,5+random(5));
		start_busy(1);	// 1/8����busy..
	}
	return;
}

void do_chilling(object me,object target,int count)
{
	if (!target)	// �뿪ս����ͬ��������Ƶ�ʱ�����condition�죬���ɽ����
		return ;
	if (!me || me->is_ghost())
	{
		target->set_temp("annie/boss_needle",0);
		tell_object(target,HIW"���еġ�"HIC"�������"HIW"�����ڷ������ˡ�\n"NOR);
		return;
	}
	if (count > 0)
	{
		count = count - 1;
		tell_object(target,HIW"���еġ�"HIC"�������"HIW"�������ˣ�\n"NOR);
		target->receive_damage("kee",target->query("combat_exp") / 6000, me);
		call_out("do_chilling",5,me,target,count);
	}
	else
	{
		target->set_temp("annie/boss_needle",0);
		tell_object(target,HIW"���еġ�"HIC"�������"HIW"�����ڷ������ˡ�\n"NOR);
	}
	return;
}

void die()
{
	ccommand("fake");
	::die();
}