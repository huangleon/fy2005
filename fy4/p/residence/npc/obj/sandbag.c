#include <ansi.h>
#include <combat.h>
inherit WALL;

string heal();
void create()
{
	set_name("����Ĵ�ɳ��", ({"sandbag" }) );
	set("race","Ԫ��");
	set("long","����һ����ɳ�������������Ե����ӡ�
������������������˺�������������������������
���˻��������ã�sandbagset����ɳ���ĸ������ԡ�\n");
	set("combat_exp",2000);
//	set_skill("iron-cloth",200);
//	set_skill("steelwall",200);
	set("max_kee",100000);	// 100k,1% = 1khp
	set("max_gin",100000);
	set("max_sen",100000);
	set("practice_dummy",1);
	set_temp("cant_dodge",1);
	set_temp("cant_parry",1);
	set_temp("count",1);
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: heal() :),
    }) );
	set("item_type","t");
	set("size",1);
	set("tax",20);
	set("score_tax",1);
	setup();
}

void init()
{
 	add_action("do_look","look");
 	add_action("do_set","sandbagset");
   	add_action("do_dismantle","dismantle");
}

int do_look(string arg){
	
	string str;
	object ob;
	
	ob = this_object();
	if (!arg || arg!= "sandbag")	return 0;
	
	str = "
����һ����ɳ�������������Ե����ӡ�������������������˺�����
�����������������������˿������ã�sandbagset����ɳ���ĸ������ԡ�\n";

	str+= "���ԣ��ȼ���" + F_LEVEL->get_level(ob->query("combat_exp")) + "\n";
	
	if (ob->query_temp("apply/armor")) 
		str += "���ף�"+ob->query_temp("apply/armor")+"��\n";
	
	if (ob->query_skill("iron-cloth",1)) 
		str += "��ЧӲ����"+(ob->query_skill("iron-cloth",1)/2+1)+"��\n";
		
	if (ob->query_skill("dodge",1))
		str += "��Ч���ܣ�"+ ob->query_skill("dodge")+"��\n";
		
	if (ob->query_skill("parry",1))
		str += "��Ч�мܣ�"+ ob->query_skill("parry")+"��\n";	

	if (ob->query_skill("perception",1))
		str += "��Ч���֮����"+ ob->query_skill("perception")+"��\n";	

	if (ob->query_temp("count"))
		str += "�����غϣ�"+ob->query_temp("count")+"��\n";
	write(str);
	return 1;
}

