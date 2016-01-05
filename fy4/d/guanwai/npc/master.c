inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void smart_fight();
void smart_busy();
void smart_attack();
int leave();
int init_quest();

void create()
{
	set_name("����", ({ "master gelun", "master","gelun" }) );
	set("gender", "����" );
	set("class","lama");
	set("long","���׸�ɮ���ڴ��������ֶ��ꡣ��Ů���ӱ鲼���⡣\n");
	
	set("age", 99);

        create_family("������", 20, "����");
    	set("rank_nogen",1);
    	set("ranks",({"��ɮ","�޺�","���","��ɮ","����","��ʿ","��ʦ",
    		"��ʦ","��ɮ","ʥɮ","����","ʥ����",YEL"�󱦷���"NOR,
    		YEL"��»��"NOR,YEL"���ڴ���"NOR,HIY"��������"NOR}));
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
						
	set("inquiry", ([
		"������": "��....������.....���������\n",
		"����": "�����ڴ����µ�ľ���",
		"leave": (: leave:),
		"��ͯת��":	(: init_quest :),
		"ת����ͯ":	(: init_quest :),
		"��ͯ":	(: init_quest :),
		"ʥ��":	"action����ŭ�����㾹Ȼ��֪���ҽ�ʥ�����ڣ�����ʲô���飡\n",
	]) );
        
        set("combat_exp", 3000000+random(1500000));
        set("score", random(90000));
	set("reward_npc", 1);
	set("difficulty", 30);
	   
        set_skill("unarmed", 170);
        set_skill("staff", 300);
        set_skill("chanting", 190);
        set_skill("parry", 170);
        set_skill("spells",200);
        set_skill("iron-cloth", 200);
	
	set_skill("force", 170);
	set_skill("literate", 100);	
	set_skill("perception", 100);
	set_skill("bloodystrike", 200);
	set_skill("fengmo-staff", 180);
	set_skill("bolomiduo", 160);
	set_skill("lamaism", 200);
        set_skill("jin-gang", 200);
        set_skill("kwan-yin-spells",200);
        set_skill("foreknowledge", 100);
    		
	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "fanwen");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "fengmo-staff");
        map_skill("parry", "fengmo-staff");
        map_skill("spells","kwan-yin-spells");
        
	set_temp("apply/iron-cloth",200);

/*      set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
		(: perform_action, "unarmed.fofawubian" :),
		(: cast_spell, "an" :),
        }) ); */
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
        	(: smart_fight() :),
        }) );
        
	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}


void attempt_apprentice(object ob)
{
	if(ob->query("marry") && !ob->query("jiebai")){
		message_vision("$N̾�˿���������ʩ���츳������ֻ��ϧ���쳾���ˡ���\n", this_object(), ob);
		return;
    }	
    	        
    if (ob->query("family/master_id")!="master yunsong"
		|| ob->query("family/master_name") != "����"
		|| ob->query("class") != "lama") {
		command("shake");
		command("say ʩ����Ϊ��ǳ������ȥ��Сͽ���ɰɡ�");
		return ;
	}
	
	if (ob->query_skill("lamaism",1)< 150) {
		command("say ������ڷ�̫���150����������Ǳ�Ŀ�����ꡣ");
		return;	
	}
	
	if (REWARD_D->riddle_check(ob,"��ͯת��")==6)
	{	
		message_vision(CYN"$N���Ƶ������գ�����\n"NOR, this_object());
		command("say �������ͯ��Ϊ�������˴󹦣����ľ���������Ϊͽ��");
		REWARD_D->riddle_done(ob,"��ͯת��",50, 1);
		command("recruit " + ob->query("id") );
		return;
	}		
				
	
	if (REWARD_D->riddle_check(ob,"��ͯת��"))
	{
		command("shake");
		command("say ��ȥ�����������֮ת����ͯ�����õ��飡");
		return;
	}
	
	if (!REWARD_D->check_m_success(ob,"��ͯת��")){
		command("smile");
		command("say ���գ����գ�");
		command("say "+ ob->name(1) + "��");
		command("say �����Ը��겦ϣ���ת��������ʮ����ֻأ�����ǰ�������Բ�š�");
		command("say ����֮�����ǽ������֮ת����ͯ����Ǳ�ķ�����꣬���ɸ������Ρ�");
		command("say ��ȥ�ر����£�ת��ǧ�Σ��������а��ţ�");
		REWARD_D->riddle_set(ob,"��ͯת��",1);
		return;
	}
		
        command("smile");
        command("say �ܺã��ܺã��ܺá�");
        command("recruit " + ob->query("id") );
}

