inherit SMART_NPC;

#include <ansi.h>

void check_fight();
void check_death();

void create()
{
        set_name("����������", ({ "white cloth man", "man" }) );
        set("nickname", HIC "һ��������" NOR );
        set("gender", "����");
        set("age", 32);
        set("long","
����һλ�书�����Ķ����ʿ������һ����ɨ��ԭ���֣������޵У�
�����������º�����У��첻֪��ȥ��
\n"
        );
        create_family("ӣ��", 1, "��ʿ");

        set("attitude", "heroism");
        set("combat_exp", 10000000);
 
		set("reward_npc", 1);
		set("difficulty", 5);
		set("class","ninja");

        set("agi",45);
                       
        set_skill("unarmed", 200);
    	set_skill("ghosty-force",300);
    	set_skill("enmeiryu",200);
    	set_skill("ittouryu",200);
    	set_skill("dodge", 200);
		set_skill("ghosty-steps",200);
		set_skill("blade",200);
   		set_skill("force", 180);
    	set_skill("parry", 200);
    	    	   	
    	map_skill("unarmed", "enmeiryu");
    	map_skill("blade", "ittouryu");
    	map_skill("parry", "ittouryu");
   		map_skill("force", "ghosty-force");
   		map_skill("dodge", "ghosty-steps");   	
   	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			100: 	(: check_death() :),
        ]) );   		

   		set("chat_chance", 0);
        set("chat_msg", ({
             (: check_fight() :),
                
        }) ); 
        
        set("asked",1);
   	    setup();
        carry_object("/obj/weapon/sword_katana")->wield();
        carry_object("/obj/armor/cloth",
        		([	"name"	:	HIW"ӣ����ʿ��"NOR,
        			"armor_prop/armor":	8,
        			"long"	: "һ��ӣ����ʿ����\n" ])
        		)->wear();
}

void init(){
		object ob;
		add_action("do_kneel", "kneel");
		if (interactive(ob=this_player()))
		{
			message_vision(WHT"
�����˻�Ȼת��ͻȻ¶��һ��˵���������֮�⣬�ƺ�����Ϊ���ֳ�
�����Ѿ�����̫�࣬���ƺ���Ϊ����ʤ��̫�ࡣ

�����˵���һЦ������

    ������ô����Ը���ܡ�����

\n"NOR, ob);
			this_object()->set("chat_chance",100);
			set("asked",0);
		}	
		::init();
}

int 	do_kneel(){
	
		object me = this_player();
		object room;
		string msg;
		
		
		if (!me->query_temp("marks/baiyiren_beg"))	return 0;
		
		tell_object(me,"����˼���룬���Ǳ���Ҫ����\n");
		message_vision(YEL"\n$N��ͨһ�����ڵأ����´������ϣ���ԭ����"+ me->name(1)+"�������ˣ��ķ��ڷ���
�������̧���֣���С��һ�������Ӵ˲������붫���ʿΪ�С�\n"NOR, me);
		
		message_vision(WHT"\n\n���������������ս�������ˣ�����С�ˣ�����ɡ�
		
		
"YEL"һ�ɴ���ӿ���������Ƽ���ش�С���Ϸ��˳�ȥ��������\n\n\n"NOR, me);

		room = find_object("/d/bat/renjiandao3");
		if (!room) room = load_object("/d/bat/renjiandao3");
		
		msg = NATURE_D->game_time()+ "��"+ me->name(1)+"̰���������ڰ����˵��¹���һ��С����";
		CHANNEL_D->do_sys_channel("info", msg);   
		 	
		if (REWARD_D->riddle_check(me,"��ƽ����")==2)
				REWARD_D->riddle_set(me,"��ƽ����",5);
		me->delete_temp("marks/baiyiren_beg");
		me->unconcious();
		me->move(room);
		set("asked",0);
		remove_call_out("resume_fight");
		return 1;
}
		


void	check_death() 	{
	
		object *enemy;
				
		if (query("asked"))	return;
		enemy = query_enemy();	// SS should be only one.
		if (!enemy || sizeof(enemy)>1)	return;
		if (enemy[0]->query("kee") <= enemy[0]->query("max_kee")*60/100)
		{
			set("asked", 1);
			set("chat_chance", 0);
			enemy[0]->remove_all_killer();
			message_vision(WHT"
�������ֳֳ�����վ�������������һ���޾��Ĵ󺣣�������ŵģ�
ȴ�ǵ����������ֵ�Ӣ�ۣ�

��ãã�ĺ�����ççӢ���䣬��������Ȼ������������į����Ŀ����
į������ת���ţ��������

    �����ꡭ����������������֮�书��Ϊ�ηǵ�ȫ�޾�����������
���ˣ����º�һ�����ѵ�����ĺ�����ˣ���\n\n"NOR, this_object());

			message_vision(CYN"
���������ͻȻ����һ˿�����Ц�ݣ�һ���ֻ����������书��΢����
�Ҷ��֣������������䣬�ұ����һ����·����kneel)\n"NOR, enemy[0]);
			set("NO_KILL","�������������㻰�ء�\n");
			enemy[0]->set_temp("marks/baiyiren_beg",1);
			call_out("resume_fight", 20, enemy[0]);
			return;
		}
		return;
}

void resume_fight(object me){
	set("chat_chance", 100);
	me->delete_temp("marks/baiyiren_beg",1);
	message_vision(CYN"\n\n���������������Ȼ��ԸΪ����������Ҿͳ�ȫ�㡣\n"NOR, this_object());
}

			
		
int accept_fight(object me)
{
		command("heihei");
		return 0;
}

void 	check_fight()	{
		
		object *inv, ob;
		int i;
		
		inv= all_inventory(environment());
		
		for (i=0;i<sizeof(inv);i++){
			if (userp(inv[i]))
			{
				delete("NO_KILL");
				ob = inv[i];
				ob->kill_ob(this_object());
				this_object()->kill_ob(ob);
				return;
			}
		}
		
		set("chat_chance", 0);
		return;
}

//		����ɱ���㱾�£���ɱ������Ҳ����ǿ�㣬--*���� silencer
		
void	killed_enemy(object victim) {

		message_vision(WHT"
����������������ߴ�һ��Ʈ��İ��ƣ����Ƶ���

������Զ����֪���������������˻������ϣ��Ƕ�ô��į������\n\n"NOR, this_object());
	
		if (!userp(victim))	return;
		if (REWARD_D->riddle_check( victim,"��ƽ����")==2)
			REWARD_D->riddle_set(victim,"��ƽ����",3);
		
		return;
}

void	die() {
		
		object killer;	// SS has no pet.
		
		killer = this_object()->query_temp("last_damage_from");
		
		message_vision(WHT"
����������������ߴ�һ��Ʈ��İ��ƣ����Ƶ���

������Զ����֪���������������˻������ϣ��Ƕ�ô��į������\n\n"NOR, this_object());
	
		if (objectp(killer))
		{
			if (REWARD_D->riddle_check( killer,"��ƽ����")==2)
				REWARD_D->riddle_set(killer,"��ƽ����",4);
		}
		
		::die();
		return;
		
}
