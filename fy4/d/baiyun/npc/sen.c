// �˲���֮Ħ�������� ����ҹ�� ������ 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 100 DMG 25 ATTACK 71K DODGE 71K PARRY 71K
// ʹ����busyΪ��ɫ��feixiansword��*giggle sinny
// �������׹���ɢ��ĩ������

// A/D/P�����ڱ�׼8M�����˿�TK��

inherit SMART_NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("������", ({ "shen yunxing","shen","sen"}) );
	set("gender", "����" );
	set("title",YEL"������� "NOR CYN"Ħ��������"NOR);
	set("nickname",HIB"����ҹ��"NOR);
	set("attitude","friendly");
	set("long",	"������һ����������ϥ�����ڰ���ʯ�ϣ���ǰƽ����һ�Ű߲�\n���٣��ٱ���һ�ѻԹⳤ����\n");
	set("class","baiyun");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",40);
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
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);

	set("chat_chance", 1);
	set("chat_chance", 1);
	set("chat_msg", ({
			"�����Ƕ���Ц����������ã���ʧԶӭ����֪�Ƿ�Ը��һ��"YEL"���Ƴ�"NOR"�⡢"YEL"����ֹϢ"NOR"��\n",
			}) );

    set("inquiry", ([
        "���Ƴ�": "����"YEL"��"CYN"���黭��ʵ������һ������ϧ�����Ķ���־��\n����Ź������֮����ʦ��ȥ����֮������ܳ�����",
        "����":   "����"YEL"��"CYN"���黭��ʵ������һ������ϧ�����Ķ���־��\n����Ź������֮����ʦ��ȥ����֮������ܳ�����",
        "����":   "action������΢΢Ц�������²������¼��ɼ������£���α��ż���",
        "ħ��":   "action������΢΢Ц�������²������¼��ɼ������£���α��ż���",
        "�������":   "action������΢΢Ц�������²������¼��ɼ������£���α��ż���",
        "�������":   "action������΢΢Ц�������²������¼��ɼ������£���α��ż���",
        "Ҷ�³�": "Ҷ�³�ı�ڽ�����������ʦ�������ڽ����������ˣ�\n����ܵð���"YEL"���ɽ���"CYN"Ҫ����",
        "��":   "���Ʒ��ɽ��������ù��ˣ������Ʒ��ȴҲ���ý�����Ҫ��",
        "����":   "���Ʒ��ɽ��������ù��ˣ������Ʒ��ȴҲ���ý�����Ҫ��",
        "���ɽ���":   "���Ʒ��ɽ��������ù��ˣ������Ʒ��ȴҲ���ý�����Ҫ��",
        "����":   "action������Ŀעң����Ⱦ��������̾�˿�����\n��������������˫�ۣ�һ���ֵ�����������������\n",
        "��":   "���ľ����ټ�ʮ���أ���Ȼ�ǵ������ҡ�ֻ�ǲ�֪��Ϊ��\n�㲻�������������������Ȼ�����������Σ���ѧ�ߴ̶�������ȴ��\n���������˲���������",
        "�ٵ�":  "���ľ����ټ�ʮ���أ���Ȼ�ǵ������ҡ�ֻ�ǲ�֪��Ϊ��\n�㲻�������������������Ȼ�����������Σ���ѧ�ߴ̶�������ȴ��\n���������˲���������",
        "����ɢ": "����ɢ��������ֹϢ��ԭ���������ף����Ƶ���������\n�����������������ף�ȴʧ�������׵ľ������ⲻ֪�и�ɽ���Գ�\nƽ�أ��л��ֲųĳ����ˣ�������ʱ˼��ǰʱ�ĺ��ѣ��������յĻ�\n�֣�������������ɢ�����ӡ��ı�̾������������ǰ�������\nͬ��",
        "����ֹϢ":   "����ɢ��������ֹϢ��ԭ���������ף����Ƶ���������\n�����������������ף�ȴʧ�������׵ľ������ⲻ֪�и�ɽ���Գ�\nƽ�أ��л��ֲųĳ����ˣ�������ʱ˼��ǰʱ�ĺ��ѣ��������յĻ�\n�֣�������������ɢ�����ӡ��ı�̾������������ǰ�������\nͬ��",


         ]) );



	set_skill("feixiansword",270);
	set_skill("sword",200);

	set_skill("feixian-steps",240);
	set_skill("move",200);
	set_skill("dodge",200);

	set_skill("chessism",400);
	map_skill("force","chessism");

	set_skill("zensword",240);
	set_skill("demosword",240);
	set_skill("zen",200);
	set_skill("xiaodao",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("eagle-claw", 300);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "eagle-claw");
	map_skill("force", "bolomiduo");
	map_skill("dodge","feixian-steps");
	map_skill("move","feixian-steps");
	map_skill("blade","demon-blade");
	map_skill("sword","feixiansword");
	map_skill("parry","feixiansword");
    	
	add_temp("apply/iron-cloth", 200);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	setup();

	carry_object(__DIR__"obj/sensword")->wield();
	carry_object(__DIR__"obj/sencloth")->wear();
	carry_object(__DIR__"obj/paper6");

    set("reward_npc", 1);
	set("difficulty",7);

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

