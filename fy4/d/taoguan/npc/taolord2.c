// taolord.c
// last modified by annie,6.28.03

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();
int nec_book();

void create()
	{
	    set_name( "������" , ({ "master ding", "master" }) );
	    set("nickname",HIB "��հ���" NOR);
	    set("gender", "Ů��");
	    set("age", 66);
	    set("long",
	        "�������Ƕ��˷��ʦ�ã�Ҳ�Ƕ��˷�������á�\n");
	
	    set("combat_exp", 20000000);
	    set("score", 200000);
	    set("reward_npc", 1);
	    set("difficulty", 40);
	    set("class", "taoist");
		
	    set("no_dodge_snow",1);
	    set("atman", 1400);
	    set("max_atman", 1400);
	    set("mana", 4000);
	    set("max_mana", 4000);
	    
	    set("inquiry", ([
		        "�����ķ�": "�����ķ��������幬Ϊ�Կ�аħ����������ڹ��ķ���\n",
		        "���幬":   "�����幬������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n",
		         "leave" : (: leave :),
		         "�ڼ�" : 	"ȴ��֪�����ڼ���ʲô�ˣ�����\n",
			 	"�������":	(: nec_book :),
			 	"��������":	(: nec_book :),
	        ]) );
	
	    set("apprentice_available", 10);
	    set("chat_chance_combat", 80);
	    set("chat_msg_combat", ({
	        (: cast_spell, "drainerbolt" :),
//	        (: cast_spell, "invocation" :),
	    }) );
	
	    create_family("���幬", 5, "Ů����");
	    set("rank_nogen",1);
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"����","��ͯ","����","С�ɹ�","�ɹ�","ɢ��","����ɢ��",
			"����ɢ��","̫��ɢ��","����","��������","��������",YEL"̫������"NOR,
			YEL"��Ů"NOR,YEL"���ڴ���"NOR,HIY"��������"NOR}));
			
	    set("guard_msg",HIW"$N�ȵ������幬����Ů�ӣ�ȴҲ�����������裡\n"NOR);
	
	    
	    set_skill("perception", 190);
	    set_skill("literate", 150);
	    set_skill("spells", 220);
	    set_skill("chanting",180);
	    
	    set_skill("foreknowledge",100);
	    set_skill("force", 160);
	    set_skill("move", 160);
	    set_skill("unarmed", 160);
	    set_skill("parry", 160);
	    set_skill("dodge", 160);
	    
	    set_skill("sword", 200);
	    set_skill("tenderzhi", 160);
	    set_skill("gouyee", 150);
	    set_skill("notracesnow", 180);
	    set_skill("snowshade-sword", 200);
	    set_skill("taoism", 220);
	    set_skill("necromancy", 200);
	    set_skill("scratmancy",200);
	    set_skill("scratching",200);
	    
	    map_skill("spells", "necromancy");
	    map_skill("unarmed", "tenderzhi");
	    map_skill("parry", "snowshade-sword");
	    map_skill("sword", "snowshade-sword");
	    map_skill("move", "notracesnow");
	    map_skill("dodge", "notracesnow");
	    map_skill("force","gouyee");
	
	    set_temp("apply/dodge", 200);
	    set_temp("apply/armor", 200);
	
	    setup();
	
	    if (!random(10))	
	    	carry_object(__DIR__"obj/sword_d2")->wield();
	    else
	    	carry_object(__DIR__"obj/sword2")->wield();	
	    	
	    carry_object(__DIR__"obj/robe2")->wear();
	    carry_object(__DIR__"obj/hat2")->wear();
	    carry_object(__DIR__"obj/shoe")->wear();
}

void attempt_apprentice(object ob)
{
    	if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            	command("say ������һ��һ������");
        else
            	call_out("do_recruit", 2, ob);
    	} else {
        	command("say ƶ�������Ѿ������������ӣ���������ͽ�ˡ�");
    	}
}

