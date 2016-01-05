// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
int leave();
int damo();
int be_guard();
int guardd();
int failit();
int dont();
int dontt();
int take_challenge(object me);
void no_answer(object me);
void create()
{
    	set_name("�ĺ�", ({ "master hu", "master"}) );
    	set("vendetta_mark","shaolin");
    	set("gender", "����" );
    	
    	set("age", 84);
    	set("per", 35);
    	set("cps", 80);
    	
    	set("attitude","friendly");
    
    	set("long",
        	"���������������ˣ��������ֳ������飬����ϲŭ�޳����������ؾ���"
        	"�ĵ���������֡�\n");
    
    	create_family("������", 17, "����");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"ɳ��","ɮ��","�޺�","���","����","��ɮ","��ʦ",
		"����","���ó���","����Ժ����","��������","����Ժ����",
		YEL"����Ժ����"NOR,YEL"������"NOR,YEL"���ڴ���"NOR,HIY"��������"NOR}));
		   
    	set("combat_exp", 5000000);
    	set("no_arrest", 1);
    	set("class","shaolin");
    
    	set("inquiry", ([
    		"���鱻��" : (: guardd :),
    		"�׽" : (: damo :),
    		"yijinjing" : (: damo :),
    		"��Ħ" : (: damo :),
    		"damo" : (: damo :),
    		"����" : (: damo :), 
        	"�ؾ�¥": (: be_guard :),
        	"����¥": (: be_guard :),
        	"����¥ʧ��": (: failit :),
        	"�ؾ�¥ʧ��": (: failit :),
        	"ʧ��": (: failit :),
        	"����": (: dont :),
        	"��": (: dontt :),
        	"�ݰ�": (: dontt :),
        	"�ݣ������ݣ�����": (: dontt :),
        	"�ݣ�����": (: dontt :),
         	"leave" : (: leave :),
    	]));
        
        set_skill("chanting", 160);
		set_skill("move", 160);
		set_skill("dodge", 160);
		set_skill("force", 180);
		set_skill("unarmed", 180);
		set_skill("parry",160);
	
		set_skill("perception",100);
		set_skill("foreknowledge",100);
		set_skill("literate", 100);
	
		set_skill("zen", 160);
		set_skill("xiaochengforce",150);
	    set_skill("iron-cloth",100);
	    set_skill("yijinjing",90);     
		set_skill("puti-steps",150);
		set_skill("yizhichan",150);
		set_skill("dabei-strike",150);
		set_skill("duanhun-spear",150);
		set_skill("fumostaff",150);
		set_skill("liuxing-hammer",150);
		set_skill("wuche-axe",150);
		set_skill("lianxin-blade",150);
		
		set_skill("blade", 200);
		set_skill("hammer",200);
		set_skill("staff",200);
		set_skill("spear",200);
		set_skill("axe",200);
	    map_skill("iron-cloth","yijinjing");	
    	map_skill("unarmed","yizhichan");			
		map_skill("blade","lianxin-blade");
		map_skill("hammer","liuxing-hammer");
		map_skill("staff","fumostaff");
		map_skill("spear","duanhun-spear");
		map_skill("force","xiaochengforce");
		map_skill("dodge","puti-steps");
		map_skill("axe","wuche-axe");

    	setup();
    	carry_object(__DIR__"obj/monk_cloth")->wear();
}

int dontt()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"����֮��") != 11)  
	{
		ccommand("yawn "+me->query("id"));
		return 1;
	}
	ccommand("hmm");
	ccommand("say �ݰݣ���������");
	ccommand("say ������˵����֮�£�һ�ְ��Ż��ǣ�����ʲô�˵������أ�");
	REWARD_D->riddle_set(me,"����֮��",12);
	return 1;
}

int dont()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"����֮��") != 4 || !REWARD_D->check_m_success(me,"�ؾ�¥"))  
	{
		ccommand("tidu "+me->query("id"));
		return 1;
	}
	ccommand("spank "+me->query("id"));
	ccommand("hmm");
	ccommand("say ����ίʵ���ɣ�������ʦ�ܱ��Ϳ��ڲؾ�����ȥ���ɣ�Ϊ��"YEL"����"CYN"��");
	ccommand("say ��ʩ���������ϱ�����ʦ�����ʹ��ɡ�");
	REWARD_D->riddle_set(me,"����֮��",5);

	return 1;
}