void init()
{
	object ob;
	if (!is_fighting())
	{
		remove_call_out("play_ting");
		delete_temp("playing");
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
	}
}


void greeting(object ob)
{
        object corpse;
		object me = ob;
		object box;
        if( !ob || environment(ob) != environment() || is_fighting() || query("ting_broken")) return;
			message_vision(CYN"�������������ڵ��ϣ�����΢Ц�����п�Զ�������ǲ�����ӭ������ˡ�\n"NOR,me);
			message_vision(CYN"��������ָһ�������ٶ���һ�죬ҡͷ����������ǰ��˵�³�Ұ��̫��\n�����ڽ������ѳ����ģ����¶����գ������ϲ����ۡ�\n"NOR,me);
			message_vision(CYN"����������̾Ϣ����ˣ���ֻ�����Լ����֣�ȴ�������鷳�ء�\n"NOR,me);
			return;
}


void killed_enemy(object who)
{
	string msg;
	remove_killer(who);
	who->remove_killer(this_object());
	if (!is_fighting())
	{
		remove_call_out("play_ting");
		delete_temp("playing");
		msg = CYN"\n������΢΢һЦ��ҡ��ҡͷ�����������ϳ����������ٷŻ�ϥǰ��\n\n"NOR;
		message_vision(msg,this_object());
	}
}

object *getenemy()
{
	object *enemy,room,*temp;
	int i;
	room = environment();
	temp = all_inventory(room);
	enemy = ({ });
	for (i=0;i<sizeof(temp) ; i++)
	{
		if (temp[i] == this_object())
			continue;
		if (temp[i]->query("name") == HIW"�׺�"NOR)
			continue;
		if (temp[i]->is_corpse() || !temp[i]->is_character()) continue;
		enemy += ({ temp[i] });
	}
	return enemy;
}

