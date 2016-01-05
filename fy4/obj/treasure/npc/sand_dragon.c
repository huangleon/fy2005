#include <ansi.h>
inherit SMART_NPC;

int dragon_attack();
int dragonstun();
int dragonclaw();
int dragonbreath ();
int dragonblow ();

void create()
{
	set_name("ɳ������", ({ "hibernating dragon", "boss","dragon" }) );
	set("race", "��");
	set("gender", "����");
	set("long", "�Ȿ��һ���ں�����������������Ϊ�׺�ɣ��ı�Ǩ��ԭ���ĺ������
��ɳĮ�����������ݷ�������Ҳ��֪���м�ǧ�������ˡ� \n");
	
	set("combat_exp", 15000000);
	
	set("age",10000000);
	set("no_curse",1);
	set("boss",1);
	
	set("agi", 20);
	
	set("max_kee", 300000);
	set("max_gin", 300000);
	set("max_sen", 300000);
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			10:	(: dragon_attack() :),
        ]) );    	
    	
    	set("chat_chance_combat", 20);
    	set("chat_msg_combat", ({
        	(: dragonclaw()	:),
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );  

	set_temp("apply/attack", 800);
	set_temp("apply/armor",  100);
	set_temp("apply/dodge",  600);
	set_temp("apply/damage", 50);
	set("spawn_location","/d/quicksand/shaxue");
	setup();
}


int dragon_attack(){
	if (random(2) && query("is_stunning")+ 4 < time()) 
		dragonstun();
	else if (time()>query("dragon/breath")+12) 
		dragonbreath();
	return 1;
}


int dragonbreath ()	{
	message_vision(HIR"\n\n$N���Ϻ�Ȼ���������ĺ�⣬ת˲�䣬��âԽ��Խǿ�ҡ�����\n\n"NOR,
			this_object());
	call_out("hurting",10);
	set("dragon/breath",time());
	return 1;
}

int hurting()	{
	int i,dam;
	object *inv;
	message_vision(HIR"\n\n$Nһ���죬����������ӭ���������������޿��������޿ɱܡ�\n\n"NOR,this_object());
	inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
		if( living(inv[i]))
		if( inv[i]!= this_object()){
			dam = 3000 + random(2000);
			inv[i]->receive_wound("kee",dam,this_object());
			COMBAT_D->report_status(inv[i]);
        	}
	return 1;
}


int dragonblow()	{
}


int dragonstun()	{
	int i,dam;
	object *inv;
	message_vision(HIW"\n\n$N��ֱ������������Ծ�£���ҡ�ض���ɳѨ�����������\n\n"NOR,this_object());
	inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
		if( living(inv[i]))
		if( inv[i]!= this_object()){
			if (random(this_object()->query("combat_exp"))*5<inv[i]->query("combat_exp"))
				continue;
			inv[i]->perform_busy(2);
			message_vision(YEL"$Nֻ���ĵ����ѣ�Ŀ�ɿڴ����������á�\n"NOR,inv[i]);
        	}
	set("is_stunning",time());
	return 1;
}


int dragonclaw()	{
	object ob,me,*enemy;
	int i;
	
	ob=this_object();
	ob->set("bite_time",time());
	enemy=ob->query_enemy();
	me=enemy[random(sizeof(enemy))];
	message_vision(HIG"\n$N���������ǰצ��Ю����֮�ƣ�Ѹ������$n��ͷ��һץ��\n"NOR,ob,me);
	me->receive_wound("kee",1000+random(1000),ob);
	COMBAT_D->report_status(me);
	return 1;
}


void die()
{
	object rstone, me,owner,money_reward,skin;
	mapping hate;
	object *ppl, *ppl_present;
	int i;
	
	if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
	environment(this_object())->set("dragon_death",time());
	
	// The purpose is, everyone present who contributed hate can get mark
	// the stone ... one at time, give whoever you want :D
	if(objectp(me)) { 
		CHANNEL_D->do_sys_channel("info","һ���µ������񻰵ĵ�����������");
		CHANNEL_D->do_sys_channel("info",sprintf("%s��%s��%s%s%s��", NATURE_D->game_time(),
				me->query("name"), environment(this_object())->query("short"),"նɱ", name())); 
	    
	    hate = query_hate_list();
	    if (sizeof(hate))
	    	ppl = keys(hate);
	    if (sizeof(ppl)) {	    
       		ppl_present=filter_array(ppl,(:objectp($1) && userp($1) && environment($1)==environment():));
	    }
	    if (sizeof(ppl_present)) 
	    for (i=0;i<sizeof(ppl_present);i++) 	
	        REWARD_D->riddle_done(ppl_present[i], "�����൤", 200, 1);
		
		rstone = new("/obj/specials/stone/rstone");
		if (objectp(rstone)) {
			message_vision(HIR"\nһ�����ɳ������˫Ŀ�����¸պõ���$n���С�\n"NOR, this_object(), me);
			if (!rstone->move(me))
				rstone->move(environment(me));
//			me->set("stone_mark/rstone", 1);
//			rstone->set("stone_owner", me);
			log_file("riddle/IMBUE_LOG",
			sprintf("%s(%s) �ҿ� ɳ������ �õ������൤ %s \n",
				me->name(1), geteuid(me), ctime(time()) ));			
		}
	} 
	environment(this_object())->tell_exit();	
	::die();
}