int do_set(string arg){
	
		object ob,me = this_player();
		int armor;
		
		ob = this_object();
		if (!environment(me)->is_owner(me->query("id")))
			return notify_fail("��ɳ��������ֻ�����˲������á�\n");
		if (me->is_fighting() || me->is_busy()) {
			tell_object(me,"��������æ���ء�\n");
	   		return 1;
	   	}
	
		if (arg) {
		if (arg == "-reset") {
			ob->delete_temp("apply/armor");
			ob->delete_skill("iron-cloth");
			ob->delete_skill("dodge");
			ob->delete_skill("perception");
			ob->delete_skill("parry");
			ob->delete_skill("jin-gang");
			ob->set("combat_exp",2000);
			ob->set_temp("cant_parry",1);
			ob->set_temp("cant_dodge",1);
			ob->set_temp("cant_percept",1);
			ob->set_temp("is_unconcious",1);
			message_vision(WHT"��ɳ��˵����ԭ��ϣ��ָ�������״̬��\n"NOR, ob);
			return 1;
		}
	
		if (sscanf(arg,"-armor %d",armor)==1){
			if (armor>0 && armor <= 200) {
				ob->set_temp("apply/armor",armor);
				message_vision(WHT"��ɳ���ཽ��˼�����������Χ������һ��͸���Ļ��ף�+"+armor+"��\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"���׷�Χֻ����1-200֮�䡣\n");
				return 1;
			}
		}

		if (sscanf(arg,"-iron-cloth %d",armor)==1){
			if (armor>0 && armor <= 400) {
				ob->set_skill("iron-cloth",armor*2-2);
				ob->set_skill("jin-gang",1);
				ob->map_skill("iron-cloth","jin-gang");
				message_vision(WHT"��ɳ���ཽ��˼���������������һ����͵Ĳ�˿��+"+armor+"��\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"��ЧӲ����Χֻ����1-400֮�䡣\n");
				return 1;
			}
		}
		
		if (sscanf(arg, "-dodge %d", armor) == 1) {
			if (armor>0 && armor <= 600) {
				ob->set_skill("dodge",armor*2);
				ob->delete_temp("cant_dodge");
				ob->delete_temp("is_unconcious",1);
				message_vision(WHT"��ɳ���ཽ��˼�����������ת�����������ۻ����ң�+"+armor+"��\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"��Ч���ܷ�Χֻ����1-600֮�䡣\n");
				return 1;
			}
		}
	
	
		if (sscanf(arg, "-parry %d", armor) == 1) {
			if (armor>0 && armor <= 600) {
				ob->set_skill("parry",armor*2);
				ob->delete_temp("cant_parry");
				ob->delete_temp("is_unconcious");
				message_vision(WHT"��ɳ���ཽ��˼������������������ִ��˴ꡣ��+"+armor+"��\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"��Ч�мܷ�Χֻ����1-600֮�䡣\n");
				return 1;
			}
		}
		
		if (sscanf(arg, "-perception %d", armor) == 1) {
			if (armor>0 && armor <= 300) {
				ob->set_skill("perception",armor);
				ob->delete_temp("cant_percept");
				message_vision(WHT"��ɳ���ཽ��˼�����ͷ��ð��һ�������Ĺ⻷����+"+armor+"��\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"���֮����Χֻ����1-300֮�䡣\n");
				return 1;
			}
		}

		if (sscanf(arg, "-level %d", armor) == 1) {
			if (armor>=1 && armor <= 150) {
				
				if (ob->query("combat_exp") > F_LEVEL->level_to_exp(armor,0))
					message_vision(WHT"��ɳ���ཽ��˼�������Ȼ����ȥ�˼��֡���+"+armor+"��\n"NOR,ob);
				else
					message_vision(WHT"��ɳ���ཽ��˼�������Ȼ�����˼��֡���+"+armor+"��\n"NOR,ob);
				ob->set("combat_exp", F_LEVEL->level_to_exp(armor,0));
				ob->delete_temp("is_unconcious");
				return 1;
			} else {
				tell_object(me,"��ɳ�������ֻ����1��150֮�䡣\n");
				return 1;
			}
		}
		
		if (sscanf(arg,"-turn %d", armor) == 1) {
			if (armor>=1 && armor <=6){
				message_vision(WHT"��ɳ���ཽ��˼�������ʾ��һ������"HIR+chinese_number(armor)+NOR+WHT"��\n"NOR,ob);
				set_temp("count",armor);
				return 1;
			}
			else {
				tell_object(me,"��ɳ�������˺�������ֻ����1-6��\n");
				return 1;
			}
		}
	}
		write (WHT"����Ĵ�ɳ��˵����	2006 v.1.17"NOR"
=========================================================		
1.���ã��������ɱ�����͹���������

2.���
sandbagset -level num: ���ô�ɳ���ľ���ȼ�Ϊ��num��
sandbagset -armor num: ���ô�ɳ���Ļ���(1-200);
sandbagset -iron-cloth num: ���ô�ɳ������Ч��������1-400��
sandbagset -dodge num: ���ô�ɳ������Ч����(1-600)
sandbagset -parry num: ���ô�ɳ������Ч�м�(1-600)
sandbagset -perception num: ���ô�ɳ���Ĺ��֮����1-300��
sandbagset -turn num:	���ô�ɳ�������˺�������(1-6)
sandbagset -reset: ��ɳ���ָ���ԭʼ״̬
	
3.˵������ԭʼ״���£���ɳ�����ǻᱻ���еģ����ǵ�������
���ľ���ȼ������ܡ��м�ʱ����ɳ����������Ӧ���ӱܡ�

4.��֪���⣺���ڱ���Ʒ��ϵͳʱ�ӿ��ƣ��ڻغϼ���ʱ������
����һ�ֵĲ����������⽫��v.5.81�еõ������
=========================================================\n\n");		
		return 1;
}


string heal()
{
	int sen,gin,kee;
	
	add_temp("amount",1);
	if (query_temp("count")>query_temp("amount")){
		message_vision(CYN"��ɳ�����˻Σ��ڻ�ԭ����λ��------"HIR+"��"
			+chinese_number(query_temp("amount"))+"�У�\n"NOR,this_object());
		return "";
	}
	delete_temp("annie/damaged_by_mingyue");
	set_temp("amount",0);
	kee = 100000 - query("kee");
	gin = 100000 - query("gin");
	sen = 100000 - query("sen");
	message_vision(CYN"����ĵĴ�ɳ�����˻Σ��ڻ�ԭ����λ��------"HIR+CYN"���һ�У�\n"NOR,this_object());
	message_vision(CYN+name()+"�ཱུ�˵����������"+gin+"�㣬��Ѫ����"+kee+"�㣬��������"+sen+"�㡣������ԭ��ϣ�\n"NOR,this_object());
	remove_all_killer();
	remove_all_enemy();
	this_object()->full_me();
}


int reset_item_list(object dest);

int do_dismantle(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	object *inv;
	object box,item;
	mapping item_list;
	string *lists,mitem;
	int i,idx;
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	if (!env)
		return notify_fail("����#13106��\n");	// ��֪����ʲô��˼...ppl report��ʱ��search index
	if (!env->is_owner(me->query("id")))
		return notify_fail("��ͥ��Ʒֻ�������ӵ����˲����\n");
	if (!present("dismantle statue",me))
		return notify_fail("��û�к��ʵĹ����Խ��в����\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("����#13108��\n");	// ��֪����ʲô��˼...ppl report��ʱ��search index
	message_vision(CYN"$Nһ�������������ʯ����"+name()+"����ȥ�������¾Ͱ�"+name()+"�ҵ�ϡ�á�\n\n"NOR,me);
//	env->add("item_index",-1);	
	inv = all_inventory(ob);
	while (sizeof(inv))
	{
		inv = all_inventory(ob);
		destruct(inv[0]);
	}
	ob->reset_item_list(ob);

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = env->query("item_list/"+lists[i]);
		if (mitem == base_name(ob))
			env->delete("item_list/"+lists[i]);
	}
	env->add("item/"+query("item_type"),-1);
	env->add("free_space",query("size"));

	env->add("tax",-query("tax")*7);
	env->add("score_tax",-query("score_tax")*100);

	if (env->query("tax")<0)
		env->set("tax",0);	// ��bug
	if (env->query("score_tax")<0)
		env->set("score_tax",0);	// ��bug

	env->save();
	destruct(present("dismantle statue",me));
	destruct(ob);
	return 1;	
}


varargs int receive_damage(string type, int damage, object who)
{
    	int val, fate, amount;
    	int reduction,r_damage, h_damage;

    	
//  if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
    	if (damage <0) damage =0;
    	if( type!="gin" && type!="kee" && type!="sen" )
        	error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n");

		if ((query_temp("buffup/backfire") == type || query_temp("buffup/backfire") == "all") && who && !query_temp("annie/backfire_damage"))
		{
			who->set_temp("annie/backfire_damage",1);
			set_temp("annie/backfire_msg",1);
			who->receive_damage(type,damage * query_temp("buffup/backfire_amount")/ 100,this_object());
			who->delete_temp("annie/backfire_damage");
			message_vision(query_temp("buffup/backfire_msg"),this_object(),who);
		}
		// annie 07.24.2003

    	if (query("resistance/"+type) || query_temp("resistance/"+type)){
			reduction=query("resistance/"+type) + query_temp("resistance/"+type);
			if (reduction >= 100)	reduction = 100;
			damage = damage - damage * reduction / 100;
		}

    	if( objectp(who) ) set_temp("last_damage_from", who);
    	val = (int)query(type) - damage;
	
//	�����������¼NPC��HATE_LIST��	
	if (objectp(who))
	if (!userp(this_object())) {
		h_damage = damage;
		add_hate(who, h_damage);
	}

    // here add for the usage of lifesave potion
    	if ( val < query("max_"+type)/5 && val>0 && is_fighting())
    	if( (time()- query("timer/lifesave"))< 3600 )//���һ��Сʱ
    	{
       		fate = 20 + query("pfm/chunquye_pw");
	    	if( fate + 100 > random(100))
	    	{
			message_vision(RED"\n$N"NOR+RED"ǿ��һ�����������Ϸ���һ˿��⣬���ƾ�Ȼ���˴�롣\n\n"NOR,
					this_object());
				amount = 4000 + F_ABILITY->check_ability(this_object(),"chunquye_amt")* 300;
				receive_fulling("gin", amount);
				receive_fulling("sen", amount);
				receive_fulling("kee", amount);
	       	    	status_msg("all");   	
	        	delete("timer/lifesave");
	        	tell_object(this_object(),WHT"���仨��ˮ��ȥҲ�������������Ե���ء�\n"NOR);
			return (damage> amount)? (damage- amount): 0 ;
		}
	}
	
	set(type, val);
    	
    	status_msg(type);
    	if (objectp(who))	dmg_msg(type, who);
    	    	
    	set_heart_beat(1);

	if(query_temp("mesmerize")) {		// testing 4.1 new pfm: mesmerize.
		this_object()->stop_busy();
		delete_temp("mesmerize");
		delete_temp("condition_type");
		tell_object(this_object(), YEL"������һʹ�������Ժ����������˹�����\n"NOR);
	}
	if (who)
		ANNIE_D->debuff(this_object(),"manatwist");

    	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
    	int val,reduction, fate;
	int r_damage, h_damage, amount;

//  if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
    	if (damage <0) damage =0;
    	if( type!="gin" && type!="kee" && type!="sen" )
        	error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n");

		if ((query_temp("buffup/backfire") == type || query_temp("buffup/backfire") == "all") && who && !query_temp("annie/backfire_damage"))
		{
			who->set_temp("annie/backfire_damage",1);
			who->receive_wound(type,damage * query_temp("buffup/backfire_amount")/ 100,this_object());
			who->delete_temp("annie/backfire_damage");
			if (!query_temp("annie/backfire_msg"))
				message_vision(query_temp("buffup/backfire_msg"),this_object(),who);
			else
				delete_temp("annie/backfire_msg");
		}

		if (query("resistance/"+type) || query_temp("resistance/"+type)){
			reduction=query("resistance/"+type) + query_temp("resistance/"+type);
			if (reduction >= 100)	reduction = 100;
			damage=damage - damage * reduction / 100;
		}

    	if( objectp(who) ) set_temp("last_damage_from", who);
    	val = (int)query("eff_" + type) - damage;
    
        // here add for the usage of lifesave potion
    	if ( val < query("max_"+type)/5 && val > 0 && is_fighting())
    	if( (time()- query("timer/lifesave"))< 3600 )//���һ��Сʱ
    	{
       		fate = 20 + query("pfm/chunquye_pw");
	    	if( fate + 100 > random(100))
	    	{
				message_vision(RED"\n$N"NOR+RED"ǿ��һ�����������Ϸ���һ˿��⣬���ƾ�Ȼ���˴�롣\n\n"NOR,
						this_object());
				amount = 4000 + F_ABILITY->check_ability(this_object(),"chunquye_amt")* 300;
				receive_fulling("gin", amount);
				receive_fulling("sen", amount);
				receive_fulling("kee", amount);
		       	status_msg("all");   	
		        delete("timer/lifesave");
		        tell_object(this_object(),WHT"���仨��ˮ��ȥҲ�������������Ե���ء�\n"NOR);
				return (damage> amount)? (damage- amount): 0 ;
			}
		}
        
        //  �����������¼NPC��HATE_LIST��	
	if (objectp(who))
	if (!userp(this_object())) {
		h_damage = damage;
		add_hate(who, h_damage);
	}
        
    	set("eff_" + type, val);
    	if( (int)query(type) > val ) set(type, val);
    	
    	status_msg(type);
    	if (objectp(who))	dmg_msg(type, who);
    	
    	set_heart_beat(1);

	if(query_temp("mesmerize")) {		// testing 4.1 new pfm: mesmerize.
		this_object()->stop_busy();
		delete_temp("mesmerize");
		delete_temp("condition_type");
		tell_object(this_object(), YEL"������һʹ�������Ժ����������˹�����\n"NOR);
	}
	if (who)
		ANNIE_D->debuff(this_object(),"manatwist");
	
    	return damage;
}


void die(){
	
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