int failit()
{
	object me;
	int combat_exp,combat_exp_lost;
	mapping combat_level;
	
	int num, current_apply;
	string *attr1= ({ "strength","composure","agility", "intelligence","karma", "constitution" });
	string *attr2= ({ "str", "cps", "agi", "int", "kar", "con" });
	string *attr3= ({ "����", "����", "�ٶ�", "����", "����", "����" });
	
	
	me = this_player();
	if (REWARD_D->riddle_check(me,"����֮��") != 3) 
	{
		ccommand("dapp "+me->query("id"));
		return 1;
	}
	if (!REWARD_D->riddle_check(me,"�ؾ�¥") || REWARD_D->check_m_success(me,"�ؾ�¥")) 
	{
		ccommand("dapp "+me->query("id"));
		return 1;
	}
	ccommand("sigh");
	no_answer(me);
	ccommand("emote ����ȥһ˲��Ͳ�������ʮ�꣮����");
	set("age",144);	// snicker annie

	
	combat_exp = me->query("combat_exp");
	combat_level = F_LEVEL->exp_to_level(combat_exp);
/*	combat_exp_lost = combat_level["next_level"]/20;

	if (((F_LEVEL->exp_to_level(combat_exp-combat_exp_lost))["level"]) < combat_level["level"])
	// �����ˡ�
	tell_object(me,HIR"\n���ˣ���ĵȼ������ˣ�\n"NOR);
	me->add("combat_exp", - combat_exp_lost);	*/
	
		
	CHANNEL_D->do_sys_channel(
		"info",sprintf("%s�����־�¥�ٶ�ʧ�ԣ�%s��������ʮ��Ԫ�����ˡ�", NATURE_D->game_time(),
			me->name(1)));
	
	// ��Ϊ������ʧ		
			num = random(6);			
			if (combat_level["level"] >= 10) {
				current_apply = me->query("attr_apply/"+attr1[num]);
				if (me->query(attr2[num]) + current_apply>10){
					tell_object (me, WHT"\n		���" + attr3[num] + "�ܵ����˽����ˡ�\n\n\n"NOR);
					me->add("attr_apply/"+attr1[num],-5);
				}
			}	
			
	me->unconcious();		
	
	me->add("annie/failed_�ؾ�¥",1);
	me->add("annie/failed_�ؾ�¥_exp",combat_exp_lost);
	REWARD_D->riddle_clear(me,"�ؾ�¥");
	return 1;
}

int guardd()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"����֮��") != 1) 
	{
		message_vision("$N��ü��������֪���£�Ī�������ǵ���������ǣ����\n",this_object());	
		return 1;
	}
	ccommand("sigh");
	message_vision("$N̾��������һ���ٶ���˭����ȥ"YEL"�ؾ�¥"NOR"��\n",this_object());	
	REWARD_D->riddle_set(me,"����֮��",2);
	return 1;
}

int be_guard(){
	object me;
	int num;
	me = this_player();
	if ( num = me->query("vendetta/shaolin")){
		message_vision("$N�ݺݵص���$nһ�ۣ�ɱ�������ӵ�" + chinese_number(num) 
			+ "�ˣ�������ƭ���־��飿\n", this_object(),me);
		return 1;
	}
	if (REWARD_D->riddle_check(me,"����֮��") != 2 && REWARD_D->riddle_check(me,"����֮��") != 3)  
	{
		message_vision("$Nҡͷ�������������޹ء�\n",this_object());	
		return 1;
	}

	message_vision("$N����������Э�����²���ؾ�¥ʧ�Ե��ɰ���....��....�㲻�������¶����𣿡���answer��\n",this_object());	
	add_action("do_answer", "answer");
	REWARD_D->riddle_set(me,"����֮��",3);
	return 1;
}

int damo(){
	object me;
	int explvl, budlvl;
	me = this_player();
	explvl = me->query("combat_exp");
	budlvl = me->query_skill("zen",1);

	if(this_object()->is_fighting()){
		return notify_fail("�ĺ��ƺ�����æ��\n");
	}
		
	if(me->query("marks/�������")
		|| REWARD_D->check_m_success(me,"�������")){
		message_vision("$N��Ū�����еķ���,����ӽ������ �������ң���Եҵ��ת���������ܣ��Դ�Ե������\n",
				this_object()); 
				
		return 1;
	}
	message_vision("$N΢΢һ��ü˵�����׽������������һ��ֻ����Ե֮�ˡ�����\n", this_object()); 
	if(me->query("class") != "shaolin") {
		message_vision("$NЦ������ȷ������֣����ǲ�Ҫ�����ˡ�\n", this_object());
		return 1;
	} else if(explvl > 2400000 && budlvl >= 160){
		message_vision(YEL"\n$N���˿�$n������İ���һ����"NOR, this_object(), me);
		message_vision(YEL"��̾һ����ԭ����ˣ����գ����ա�\n"NOR, this_object());
		message_vision(YEL"$N����$n˵����Ҫѧ�׽��Ϊʦ����Ҫ��������ѧ�ϵ���Ϊ���ɷ�\n"NOR, 
				this_object(), me);
		message_vision(YEL"���������������󣯣�\n"NOR, this_object());  
		add_action("do_accept", "accept");
		me->set_temp("marks/���ĺ�", 1);
		call_out("no_answer", 60, me);	
	} else {
		message_vision("$N���˿�$n��ͽ����������δ��������ǿ�󡣡���", this_object(), me); 
		tell_object(me, "����160��������\n");
	}	
	return 1;
}