int init_quest(){
	object me = this_player();
	int i;
	
	if (REWARD_D->check_m_success(me,"��ͯת��")) {
		command("pat "+ me->query("id"));
		return 1;
	}
	
	if (me->query("class") != "lama") {
		command("say ������ʩ���޹ء�");
		return 1;
	}
	
	if (!REWARD_D->riddle_check(me,"��ͯת��")) {
		if (me->query_skill("lamaism",1) < 150 ) {
			message_vision(CYN"$N���˿��㣬ҡҡͷ��ͷ���\n"NOR, this_object());
			tell_object(me,"���裱���������ڷ𷨣�\n");
			return 1;
		}
		command("smile");
		command("say ���գ����գ�");
		command("say "+ me->name(1) + "��");
		command("say �����Ը��겦ϣ���ת��������ʮ����ֻأ�����ǰ�������Բ�š�");
		command("say ����֮�����ǽ������֮"YEL"ת����ͯ"CYN"���������Ŷ��꣬���ɸ������Ρ�");
		command("say ��ȥ�ر����£�ת��ǧ�Σ��������а��ţ�");
		REWARD_D->riddle_set(me,"��ͯת��",1);
		return 1;
	}
	
	i = REWARD_D->riddle_check(me,"��ͯת��");
	
	switch (i) {
		case 1: command("say ��ȥ�ر�ת��ǧ�Σ����ɽ���ת����ͯ�����õ��飡");
				return 1;		
		case 2: command("smile");
				command("spank "+ me->query("id"));
				command("say ��һ�������ǰ�����֮���ȣ����Բ��֮�գ�����������ɽ������");
				REWARD_D->riddle_set(me,"��ͯת��", 3);
				return 1;
		case 3: command("say ��ȥ��ɽȡ��ǰ�����֮������õ��飡");
				return 1;
		case 4: 
		case 999:	command("say �ٳ�����ǰ��ʥ�����۵�ת����ͯ������");
					return 1;
		case 6: message_vision(CYN"$N���Ƶ������գ�����\n"NOR, this_object());
				command("say �������ͯ��Ϊ�������˴󹦣����ľ���������Ϊͽ��");
				REWARD_D->riddle_done(me,"��ͯת��",50, 1);
				return 1;
		default:
	}			
			
	return 1;
}
	
int accept_object(object who, object ob){
	
	if (REWARD_D->riddle_check(who,"��ͯת��") == 3)
	if (ob->name() == "��ľ����") {
		message_vision(CYN"$N��ü����ȥ�����֮�ã��������˴��£�\n"NOR, this_object());
		command("say �ٳ�����ǰ��ʥ�����۵�ת����ͯ������");
		REWARD_D->riddle_set(who,"��ͯת��",4);
		return 0;
	}
	
	return 0;
}			
	
	

void init()
{
        object ob;
        ::init();
        add_action("do_killing", "kill");
/*        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }*/
}


void punish_betray(object ob)
{
        if (!ob)	return;
        if((ob->query("once_gelun")==1) && ( (ob->query("class"))!= "lama"))
          {      
			tell_object(ob, YEL"\n���״�ŭ:ԭ���������һ��,�Ǹ�����ʦ�ŵ�С�ˣ���\n"NOR);          	
          	message("vision", YEL"���׶�"+ ob->name() +"ŭ������"+ ob->name() + "�� ��������ļһ�,����һ�ȣ�\n"NOR, environment(ob), ob);
			tell_object(ob, HIW"����һ�Ȼ�����ı��ϣ�\n"NOR);          	
          	message("vision", HIW"����һ�Ȼ���"+ ob->name() +"�ı��ϣ�\n"NOR, environment(ob), ob);
//          	if (ob->query_skill("cloudstaff",1)>160) ob->set_skill("cloudstaff",150);
//          	if (ob->query_skill("lamaism",1)>180)  ob->set_skill("lamaism",180);
          	tell_object(ob, HIR"��ֻ�����ε�ת,ҡҡ�λεص�����ȥ----�ڲ�����ѽ!\n"NOR);
//         	ob->set("once_gelun",2);
          	ob->unconcious();
          }
}


int leave() {
	if (this_player()->query("class")!="lama") return 0;
	message_vision(CYN"$N����һ����������һ������������,�Ϸ���޵ľ����������ˡ���\n"NOR, this_object());
	message_vision(CYN"$N˵�����Ǳ����˷��棬��Ҳ�̲��ù������䡣\n"NOR,this_object());
	message_vision(CYN"$N˵���Ĵ�������⵶ǹ����Ľ�ղ���Ҳ��ֻ�и������ˡ�\n"NOR,this_object());
	
	return 1;
}


smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2) {
		who->cast_spell("ni");
		return;
	}
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			if (enemy[i]->query_skill("iron-cloth")>300 
				|| enemy[i]->query("combat_exp")> who->query("combat_exp")) {
				ccommand("emote �ȵ����������������ĵ��±��£�");
				ccommand("emote �ͳ�һ�ŷ��Ƶľ�ֽ�����ԲͲ�ս���ߡ�");
				who->cast_spell("an");
				who->stop_busy();
				who->cast_spell("an");
				who->stop_busy();
				who->cast_spell("an");
				ccommand("haha");
				return;
			}		
			who->cast_spell("an");
			}
	}
	return;
}

smart_busy() {
	this_object()->perform_action("unarmed.fofawubian");
	return;
}
