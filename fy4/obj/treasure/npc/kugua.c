inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    object weapon;

	set_name("��ϴ�ʦ", ({ "kugua","boss"}) );
	set("gender", "����" );
	set("nickname",BLU"������ի"NOR);
    set("title","�˹��¹Ҵ����");
	set("class","bonze");
set("long","��ϴ�ʦ�ǵ������µ�һ����������ʦ�֣�ȴ�������������Ȩ����
�����⡣����������˴�ʦ���۵ģ�����ֻ�й���ư��������Ϻ������
���ģ�Ҳ������һ��������µ���ի�˰ɡ�\n");

		set("spawn_location","/d/qianfo/zt2");
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

        set("combat_exp", 6100000);	// L125. CAP @ L95.
    
        set_skill("force", 400);
        set_skill("lotusforce",250);
        set_skill("magic", 200);
        set_skill("essencemagic",400);		//	random (700) + 700 sen damage per light_sense... 
        set_skill("unarmed", 200);
        set_skill("luohan-quan",300);	// �������ǲ�Ҫenable�����..	 // ��������enable��:p
        set_skill("dodge", 200);
        set_skill("fall-steps",200);	// �������ǲ�Ҫenable�����..	 // ��������enable��:p
		set_skill("parry",200);
		
		
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "luohan-quan");
        map_skill("force", "lotusforce");
        map_skill("magic", "essencemagic");
		
		set("max_kee",80000);
		set("max_gin",70000);
		set("max_sen",70000);
        
		setup();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(YEL"����ɮ��"NOR, ({ "cloth" }) );
		weapon->set("long","����ɮ��(Cloth)��");
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
"/obj/generate/surcoat_110_7.c",
"/obj/generate/head_110_7.c",
"/obj/generate/head_110_17.c",
"/obj/generate/cloth2_110_17.c",
"/obj/generate/boots_110_18.c",
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

int hurting()
{
	message_vision(HIY"\n$N"HIY"�����³�һ�ڳ��������ϵ����ƾ���ת�ۼ価����ʧ��\n"NOR,this_object());
	full_me();
	set("annie/ec",time());
	return 1;
}


void dist(object ghost)
{
	if (!ghost)
		return;
	message_vision(BLU"$N�ڿ��д��˸����������彥����ɢ��Ӱ������\n"NOR,ghost);
	destruct(ghost);
	return;
}

void smart_fight()
{
	object ob;
	mapping buff;
	object *enemy;
	int i;

	set("atman",query("max_atman")*2);

	// �ٻ�����
	if (!present("����",environment()) && time()>query("annie/sh")+30)
	{
		message_vision(BMAG YEL"\n�ٻ�����\n"NOR,this_object());
		message_vision(CYN"\n$N�����ȵ��������������ڣ�\n�����������¡¡��������һ������Ӧ�ٶ�����\n\n"NOR,this_object());
		ob = new("/d/qianfo/npc/tianwang"+(1+random(4)));
//		ob->delete("no_shown");
		ob->set("name","����");
		ob->set("combat_exp",5000000+random(1000000));
		"/feature/nada"->reset_npc(ob);
		ob->full_me();
		ob->move(environment());
		set("annie/sh",time());

		enemy=query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				ob->kill_ob(enemy[i]);
				enemy[i]->kill_ob(ob);
			}
		}
		ob->set("possessed",this_object());
		call_out("dist",60,ob);
	}
//	ccommand("conjure shade_sense");
	
	// �ظ�����
	if (!random(3) && time()>query("annie/ec")+ 600 && 
		(query("kee") < query("max_kee")/3
		|| query("sen")< query("max_sen")/3
		|| query("gin")< query("max_gin")/3))
	{
		message_vision(BBLU HIW"\n����˳��\n"NOR,this_object());
		message_vision(HIG"\n$N"HIG"˫�ֺ�ʮ��������ӽ������\n\n"NOR,this_object());
		perform_busy(10);
		// delay 20,��ȡ�����ʱ����ҵ�����
		call_out("hurting",20);
	}

	if (random(3))	ccommand("conjure light_sense");
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