void do_recruit(object ob)
{
    
    	if( (string)ob->query("gender") != "Ů��" )
	{
        	command("say ƶ���ǳ����ˣ���������ͽ��ʩ��������ذɡ�");
		return;
	}
    	else if(ob->query("marry") && !ob->query("jiebai")) {
		message_vision("$Nҡ��ҡͷ˵������λ�������м��ң���λ����������У�\n",this_object(), ob);
		return;
     	}	
     	  
     	if (ob->query("family/master_name") != "���ʦ̫") {
     		message_vision("$N˵����ȥ��Сͽ������м���ɡ���\n",this_object(),ob);
     		return;
     	}
        if (ob->query_skill("taoism",1)<140) {
        	message_vision("$N˵���������ʦ����������ǳ��ȥ��Сͽ��媶����м���ɡ�����140������\n",this_object(),ob);
        	return;
        }
        
        if (!REWARD_D->check_m_success( ob,"�������")){
        	message_vision(CYN"
$N���������������츳������ѧ�ҵ�������֮ѡ�����ǡ�������
�������ҹ��ڶ�����Σ��˷�ʦ�������˷��ֻ�ɽ�Ĺ�����������ƺ׶�Ӳ쿴��
��Ȼ�Ǻ���ͷ��������һ�ղ�ƽ������۲��������������ˡ�\n"NOR, this_object());
			REWARD_D->riddle_set( ob, "�������", 1);
			return;
		}     
             
        command("say �ţ�����������Ϊͽ�������޵�ѧ��������һ��и����");
        command("recruit " + ob->query("id") );
        
}

int recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
	        ob->set("class", "taoist");
    	add("apprentice_availavble", -1);
}


void init()
{	
	object me = this_player();
	::init();
	add_action("do_killing", "kill");
}


int leave() {
	if (this_player()->query("class")!="taoist") return 0;
	message_vision(CYN"$N���������������Ų��⴫���������˿ɲ�Ҫ��ڡ�\n"NOR, this_object(),this_player());
	return 1;
}

int nec_book()
{
	object me,who;
	int i;
	me = this_object();
	who = this_player();
	i = REWARD_D->riddle_check(who,"��������");
	if (!i)
	{
		message_vision(CYN"$N˵�������������ʲô��\n"NOR,me);
		return 1;
	}
	if (i != 2)
	{
		message_vision(CYN"$N̾�˿�����˫��������������Ȼ�����������㡣\n"NOR,me);
		return 1;
	}
	if (query("ggyying") || is_fighting() || is_busy())
	{
		message_vision(CYN"$N��æ����Ȼû�����㡣\n"NOR,me);
		return 1;
	}
	set("ggyying",1);
	ccommand("sigh2");
	who->start_busy(20);
	call_out("do_ggyy",2,me,who,0);
	return 1;
}


void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"�����ơ�������һ��̾�˿�����",
"������˵���������ˣ������ˣ��һ���Ϊ�������Զ��������������",
"������˵������Ȼ������ʵ���Ҳ����Ե���ҾͲ��������ˡ�",
"������˵���������ġ�������ڡ��ؼ�����������ǰ���Ѷ�ʧ��",
"������˵����Ϊά������������׹����סа������˻��������Ҽ�����һ������֮�顣",
"������˵����ȴ���ϣ��������վ������֪��",
"������˵��������������а���������ؼ���ʧ�������к����塣",
"������˵�������ж����ڼ飬���˲��ܵ��֡�������������������ĵ��¡�",
"�����Ƴ�ü��չ��ת������������",
});
	if (!me || !target)
		return;
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,me,target);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",1+random(2),me,target,count+1);
	else
	{
		set("ggyying",0);
		target->stop_busy();
		REWARD_D->riddle_set(target,"��������",3);
		return;
	}
	return;

}


int accept_object(object who, object ob)
{
	
	mapping data;
	
	int i = REWARD_D->riddle_check(who,"��������");

	if (!ob->query("is_xbook"))
		return 0;
	
	if (i != 8)
	{
		ccommand("ack");
		ccommand("say ��͵���������Ҵ�������������");
		kill_ob(who);
		return 1;
	}

	ccommand("ack");
	ccommand("thank "+who->query("id"));
	REWARD_D->riddle_done(who,"��������",100,1);
	
	    data = ([
				"name":		"��������",
				"target":	who,
				"att_1":	"kar",
				"att_1c":	1,
				"mark":		1,
		]);
		
		REWARD_D->imbue_att(data);
		
	
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

