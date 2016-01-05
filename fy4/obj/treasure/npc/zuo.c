inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    object weapon;

		set_name("�����", ({ "zuo qinghou","boss","zuo","qinghou"}) );
		set("gender", "����" );
		set("nickname",BLU"��ī"NOR);
    	set("title","����ɽׯׯ��");
		set("class","annie");

		set("long","������Ǹ����������������ˣ�������������֣������Ժ�Ϊ����
��������ֻ֪��������������£�һ�������Ʒ�����ƥ�У�ȴû����֪��
���ıʷ�Ҳ�ǵǷ��켫��\n");

		set("spawn_location","/d/baiyun/yinxian");
        set("gender", "����" );
       
        set("gold", 20);
		set("agi", 60);
		
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 4100000);	// L90. CAP @ L75.
    
        set_skill("unarmed", 240);
        set_skill("calligraphy",240);
        set_skill("parry",200);
        set_skill("dodge",200);
        set_skill("feixian-steps",160);
        
        map_skill("dodge","feixian-steps");
        map_skill("unarmed", "calligraphy");
		
		set("max_kee",50000);
		set("max_gin",45000);
		set("max_sen",45000);
    	    
		setup();

		weapon = carry_object("/d/huashan/npc/obj/qingcong");
		weapon->set_name(YEL"�ú���"NOR, ({ "brush pen" }) );
		weapon->set("unit", "��СС��");
		weapon->set("long", "\n");
		weapon->set("weapon_wielded","��");
		weapon->wield();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(WHT"մ��ī���İ���"NOR, ({ "cloth" }) );
		weapon->set("long","մ��ī���İ���(Cloth)��");
		weapon->set("value",0);
		weapon->wear();
		
		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({		// L70-80 books
			BOOKS"class/xueyeqianzong_feline_2",	
			BOOKS"class/cloud-dance_yegui_2",
			BOOKS"class/dragonstrike_zjbl_3",
			BOOKS"class/dream-herb_huanmengluo_2",
			BOOKS"class/iceheart_buffup_3",
			BOOKS"class/kwan-yin-spells_ma_2",
			BOOKS"class/qidaoforce_juxue_2",
			BOOKS"class/xuezhan-spear_liguang_2",	
		}));
		
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/surcoat_90_6.c",
"/obj/generate/surcoat_90_18.c",
"/obj/generate/cloth3_90_6.c",
"/obj/generate/cloth1_90_16.c",
"/obj/generate/boots_90_17.c",
	}) );
	set("drop/rare_drop",({
"none",
	}) );

}


void die()
{
	object who = query_max_damage_dealer();
	object lotus;
	
	if (random(2)) {
		lotus = new(AREA_XINJIANG"obj/lotus");
		if (lotus) lotus->move(this_object());
	}

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);
	::die();
	return;
}

void smart_fight()
{
	object ob,target;
	mapping buff;
	object *enemy;
	string msg;
	int i;
	object me = this_object();

	set("atman",query("max_atman")*2);

	switch (random(4))
	{
	case 0:		
		if (!present("��",environment()))
		{
			message_vision(MAG"\n�����ʷ����ת�ۼ����ڵ�������һ�����ġ������֡�\n"NOR,me);
			target = new(__DIR__"obj/ward2");
			target->move(environment());
			target->heal_ob(me,10);
			return;
		}
		break;
	case 1:
		if (!present("��",environment()))
		{
			message_vision(RED"\n�����ʷ����ת�ۼ����ڵ�������һ�����ġ��ˡ��֡�\n"NOR,me);
			target = new(__DIR__"obj/ward3");
			target->move(environment());
			target->heal_ob(me,10);
			return;
		}
		break;
	
	}

	if (!present("��",environment()) 
		&& (query("kee") < query("max_kee") / 3 || query("gin") < query("max_gin") / 3 || query("sen") < query("max_sen") / 3))
	{
		message_vision(CYN"\n�����ʷ����ת�ۼ����ڵ�������һ�����ġ������֡�\n"NOR,me);
		target = new(__DIR__"obj/ward");
		target->move(environment());
		target->heal_ob(select_opponent(),8);
		return;
	}

	
	// CDT 10 sec 's single perform
	if (query("timer/pfm/pfm_huibi") + 10 < time()) {
		
		set("timer/pfm/pfm_huibi",time());		
		target = select_opponent();
		message_vision(WHT"\n$N��Ȼ���˴󷢣���ͷɢ���������ú���һ£����һƪ��֮ɥ����������ˮ��һ���ǳɣ�\n",me);
		add_temp("apply/attack",100);
		add_temp("apply/damage",150);
		msg=HIC"��֮���ף�\n"NOR WHT"$N����Ʈ�ݣ�����ʵ����ݺ�֮����������Ͱ���$n��ȥ��"NOR;
		COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);

		if (me->query_busy())	// parry/dodge/ob_hit busy
		{
			message_vision(HIG"$N�ж����裬�ʷ��������飬���������������ơ�\n"NOR,me,target);
			me->stop_busy();
		}

		msg=HIC"��ɥ��֮������Ĺ���ݱ������\n"NOR WHT"$N���δ󿪴��أ�һ��һ�����Ǳ��ߣ���籩�������$n��"NOR;
		COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);
	
		if (me->query_busy())	// parry/dodge/ob_hit busy
		{
			message_vision(HIG"$N�ж����裬�ʷ��������飬���������������ơ�\n"NOR,me,target);
			me->stop_busy();
		}

		msg=HIC"����׷Ω������\n"NOR WHT"$N���ⶸ�䣬���ֳٻ����أ�����ǧ��֮������$n��"NOR;
		COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);
	
		if (me->query_busy())	// parry/dodge/ob_hit busy
		{
			message_vision(HIG"$N�ж����裬�ʷ��������飬���������������ơ�\n"NOR,me,target);
			me->stop_busy();
		}

		msg=HIC"����������Ľ�ݾ���ʹ���ĸΣ�\n"NOR WHT"$w"WHT"�������ɣ�����Ҳ���أ��Ƴ��֮��������Ҳ�վ��������֮�ѣ�"NOR;
		COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);

		add_temp("apply/damage",-150);
		add_temp("apply/attack",-100);
	
	}
		
	return;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