int play_ting(int count)
{
	string msg;
	object *enemy,bird;
	int i;
	enemy = getenemy();
	if (!is_fighting() && !query("ting_broken"))
	{
		remove_call_out("play_ting");
		delete_temp("playing");
		msg = CYN"\n������΢΢һЦ��ҡ��ҡͷ�����������ϳ����������ٷŻ�ϥǰ��\n\n"NOR;
		message_vision(msg,this_object());
		return 1;
	}

	switch (count)
	{
	case 1:
		msg = CYN"\n�����Ǿ�����ϥ�����������ٷ���ϥͷ����һ���ң�΢Ц��������ˣ��Ҿ��Թ���ֹϢ���͡���\n\n"NOR;
		message_vision(msg,this_object());
		break;
	case 2:
		msg = HIC"\n��������������Ͱ������滬��ů����棬��������أ�����һ˿һ�����̻�֮����\nһ�з��ǣ���������������Ʈɢ����ֻ��������ů�����µĺӱ߲ݵأ���ǰ���ӻ�����\n��Ⱥݺ�ҷɣ���ǿ����֮��������ɢ��\n\n"NOR;
		message_vision(msg,this_object());
		for (i=0; i<sizeof(enemy); i++)
		{
			tell_object(enemy[i],RED"(�����������ģ��᲻��һ˿������)\n"NOR);
			enemy[i]->perform_busy(1);
		}
		break;
	case 3:
		msg = HIW"\n������΢΢һЦ��ָ��һת�����������ת���ʣ���ͬ�պ�һ��ʢ�е�˿��С��������\n���У���·�����һ�����Ҿ��Ļ��Ƶ���ī��������������ǳǳ��η����Ľ���ɽ\nˮ������������Զɽ���������зɹ���ֻֻ�׺ס�\n\n"NOR;
		message_vision(msg,this_object());
		seteuid(getuid());
		for (i=0; i<3+random(4); i++)
		{
	        bird = new(__DIR__"white_crane");
	        bird->move(environment());
	        bird->invocation(this_object(), 500);
			bird->set("possessed", this_object());
		}
		break;
	case 4:
		msg = HIG"\n��֪����֮����������һ�䣬��ø�Ϊ���䣬��Ϊ��졣���������˵�����ϸ�����\n��֪���Ŀ����̸��ֻ��������ͷ¹ײ�������컷�������ǰ�������Ļ����˫��\n���죬һ������������ɢ��\n\n"NOR;
		message_vision(msg,this_object());
		for (i=0; i<sizeof(enemy); i++)
			enemy[i]->set("force",enemy[i]->query("force")/2);
		break;
	case 5:
		msg = YEL"\n������Ȼֱ����£���Թ��Ľ���������ߡ�����Ӵ�ů������ʱ�ڣ���Ȼ���������ľ\nҶҡ������졣�����ǵ������ˣ�����������ϿԳ�䣬��������ҹ����������ĸ���̣�\n�����������ӵĹ�����ȴ��֪�����Ѿ������޶��ӱߵĿݹǣ�����¥ͷԹ�����ڽ̷���\n�ٷ�ȴ��֪�Լ�ֿ�����ɷ�������̰�����ɣ��������룬������������������\n��ֹ�����������ײ�������ɪ����֮�У���ʱ�����ػ���\n\n"NOR;
		message_vision(msg,this_object());
		for (i=0; i<sizeof(enemy); i++)
		{
			enemy[i]->receive_wound("sen",enemy[i]->query("max_sen")/6,this_object());
			enemy[i]->receive_damage("sen",enemy[i]->query("max_sen")/4,this_object());
			COMBAT_D->report_status(enemy[i]);
		}
		break;
	case 6:
		msg = HIB"\n�������ڽ��εͳ����������������������������ǻ���ɢ���������ܽ���������������\n�����������ľ����н�������ȴ�־�������δ��������տյ������ƺ�ȱ��ʲô����\nѪ�����泩��\n�����Ǳ���ϥ�Ϲ��٣������ŵ����ϣ��������Բ�����Ϣ��ֻ���ã����һ�죬ҡ��\n�����ʶ������Ի����䣬�����Ϲ������Ҿ���һ��Ͼ���\n\n"NOR;

		set("ting_broken",1);
		message_vision(msg,this_object());
		for (i=0; i<sizeof(enemy); i++)
			enemy[i]->perform_busy(3);
		stop_busy();
		return 1;
		break;
	}

	call_out("play_ting",count,count+1);
	perform_busy(10);
	return 0;
}

int kill_ob(object who)
{
	object me;
	int exp_r,busyst;
	::kill_ob(who);

	if (!query_temp("playing") && !query("ting_broken"))
	{
		set_temp("playing",1);
		play_ting(1);
	}
	return 1;
}