int do_accept(string arg) {
	object me;
	
	me = this_player();
	if(!arg || (arg != "yes" && arg != "no")){
		return 0;
	}
	if(me->is_fighting()){
		return notify_fail("������æ��\n");
	}
	if(!me->query_temp("marks/���ĺ�")){
		return 0;
	}
	if(this_object()->is_fighting() || this_object()->is_busy()){
		command("say ��������æ���Ȼ�ɡ�����");
		return 1;
	}
	if(arg == "no"){
		remove_call_out("no_answer");
		message_vision("$N���˵�ͷ���������ۣ��૵�������ʧ��Ե������������ϲ�粻����ڤ˳�ڵ�������\n",
			this_object());
	} else if(arg == "yes"){
		remove_call_out("no_answer");
		message_vision("$N�������аɡ�����������\n", this_object());
		me->set("marks/challenge_xinhu", 1);
	}
	me->delete_temp("marks/���ĺ�"); 
	return 1;
}


int accept_fight(object me){
	if (me->query("class")!= "shaolin")
		return 0;
		
	if(this_object()->is_fighting()){
		command("say ��������æ���Ȼ�ɡ�����");
	} else if(!me->query("marks/challenge_xinhu")) {
		message_vision("$N�������ۣ��૵�������ʧ��Ե������������ϲ�粻����ڤ˳�ڵ�������\n", this_object());
		return 0;
	} else if (me->query("marks/�������") == 1) {
		message_vision(YEL"$N�������������þ������������ģ������ľ���������������������\n"NOR,
				this_object());
	} else if (me->query("marks/�������") == 2) {	
		message_vision(YEL"$N���ͷ˵�����գ����ա�����������\n"NOR, this_object()); 
		message_vision(YEL"$N�����ȵ���δ����δ����ĪԸĪ��δ�����Ծ���������δ���¡������ܽ��\n"NOR, 
				this_object());
	} else if (me->query("marks/�������") == 3) {	
		message_vision(YEL"$N˫�ֺ�ʮ��΢Ц������ϲ����ϲ��������Ӧ֤�˴����\n"NOR, this_object());
		message_vision(YEL"$N˫�ֺ�ʮ������л������лʦ��ָ���Խ�\n"NOR, me); 
		message_vision("\n$N�ʵ���ֻ���֮�뷨��Ϊ�Ƿ����ȣ�Ϊ�Ƿ����ȣ��������ȣ����Ǻη���˵��\n",
				this_object());
		message_vision("���Ƿ����ȣ��кν̶��ɵ���\n", this_object()); 
		message_vision("$N�����ش𣺷����ڷ��ȣ����ڷ���\n", me); 
		message_vision("\n$N���ʵ�����η��Ⱥ�\n", me); 
		message_vision("$N��ȻԻ��һ����𣬽�����𷨶��óɷ𣬼��Ƿ��ȷ��Ȼʼ��˵ʮ��������\n",
				me);
		message_vision("���������������з𷨽̣����еóɷ𣬼��Ƿ��ȷ���Ҳ��\n", me); 
		message_vision("$N��$n��Ի��ĵ�һЦ��\n", me, this_object());
		message_vision(HIY"\n$N˵����ҪѰ�ҵĶ������Ѿ�ָ�������ˣ��㻹����ȥ��\n"NOR, this_object());
		me->delete("marks/�������");
		me->delete("marks/challenge_xinhu");
		REWARD_D->riddle_done(me,"�������", 50, 1);
//		me->set("marks/����_��ڳɹ�", 1);
		return 0;
	}
	message_vision("\n$N���������С���������\n", this_object());
	return 1;
}

void win_enemy(object obj){
	message_vision("$Nҡ��ҡͷ�����������������ϧ����ϧ����\n", this_object());	
}

