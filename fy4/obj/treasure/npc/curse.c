inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();
	
void create()	
{
    object weapon;

	set_name("��ڤ", ({ "pei ming","boss","pei","ming"}) );
	set("title",HIB"ͨ��"NOR);
	set("nickname",BLU"���������γɿ�"NOR);
	set("gender", "����" );
	set("class","yinshi");
	set("age",60);
	set("long","��ڤͨ�������Ƕ�ʮ��ǰ������������컢�����������ἰɫ��ĸ���֮
һ��Ȼ�����´��ˣ�������Ѿ����ˣ��ϵ��ٿ�����һ������ʱ��Ӱ�ӣ�
�������ƽ�������Ĵ�ĺ���ˣ���\n");

		set("spawn_location","/d/manglin/hole");

		set("cps",50);
		set("agi",62);
		
		set("gold",15);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.
        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 2350000);	// L55.capped at 45
    
        set_skill("celecurse", 150);
        set_skill("cursism",200);	
		set_skill("qiankunwuxing",200);
		set_skill("dodge",200);
		set_skill("iceheart",200);
		set_skill("force",200);
		set_skill("unarmed",200);
		set_skill("doomstrike",200);
		set_skill("doomsteps",200);
		set_skill("doomforce",200);
		
		map_skill("force","doomforce");		// don't enable iceheart, use NPC inherent hit
		map_skill("cursism","celecurse");
		map_skill("unarmed","doomstrike");
		map_skill("dodge","doomsteps");
		
		set("max_kee",20000);
		set("max_gin",16000);
		set("max_sen",16000);
        
		setup();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set("armor_prop/armor",80);
		weapon->wear();
			
		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({
			BOOKS"class/dragonstrike_zjbl_2",	
			BOOKS"class/gouyee_heal_2",	
		}));
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",2);
	set("drop/common_drop",({
"/obj/generate/surcoat_55_4.c",
"/obj/generate/surcoat_55_16.c",
"/obj/generate/neck_55_4.c",
"/obj/generate/head_55_4.c",
"/obj/generate/head_55_14.c",
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


void dist(object ghost)
{
	if (!ghost)
		return;
	set_temp("timer/solidghost",0);
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
	object ghost;
	object me = this_object();

	set("atman",query("max_atman")*2);

	// 1/3����Ѫ�ģ�Normal ��ʱ���������
	if (query("kee")< query("max_kee")) {		
		if (!query_temp("timer/solidghost") && time()>query("annie/sh")+30)
		{
			set_temp("timer/solidghost",1);
			message_vision(HIB"\nһ������ͻȻ��Զ��Ʈ�˹�������$N����������ë���Ȼ��Ц���������ˣ���ʲô�Ը���������\n"NOR,this_object());
			ghost=new("/obj/npc/solidghost");
			ghost->invocation(me,200);
			ghost->set("name","��������");
			set("my_pet", ghost);			
			ghost->move(environment());
			set("annie/sh",time());
			ob = ghost;
			enemy=query_enemy();
			i = sizeof(enemy);
			while(i--) {
				if( enemy[i] && living(enemy[i]) ) {
					ob->kill_ob(enemy[i]);
					enemy[i]->kill_ob(ob);
				}
			}
			call_out("dist",180,ob);
				
		}
	}
	
	if (objectp(ob=query("my_pet"))) {		
		
		if (query("kee")< query("max_kee")/3 )
		{ 
			if (!ob->query_temp("pfm/qiankun/heal_curse"))
			{	
				"/daemon/class/yinshi/qiankunwuxing/heal.c"->conjure(me,ob);
				ob->set_skill("cursism",200);	
				ob->set_skill("celecurse",200);
				ob->stop_busy();
			}
		} else if (query("kee")< query("max_kee"))
		{	
			if (!ob->query_temp("pfm/qiankun/turn_curse"))
			{
				"/daemon/class/yinshi/qiankunwuxing/boost.c"->conjure(me,ob);
				ob->set_skill("cursism",200);	
				ob->set_skill("celecurse",200);
				ob->stop_busy();
			} 
		}		
	}
	
	if (!ANNIE_D->check_buff(me,"boostcurse"))
		ccommand("curse boostcurse");

	stop_busy();
	return;
}

mixed hit_ob(object me,object victim, int damage_bonus)
{
	int extra, damage, rate;
	object weapon, *enemy;
	string msg;

    extra=  400;
    extra = COMBAT_D->magic_modifier(me, victim,"kee", extra);            
	victim->receive_wound("kee",extra, me);
	msg= RED"$N���еĺ���Ȼ���ӳ�������û��Ϣ���䵽$n���ϡ�\n"NOR;
	
	return msg;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

