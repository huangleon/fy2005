inherit NPC;
#include <ansi.h>

void growup();

void create()
{
	object staff;
	
	set_name("��Ⱦ���", ({ "chi you", "chiyou" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("class","wolfmount");
	set("age", 10000);
	set("long", "��ȣ���Ƶ���¹��ԭ��һ���������罣ꪣ�ͷ�����ǣ�ͭͷ�����ɱ 
�޵����˹��������������֮��һ��ħ������ͷ������һ������������
��[37m����[32mû������\n");
	set("title", "����ս��");
	set("nickname", HIR"�����ħ"NOR);
	set("NO_KILL","���޷�����һ��ʯ��\n");
	set("spawn_location","/d/wolfmount/chiyouku");
		
	set("str", 90);
  set("force_factor",100);
	set("cor", 100);
	set("per", 1);
	
	set("boss",1);
	set("big_boss",1);
	set("max_kee", 300000);
	set("max_gin", 300000);
	set("max_sen", 300000);
	
	set("limbs", ({ "ͷ��", "����", "צ��" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       	(: growup() :),
  }) ); 
	
	set_skill("unarmed", 700);
	set_skill("iron-cloth", 200);
	set_skill("yiqiforce", 100);
	set_skill("dodge", 400);
	set_skill("force",100);
	set_skill("parry", 400);
	set_skill("wolf-curse",200);
	set_skill("cursism",200);
	set_skill("summonwolf",300);
	set_skill("perception",400);
	map_skill("unarmed","yiqiforce");
	map_skill("cursism","wolf-curse");
	map_skill("force","yiqiforce");
	
	set("combat_exp", 13000000);
  set("staff",1);              
  set_temp("apply/attack", 200);
  set_temp("apply/dodge", 200);
  
	setup();
	  
  	if (!query("claw_set")) {
			if (!random(5)){
				staff=new(__DIR__"obj/wolf-fist");
				staff->move(this_object());
				staff->wield();
				staff->set("nodrop_weapon");
				set("claw_set",2);
			}	
			else
				set("claw_set",1);
		}
}

void init() {
	::init();
	if (query("staff"))
		add_action("do_pull", "pull");
	if (interactive(this_player()) && !query("NO_KILL")){
//		ccommand("say ok");
		kill_ob(this_player());	
		this_player()->kill_ob(this_object());
	}
}

string staff(){
	object me;
	me = this_player();
	if(query("staff")){
		tell_object(me, YEL"\n
һ������������ľ�Ƴɵķ��ȣ�һ��������������Ⱦ���ͷ������¶����һ����
���ɹ⻪��Ŀ����֪���Ƿ��ܰγ�����pull)���ݴ��Ϲ�ʱ�Ƶ�նɱ��Ⱦ��׺�
Ψ�������겻ɢ�����������������������Ȳ������ʯ������ס�ⲻ��֮�ף�
�������÷���\n\n"NOR);
	} else {
		tell_object(me, "���������ͷ���ķ�����Ȼ������ֻʣһ���ն���\n");
	}
	return "";
}

int do_pull(string arg){
	object me, staff;
	int damage;
	me = this_player();
	if(!arg || (arg != "staff" && arg != "����")) {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if(!query("staff")) {
		return notify_fail("�Ѿ�û�з����ˡ�\n");
	}
	if(me->query("kee") < 100) {
		return notify_fail("��û���㹻����Ѫ��\n");
	}
	if(me->query("force_factor") > 80 && me->query_str() > 30 ) {
		message_vision("$N˫�ֽ�����ס���ᷨ�ȣ�����һҧ��������Ѫ���䣬ŭ��һ�����𣡣�\n", me);
		message_vision(HIY"\n���ᷨ��ͻȻ�ų�����𻪣���ɫ���Σ�ɽҡ�ض�֮�䣬����Ӧ�����𣬳��������\n"NOR,
				me);  
	set("long", "��ȣ���Ƶ���¹��ԭ��һ���������罣ꪣ�ͷ�����ǣ�ͭͷ�����ɱ 
�޵����˹��������������֮��һ��ħ��\n");
		set("staff", 0);
		me->perform_busy(4);
		call_out("stone_fall", 3, me);
	} else {
		message_vision("$N˫�ֽ�����ס���ᷨ�ȣ�����һҧ��������Ѫ���䣬ŭ��һ�����𣡣�\n", me);
		message_vision("���ᷨ����˿������\n", me);
		me->perform_busy(4);
		damage = me->query("kee") / 5;
		me->receive_damage("kee", damage);
	}
	return 1;
}

void stone_fall(object me){
	object *all, *inv, room, obj;
	int i;
	string *names = ({"chiyoudao", "chiyoudao1", "chiyoudao2", "chiyoudao3", "chiyoudao4", "chiyoudao5",
			"chiyoudao6", "chiyoudao7", "chiyoudao8", "chiyoudao9"});
	
	all = all_inventory(environment(this_object()));
	
	message_vision("\nͻȻ֮������ؿ�����������Ѱ㣬Ũ�Ʒ���������������ɽʯ���缲�籩���\n", me);	 
	message_vision("�������£�\n", me); 
	message_vision("\n$N��ɫ��䣬����ȫ������ʯ�籩�п��Ѱ��һ��������\n", me);
	for(i=0;i<sizeof(names);i++){
		if( obj = find_object(__DIR__+names[i])) {
		tell_object(obj,HIY "\n\nԶ������һ��¡¡���죬����������ʯ��������������\n\n"NOR);
		}
	}
	
	inv = filter_array(all, (: interactive($1):));
	for(i=0; i<sizeof(inv); i++) {
		message_vision(HIY"$N����ͻ�������ı仯����Ŀ�ɿڴ���ֻ��������ʯ�ݺݵ����˹�����\n"NOR, inv[i]);
		message_vision(HIY"�����ǵ��޿ɵ����޿ɶ㡣\n"NOR, inv[i]);
		if(inv[i]->query_skill("dodge",1)>=150 && inv[i]->query_skill("parry",1)>=150){
			message_vision(HIG"\n����䲻�ݷ��������$N����˾�ʯ�Ĺ�����\n"NOR, inv[i]);
		} else {
			tell_object(inv[i], "�����Ҷ���ǰ�������������ʯ��Ϯ����\n");
			me->perform_busy(3);
			room = find_object(AREA_WOLFMOUNT"chiyoudao");
			if(!objectp(room)){
				room = load_object(AREA_WOLFMOUNT"chiyoudao");
			}
			message_vision(RED"\n$Nһ������������������ʯ�ݺݵ����˹���������\n"NOR, inv[i]); 
			inv[i]->move(room);		
			inv[i]->unconcious();
		}
	}
	
	remove_call_out("chiyou");
	call_out("chiyou", 3, me);
	
}

void chiyou(object ob){
	object *all, *inv;
	int i;
	
	if(!interactive(ob) && environment(ob) != this_object()){
		set("staff",1);
		return;
	}
	message_vision(HIB"\n������ʯ�У����է����ɫ���һƬ�������·���������Ұ��������ŭ��\n"NOR, ob);
	message_vision(HIR"\n�ʺ���Ѫ��Ĵ������ȼ��һƬ��������һ���ߴ�ٳߣ����������ľ޺���\n"NOR,ob); 
	message_vision(HIR"Զ����������������ÿһ���ط�����������а������Ĥ�ݣ��������\n\n"NOR, ob);
	message_vision(HIY"              ������������ս���񣭣�򿣭�ȣ��أ�������  \n\n"NOR, ob);
	
	delete("NO_KILL"); 	
	set("name","���");
	
	all = all_inventory(environment(this_object()));
	inv = filter_array(all, (: interactive($1):));
	for(i=0; i<sizeof(inv); i++) {
		kill_ob(inv[i]);
		inv[i]->kill_ob(this_object());
		}
}


void growup(){
		
		object staff;
		ccommand("exert npc_hurtless");
		
		if (query("timer/cy_curse")+ 30 + random(20) < time() && query("kee")*100/query("max_kee")<90
			&& sizeof(query_enemy())>1){
			delete("timer/pfm/wm_mindcurse");
			ccommand("curse mindcurse");
			stop_busy();
			if (!random(3) && sizeof(query_enemy())>2) {
				delete("timer/pfm/wm_mindcurse");
				ccommand("curse mindcurse");
				stop_busy();
			}
			ccommand("xiao");
			set("timer/cy_curse",time());
		}
		
		return;
}			
		
/*
void chiyou_call(object ob){
	if(ob->query("marks/wolfmount_chiyou_kneel")){
		message_vision(CYN"$N���췢�������ĵ����ѵ�����ŭ��ɽʯ���£����Ʒ�����\n"NOR, this_object()); 
		message_vision(CYN"���Ѫ��֮�䣬����ͻȻ�ѿ������죬$N���Ӵ�������������������\n"NOR, this_object());
		message_vision(CYN"���¹�����һ��ļž�����\n"NOR, this_object());
		destruct(this_object());
	} else { 
		message_vision(HIG"$N���췢�������ĵ����ѵ�����ŭ��ɽʯ���£����Ʒ�����\n"NOR, this_object()); 
		message_vision(RED"\n$N΢΢���ף�ɢ��������ɱ����Ѫɫ��������$nһ���ֵ�������������������£�\n"NOR, this_object(),ob); 
		message_vision(RED"�����ų���ޣ�������س�������kneel or reject��\n"NOR, this_object()); 
	}
}

int do_kneel(){
	object me;
	me = this_player();
	tell_object(me, YEL"��ֻ�������ޱߵĻ𺣺Ϳ־�֮�У�˫ϥһ�䣬������أ��ϻ̳Ͽ�Ĥ�ݵ���ս���������������£�\n"NOR);
	message("vision", YEL""+me->name() + "˫ϥһ�䣬������أ��ϻ̳Ͽ�Ĥ�ݵ���ս���������������£�\n"NOR,
			environment(me), me);
	if(query("busy") || this_object()->is_fighting()){
		return notify_fail(WHT"�����æ��û��ʱ�����㡣\n"NOR);
	}
		message_vision(RED"\n$NѪ���������䣬��Ц���ε�������ĳ��ȥ���������ԯ�۳�������������\n"NOR,this_object()); 
		message_vision(RED"����Ļ������١�����ԯ�Ϲ� ���Ѫ��֮�䣬����ͻȻ�ѿ������죬�������\n"NOR, this_object()); 
		message_vision(RED"�������������������� ���¹�����һ��ļž�����\n", this_object()); 
	destruct(this_object());
	return 1;
}

int do_reject(){
	object me;
	me = this_player();
	set("busy", 1);
	message_vision(HIG"$N���¶������쳤Ц������ʹѪ���ڴˣ���ٲ�����Ҳ������ϥ��磡\n"NOR, me); 
	message_vision(HIR"\n$N˫��Ѫ�Ⱪ�𣬺ȵ���˳���߲��������ߡ���������\n"NOR, this_object()); 
	me->kill_ob(this_object());
	kill_ob(me);
	return 1;
}
*/



void die(){
	object me,staff;
	object owner,room;
	mapping hate;
	object *ppl, *ppl_present;
	int i;
	
	message_vision(HIR"\n$N˻�е������ɶ�ġ��������һ��ٻ����ġ���"NOR, this_object());
	message_vision(HIR"$N���Ӵ�����ͻȻ��Ϊһ��Ũ����ʧ�����ˡ�\n"NOR, this_object());
	
	if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
    
  if (me) {
       	hate = query_hate_list();
	    if (sizeof(hate))
	    	ppl = keys(hate);
	    CHANNEL_D->do_sys_channel("sys",sprintf("ppl is %O\n",ppl));	
	    if (sizeof(ppl)) {	    
       		ppl_present=filter_array(ppl,(:objectp($1) && userp($1) && environment($1)==environment():));
	    }
	    CHANNEL_D->do_sys_channel("sys",sprintf("ppl_present is %O\n",ppl_present));
	    if (sizeof(ppl_present)) 
	    for (i=0;i<sizeof(ppl_present);i++) 	
	        REWARD_D->riddle_done(ppl_present[i], "��ն��ħ", 100, 1);   
	}
    
	if (me) 
		CHANNEL_D->do_sys_channel("info",sprintf("%s��%s������ؿ߻�ɱ��ȡ�", NATURE_D->game_time(),me->query("name")) ); 
	
	seteuid(getuid());
	
	staff=new(__DIR__"obj/tigersoul");
	staff->move(environment(this_object()));
			
	if (query("claw_set")==2) {
		staff=new(__DIR__"obj/wolf-fist");
		staff->move(environment(this_object()));
	}
	
	destruct(this_object());
}


