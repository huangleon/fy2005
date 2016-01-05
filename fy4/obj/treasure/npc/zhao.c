inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    	object weapon;

		set_name("�Է���", ({ "zhao feiliu","boss","zhao"}) );
		set("gender", "����" );
		set("nickname",BLU"����ɡ"NOR);
    	set("title","Ѫ����");
		set("class","legend");
		set("age",77);
		set("spawn_location","/d/cyan/peakx");

		set("long","һ�����°׷������ˣ�һ���˶�����ɽ���䣬������ű���ֽɡ����Ǵ�
��˿���ض����ܵ�΢Ц�����������ܲ���ϸ��׷ף��ε������������ϵ�
��ֽɡ�ϡ�\n");

        set("gender", "����" );
    	set("agi",70);
    	set("gold",30);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 7100000);	// L110
    	set_temp("apply/armor",80);
    	
        set_skill("force", 400);
        set_skill("divineforce",250);
        set_skill("dodge", 400);
        set_skill("fall-steps",250);
        set_skill("unarmed", 400);
        set_skill("luohan-quan",220);
        set_skill("parry", 200);	

        map_skill("force", "divineforce");
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "luohan-quan");	// ������������ľ�����..
		
		set("max_kee",90000);
		set("max_gin",70000);
		set("max_sen",70000);
        
		setup();

		weapon=carry_object("/obj/weapon/sword");
		weapon->set_name(YEL"��ֽɡ"NOR, ({ "umbrella" }) );
		weapon->set("long","��ֽɡ(Umbrella)��");
		weapon->set("value",0);
		weapon->wield();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(CYN"Ѫ������"NOR, ({ "cloth" }) );
		weapon->set("long","Ѫ������(Cloth)��");
		weapon->set("value",0);
		weapon->wear();
		
		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({		// L80-90 books
			BOOKS"class/cloud-dance_yegui_2",
			BOOKS"class/dragonstrike_zjbl_3",
			BOOKS"class/iceheart_buffup_3",
			BOOKS"class/xueyeqianzong_wolverine_3",
			BOOKS"class/nine-moon-claw_weiwoduzun_2",
			BOOKS"class/yijinjing_shield_2",
			BOOKS"class/yue-spear_juechufengsheng_2",
		}));
		
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/wrists_110_6.c",
"/obj/generate/surcoat_110_19.c",
"/obj/generate/neck_110_7.c",
"/obj/generate/neck_110_17.c",
"/obj/generate/cloth2_110_7.c",
"/obj/generate/boots_110_8.c",
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
	object ob;
	mapping buff;
	object target,*enemy;
	int f,i;
	
	enemy=query_enemy();
	
	if (!random(3))
	{
		for (i=0;i<sizeof(enemy);i++) {
			if (objectp(ob = enemy[i])) {
				if (ANNIE_D->check_buff(ob,"lowresist"))	continue;
				message_vision(BCYN WHT"\n��������\n"NOR,this_object());
				message_vision(HIB"\n�Է�����ɡͻȻһ�գ�����ĺ��ƾ��𣬺�Ȼ��һ��������"NOR,this_object());	
				message_vision(HIB"�������Ʋ���£��������������ʡ�\n"NOR,this_object());
				buff =
					([
						"caster":this_object(),
						"who":ob,
						"name":"��ħ���ࡤ��������",
						"type": "lowresist",
						"att": "curse",
						"buff1":"resistance/kee",
						"buff1_c":-20,
						"time":60,
						"buff_msg":HIB"$N"HIB"��ͷ������ǰһ��ѣ�Ρ�\n"NOR,
					]);
				ANNIE_D->buffup(buff);
				break;
			}
		}	
	}
		
	if (!random(3))
	{
		for (i=0;i<sizeof(enemy);i++) {
			if (objectp(ob = enemy[i])) {
				if (ANNIE_D->check_buff(ob,"cursedflesh"))	continue;
				message_vision(BBLU HIW"\n�ջ���Ѫ\n"NOR,this_object());
				buff =
				([
					"caster":this_object(),
					"who":	ob,
					"type": "cursedflesh",
					"att":  "curse",
					"name": "��а�ľ����ջ���Ѫ",
					"time": 30,
					"buff_msg":HIC"\n$n"HIC"���ϸ��ֳ�����֮ɫ�����һ���ȳ���������
"HIB"$N"HIB"⧲�����������һ�ڶ�����ʱҡҡ��׹������\n\n"NOR,
				]);
				ANNIE_D->buffup(buff);
				break;
			}
		}	
	}

	target = select_opponent();
	add_temp("apply/attack",250);
	add_temp("apply/damage",400);
	message_vision(BRED WHT"\n�˺۴���\n"NOR,this_object());
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,HIB"�Դ�������ɡһ�ţ���Ӱ������Ȱ�����$n����ָ��$n����ץȥ��"NOR,"ץ�ˣ�
"HIR"$n�ı��ϱ�ץ����Ѫ���죮����"NOR);
	add_temp("apply/damage",-400);
	add_temp("apply/attack",-250);
	
	if (target->query_temp("damaged_during_attack"))
	{
		if (!ANNIE_D->check_buff(target,"armorup"))
		{
				buff =
				([
					"caster":this_object(),
					"who":target,
					"name":"��ħ���ࡤ�˺۴���",
					"type": "armorup",
					"att": "curse",
					"buff1":"apply/armor",
					"buff1_c": -100,
					"time":	  60,
					"buff_msg":" "NOR,
				]);
				ANNIE_D->buffup(buff);
		}
	}

	return;
}


mapping ob_hit(object attacker, object victim,int damage)
{
	mapping data = ([]);
	object thr;
	if (!thr = attacker->query_temp("weapon"))
		return 0;
	if (thr->query("skill_type") != "throwing")
		return 0;
	data["msg"] = CYN"�Է����������ֽɡ�糵����ת������ͻȻ���ѻ���һ����Ȧ��\nֻ������������һ�������죬"+thr->name()+CYN"����һ˲�䱻��ɡ�\n"NOR;
	data["damage"] = -damage;
	return data;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