void lose_enemy(object me) {
	object room;
	
	if (!me->query("marks/challenge_xinhu"))	return;
		
	me->delete_temp("marks/fi_m_17");
		
	if(!me->query("marks/�������")) {
		message_vision(HIR"\n$N��Ȼ��ŭ������ͽ����ʦ������Ҳ����ô�ص��֡���$N�����������ָ
��$n��ǰһ�Ρ�\n"NOR, this_object(), me);
		tell_object(me, HIR"\n���������һ�ȣ���ʧȥ��֪����\n"NOR);
		me->set("marks/�������", 1);		
		me->unconcious();
	} else if(me->query("marks/�������") == 1){
		message_vision(HIR"\n�ĺ����һ���������һ�ȥ����������������ƽ�ƣ�����ʳָ�����㡣\n"NOR, this_object());
		tell_object(me, HIR"������ؿ���Ѫ��ӿ����ǰһ�ڣ����˹�ȥ��\n"NOR);
		me->set("marks/�������", 1);
		me->unconcious();
	} else if(me->query("marks/�������") == 2) {
		message_vision(HIR"\nֻ��$N��������˫��Ĵָͬʱ����$n̫��Ѩ��$n��ʧɫ������������\n"NOR, 
				this_object(), me);
		tell_object(me, HIR"ֻ����ͷ����һ�����ȣ���ǰһ�ڣ����˹�ȥ��\n"NOR); 
		me->set("marks/�������", 1);
		me->unconcious();
	} 
	message("vision", "����Сɳ��������" + me->name()+ "̧�˳�ȥ��\n", environment(me), me);
	room = find_object("/d/songshan/damocave");
	if(!objectp(room)){
		room = load_object("/d/songshan/damocave");
	}
	me->move(room);
	message("vision", "����Сɳ�ְ�" + me->name() + "̧�����ŵ��˵��ϡ�\n", room);
	me->delete_temp("marks/���ĺ�");
}

void no_answer(object me)
{

	message_vision("$N���˵�ͷ���������ۣ��૵�������ʧ��Ե������������ϲ�粻����ڤ˳�ڵ�������\n",
			this_object()); 
	if(me->query_temp("marks/���ĺ�")){
		me->delete_temp("marks/���ĺ�");
	}
	delete("asking");	
}

void attempt_apprentice(object me)
{
    
	if(me->query_temp("won_master_yi"))
	{
		command("smile");
        	command("recruit " + me->query("id") );
		message_vision(CYN"
$N˵����ĦԺ�ļ�λʦ����þ������������Ŀ���һ"YEL"���"CYN"��
ֻ�Ǻ�������������µĸ��������򲻿���̰ѧ�书��������
������Ϊ���м��мǡ�\n"NOR, this_object());
        	me->delete_temp("won_master_yi");

        	return;
    	}
    	else
    	{
		command("shake");
    	}
}

int do_answer(string arg)
{
    	object ob;
    	object shouyu;
	object me = this_player();

		if (REWARD_D->riddle_check(me,"����֮��") != 3) 
		{
			command("emote ��ü������˵ʲô���������������\n");
        	return 1;
        }   
		if (REWARD_D->riddle_check(me,"�ؾ�¥") || REWARD_D->check_m_success(me,"�ؾ�¥")) 
		{
			command("emote ��ü�����㲻���Ѿ�ȥ�ؾ�¥��ô��\n");
        	return 1;
        }   
		if (arg == "��" || arg == "no")
		{
			no_answer(me);
			REWARD_D->riddle_set(me,"����֮��",2);
			return 1;
		}

    	if(arg == "����" || arg == "yes")
    	{        
    		if (shouyu=present("shouyu",this_player())) 
			{
        	command("say �ðɣ����Ѿ������ҵ����ͣ��㣨wave�����Ϳ����ϲؾ�¥��\n");
			if (!REWARD_D->check_m_success(me,"�ؾ�¥")) 
				REWARD_D->riddle_set(me,"�ؾ�¥",1);
        	return 1;
	        }   
			command("say �ã���ȥ�ɣ�\n");
			command("say �������ҵ����ͣ����ã�wave�����ſ����ϲؾ�¥��\n");
			command("say �����ڴ˹���"YEL"����"CYN"��\n");
			command("say ��������"YEL"ʧ��"CYN"��Ҳ�뾡���֪���ģ�����\n");
			ob = new(__DIR__"obj/shouyu");
			if(!ob->move(this_player()))        	
				destruct(ob);
			if (!REWARD_D->check_m_success(me,"�ؾ�¥")) 
				REWARD_D->riddle_set(me,"�ؾ�¥",1);
			return 1;
	    }
	command("emote ��ü������˵ʲô���������������\n");
	return 1;
}


void die(){
	message_vision("$N�˺󼸲�΢һ��������ɫ�ָֻ��˺���\n", this_object());
	full_me();
}


void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="shaolin") return 0;
	message_vision(CYN"$N���Ƶ���������Ե���α�����,�Ժ�Ҳ��Ҫ�ٻ����ˡ�\n"NOR, this_object(),this_player());
	return 1;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


