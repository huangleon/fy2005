// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// DONT KILL ME ...


inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
	object armor,weapon;
	set_name("������", ({ "suu zhanqing","suu"}) );
	set("gender", "Ů��" );
	set("title","˪������");
	set("nickname",CYN"������ɫ"NOR);
	set("age", 17);

	set("attitude","friendly");
	set("no_drop",1);
    set("combat_exp", 8000000);	
    set("score", -10000);
	set("per",36);
	set("force",2500);
	set("max_force",2500);
	set("force_factor",130+random(100));
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("class","moon");

	set("no_fly",1);
	set("no_arrest",1);
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);
	
	set_skill("heavendance",250);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("move",200);
	set_skill("dodge",200);
    set_skill("perception",200);
	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("lingxi-zhi", 170);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("stormdance",261);
	set_skill("move",200);
	set_skill("dodge",200);


	set("chat_chance", 1);
        set("chat_msg", ({
                "��������Ŀ���⣬�����ҹ��Σ�һ�����꾫�����ӡ�\n",
                "������������̾��ˮ���ȥ�䵱Ҳ��һ��ʱ���ˣ���֪��������\n",
                }) );


    set("inquiry", ([
        "ˮ����":   "����ʶ��ˮ��㣿",
         ]) );

		map_skill("spells","kwan-yin-spells");
		map_skill("force", "divineforce");
    	map_skill("dodge","stormdance");
    	map_skill("move","stormdance");
    	map_skill("blade","heavendance");
    	map_skill("parry","heavendance");
    	
	set_skill("kaleidostrike",500);
	map_skill("unarmed", "kaleidostrike");


		add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight(this_object()) :),
        }) );

	setup();

	carry_object(__DIR__"obj/longskirt",([	
    						"name":  MAG"ϼ�Ʋ��"NOR,
    						"long": "һ��ǳ��ɫ���ŵس�ȹ��\n",
    						 ]))->wear();
	
	weapon = carry_object("/d/huashan/npc/obj/qingcong");
	weapon->set_name(WHT"����ˮ��"NOR, ({ "slippery sleeve" }) );
	weapon->set("unit", "˫");
	weapon->set("long", "\n");
	weapon->set("weapon_wielded","��");
	weapon->wield();

    set("reward_npc", 1);
	set("difficulty",40);
}

void init()
{
	add_action("do_look", "look");
}


int do_look(string arg)
{
	object me = this_player();
	if (arg == "south")
	{
		me->add_temp("annie/blocked_by_suu",1);
		switch (me->query_temp("annie/blocked_by_suu"))
		{
		case 1:
			message_vision(CYN"������������ס$N�����Բ��𣬽���������Ǳ���ԡ���벻Ҫ̽ͷ̽�ԡ�\n"NOR,me);
			return 0;
			break;
		case 2:
			message_vision(CYN"�������$N��ü�����Ҳ����Ѿ������㲻Ҫ�ҿ���ô��\n"NOR,me);
			return 0;
			break;
		case 3:
			message_vision(CYN"���������$Nһ�ߣ�����һ��Ҫ�����ˣ�\n"NOR,me);
			return 0;
			break;
		}
		message_vision(CYN"���������������\n"NOR,me);
		me->delete_temp("annie/blocked_by_suu");
		kill_ob(me);
		return 0;
	}

}

int kill_ob(object who)
{
	object me;
	int exp_r,busyst;
	string msg;
	::kill_ob(who);
	if (who->is_zombie() == 1)
	{
		msg = HIW "$N�������֣������е���ǹ���˸��ɲ�Ǽ�����������ţ�����\n" NOR;
		message_vision(msg,this_object());
		who->die();
		return 1;
	}
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


varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	message_vision(CYN"\n����������һ�ߣ���Ȼ������\n"NOR, this_object());
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
	if (ccommand("perform force.check_gspm"))
		ccommand("perform force.guishenpomie");
	ccommand("perform force.manaflare");

	tar = me->query_enemy();
	if (sizeof(tar) > 1)
	{
		message_vision(CYN"\n$Nһ�����Ƴ��䣬һ������֮���ڳ�����ת��ɢ��\n"NOR,me);
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
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,CYN"$N����һ�����ȣ����ɼ�����$n��ȥ��"NOR);
			tar[i]->add("force_factor",-query("force_factor")/2);
			tar[i]->perform_busy(j+random(2));	// busy 0~1.
			target->add_temp("no_check_pfm_win",-1);
		}
	}

	target = select_opponent();
	message_vision(HIY"\n$N��������ʹ����ĺѩ��̾��֮ʽ���ĳ�һ������Ϯ��$n��\n"NOR,me,target);
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
				message_vision(HIY"\n$n��ת������Ȧ�����ν�ֹ��ͻ�ֻ���һ�𣬵����ڵء�\nԭ����������ʽ��ĺѩ��̾���������㾢���������ȫչ����\n"NOR,me,target);
				target->receive_damage("kee",target->query("max_kee") / 5-100,me);
				target->receive_wound("kee",target->query("max_kee") / 10-100,me);
				COMBAT_D->report_status(target);
			}
			else
			{
				message_vision(HIR BLK"$n�۵����һ����Ѫ��������������ǿ��׮վ�ȡ�\n"NOR,me,target);
				COMBAT_D->report_status(target);
			}
		}
		else
		{
			message_vision(HIR BLK"$n�۵����һ����Ѫ��������������ǿ��׮վ�ȡ�\n"NOR,me,target);
			COMBAT_D->report_status(target);
		}
	}
	else
	{
		message_vision(HIR BLK"$n��״�󾪣����������������ն����\n\n"NOR,me,target);
	}
	return;
}