void smart_fight()
{
	int i;
	int j;
	object *enemy, who,target,me,weapon,wpx;
	string msg;
	who = this_object();
	me=this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2 && enemy[1]->is_zombie())
	{
		who->cast_spell("zombie-bolt");
		return;
	}

	target = select_opponent();
	if (me->query_temp("weapon"))
	{
	//	ccommand("say "+target->name()+" busy "+target->query_busy());
		if (target->query_busy() > 2)
		{
			if (ANNIE_D->check_buff(target,"powerup") || target->query_temp("weapon"))
			{
				map_skill("sword","zensword");
				ccommand("perform menghuankonghua "+target->query("id"));
				map_skill("sword","feixiansword");
			}
			else
			{
				delete("class");
				map_skill("sword","demosword");
				ccommand("perform zhutianjianzhen "+target->query("id"));
				set("class","baiyun");
				map_skill("sword","feixiansword");
			}

		}
		else
		ccommand("perform tianwaifeixian "+target->query("id"));
	}
	else
	{
   		me->add_temp("apply/attack", 220);
       	me->add_temp("apply/damage", 620);
		message_vision(HIR"\n$N���������¶����֮ɫ����ָ΢����צ�Σ�Ю�����Կ��з��˶��£�\n",me,target);
		target->add_temp("combat_no_report",1);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM);
		target->add_temp("combat_no_report",-1);
		if (!target->query_temp("damaged_during_attack"))
			message_vision(HIW"$n"HIW"��ʧɫ���͵ؿ���һ����$Nһ�����У������ϵ�ʱ�������׶���\n"NOR,me,target);
		else if (target->query("kee") > 0)
		{
			message_vision(HIY"$n"HIY"��ʧɫ���������ܣ�����������ನ��������ֽ�հ�ɵ����ɿ��⡣\n"NOR,me,target);
			COMBAT_D->report_status(target);
		}
		else
		{
			message_vision(HIR"ֻ����һ���Һ���$N��ָ��û��$n"HIR"ͷ­��$n"HIR"����Ѫ��Ȫӿ���鴤���£����ڵ��ϡ�\n"NOR,me,target);
			target->die();
		}
   		me->add_temp("apply/attack", -220);
       	me->add_temp("apply/damage", -620);
		perform_busy(1);
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
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	

	if (environment(me)->query("short") != "ն��̨��" || !REWARD_D->check_m_success(enemy,"��ͼһ��"))
	{
		set("reward_npc", 0);
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		::die();
		return;
	}

	message_vision(CYN"\n$N̾��������ɢ�����Ҷϣ������ǳ�������������\n$N���������۾�������������Ҫ�������׹��꣬���ܲ�����\n\n"NOR,me,enemy);
	enemy->set("annie/demon_killed_sen",1);
//	REWARD_D->riddle_done(enemy,"Ұ��",100,1); what's this ?
	::die();
	return;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

/*
��������������Ͱ������滬��ů����棬��������أ�����һ˿һ�����̻�֮����
һ�з��ǣ���������������Ʈɢ����ֻ��������ů�����µĺӱ߲ݵأ���ǰ���ӻ�����
��Ⱥݺ�ҷɣ������������ģ��᲻��һ˿��������ǿ����֮�Ķ�ʱ������ɢ��

������΢΢һЦ��ָ��һת�����������ת���ʣ���ͬ�պ�һ��ʢ�е�˿��С��������
���У���·�����һ�����Ҿ��Ļ��Ƶ���ī��������������ǳǳ��η����Ľ���ɽ
ˮ������������Զɽ���������зɹ���ֻֻ�׺ס�

��֪����֮����������һ�䣬��ø�Ϊ���䣬��Ϊ��졣���������˵�����ϸ�����
��֪���Ŀ����̸��ֻ��������ͷ¹ײ�������컷�������ǰ�������Ļ����˫��
���죬һ������������ɢ��

������Ȼֱ����£���Թ��Ľ���������ߡ�����Ӵ�ů������ʱ�ڣ���Ȼ���������ľ
Ҷҡ������졣�����ǵ������ˣ�����������ϿԳ�䣬��������ҹ����������ĸ���̣�
�����������ӵĹ�����ȴ��֪�����Ѿ������޶��ӱߵĿݹǣ�����¥ͷԹ�����ڽ̷���
�ٷ�ȴ��֪�Լ�ֿ�����ɷ�������̰�����ɡ��������룬������������������
��ֹ�����������ײ�������ɪ����֮�У���ʱ�����ؼʡ�

�������ڽ��εͳ����������������������������ǻ���ɢ���������ܽ���������������
�����������ľ����н�������ȴ�־�������δ��������տյ������ƺ�ȱ��ʲô����
Ѫ�����泩��
�����Ǳ���ϥ�Ϲ��٣������ŵ����ϣ��������Բ�����Ϣ��ֻ���ã����һ�죬ҡ��
���Ի����䣬�����Ϲ������Ҿ���һ��Ͼ���

annie 08.11.2003
*/