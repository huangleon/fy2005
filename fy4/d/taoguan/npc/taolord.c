// taolord.c
// last modified by annie,6.28.03

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string quest();

int cangsheng();
int cure();
int leave();
int marriage();
int event1(object who, int n);
void ding_fight();

void create()
{
	    set_name("���˷�", ({ "master ding", "master", "ding chengfeng" }) );
	    set("nickname", HIG"�̺��˷�" NOR);
	    set("title", "���幬 ������ŷ�");
	    
	    set("gender", "����");
	    set("age", 67);
	    set("long","
���˷�ԭ�������������ң�����С��ѧ�޵���ħ֮��������������ٻ�������
����ö�����������ɽ��ˮ�������ɽ���С����˷��ʱ���к�ʤ֮�ģ����ʼ�
į�����˼���ͽ���ڽ����ϴ�����ĳ�պ�Ȼ�󳹴��򣬰����幬֮�¾��Խ�����
�ð��ƹ��������ֻ���¼���С��ͯ����˵��ÿ�����д��ʱ����������������
��Ҳû��֪������ȥ��\n");
	    
	    set("combat_exp", 20000000);
	    set("score", 20000);
	    set("class", "taoist");
		
/*	    create_family("���幬", 5, "����");
	    set("rank_nogen",1);
	    set("ranks",({"��ʿ","С����","����","С��ʦ","��ʦ",YEL"����ʦ"NOR,YEL"������"NOR,
	                      HIY"����"NOR}));*/
	                     
	    
	    set("reward_npc", 1);
	    set("difficulty", 40);
	    set_temp("no_dodge_snow",1);
	    
	    set("atman", 1400);
	    set("max_atman", 1400);
	    set("mana", 4000);
	    set("max_mana", 4000);
	    
		set("chat_chance_combat", 10);
	        set("chat_msg_combat", ({
	        }) );
	
	    set("inquiry", ([
	         "�����ķ�":    "�����ķ��������幬Ϊ�Կ�аħ����������ڹ��ķ���\n",
	         "���幬":      "�����幬������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n",
	         "������":	(: cangsheng() :),
	         "��ҩ":		(: cure() :),
	         "������":	"����������Ѱ�����ĸ����ˡ�\n",
	         "��̽��":  	"С��ɵ��������鷢������",  
      		 "��Ѱ��": 	"С��ɵ��������鷢������",  	
	         "�Ϲٽ��":	"�Ϲ��ǽ�Ǯ��������������������ڶ���\n",
        	 "��Ǯ��":	"��Ǯ���ǽ����������ϵĵ�һ�������Ϲٽ���ڷ��Ƴ��ｨ����̳��\n",
        	 "÷����":	"action���˷����ü�أ�һ�ﲻ����������\n",
	         "����":		"��˵��Ǯ���ڷ��Ƴ���̳�½��˵��Σ���ȥ����û��һ���ܻ��ų����ġ�\n",
	         "ұ������":	"��˵����ɽ�µ����󸽽��������ˣ����ȥ���������\n",
	         "ұ��":		"��˵����ɽ�µ����󸽽��������ˣ����ȥ���������\n",
	         "����":		"��˵����ɽ�µ����󸽽��������ˣ����ȥ���������\n",
	         "�ڶ�":		"�ڶ�������ɽ�İ�����\n",
	         "Ѫ��":		"�ڶ��е���Ѫ�أ��ǳ����������Ʋ����ҵġ�\n",
	         "��Ѫ��":	"�ڶ��е���Ѫ�أ��ǳ����������Ʋ����ҵġ�\n",
	         "����":		"���������Ѿ��Ӻڶ��ж��ߣ����¿��²���̫ƽ�ˡ�\n",
		 	"�������":	"�������һ�������ɰ��Ʊ��ܡ�\n",
		 	"����":		 (: quest :),
	       	"job": 		(: quest :),

		]) );
	
	    set_skill("literate", 100);
	    set_skill("force", 180);
	    set_skill("move", 150);
	    set_skill("scratching", 250);
	    set_skill("spells",150);
	    set_skill("unarmed", 150);
	    set_skill("sword", 250);
	    set_skill("parry", 180);
	    set_skill("dodge", 160);
	    set_skill("gouyee", 150);
	    set_skill("notracesnow", 200);
	    set_skill("snowshade-sword", 200);
	    set_skill("alchemy",200);
	    set_skill("magic",100);	
	    set_skill("taoism", 200);
	    set_skill("scratmancy", 200);
	    set_skill("necromancy",150);
	    set_skill("perception", 100);
	    
	    map_skill("scratching", "scratmancy");
	    map_skill("parry", "snowshade-sword");
	    map_skill("sword", "snowshade-sword");
	    map_skill("move", "notracesnow");
	    map_skill("dodge", "notracesnow");
	    map_skill("spells", "necromancy");
	    map_skill("magic", "alchemy");	
	    
	    set_temp("apply/dodge", 200);
	    set_temp("apply/armor", 200);
	    
	    setup();
	
	    if (!random(10))
	    	carry_object(__DIR__"obj/sword_d1")->wield();
	    else carry_object(__DIR__"obj/sword")->wield();
	    
	    carry_object(__DIR__"obj/robe")->wear();
	    carry_object(__DIR__"obj/hat")->wear();
	    carry_object(__DIR__"obj/shoe")->wear();
}



void attempt_apprentice(object ob)
{
	    command("say ƶ���չض��꣬���Ѳ����������񣬰�ʦ�޵�һ�£����Ұ��ƹ�����\n");
	    return;  
}



void init()
{	
	object me;
	::init();
	if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	object ob,*inv, ding, tie;
	
	ob=this_object();
	if( !me || environment(me) != environment() ) return;
		
	if (REWARD_D->check_m_success(me,"�ǻ�Ѫ��") && !REWARD_D->riddle_check(me,"�ٴ���Ǯ")
		&& !me->query_temp("maze/ding_talk_1")&& !REWARD_D->check_m_success(me,"�ٴ���Ǯ")) {
		message_vision(YEL"
���˷翴���㣬����δ��ϲɫ����ɫһ�䣬����ؿ����������� 
���˷��¶����ĵ�����λʩ���������ǽӴ���մ���˲�����֮Ѫ����ꪹ��ã�
�㡣�� ���Ѿ�Ⱦ���˲����ҡ���������\n"NOR,me);
		me->set_temp("maze/ding_talk_1",1);
		return;
	}
}

void event2(object me, int num) {
	if (!me || environment(me)!= environment(this_object()) || !me->query_temp("maze/ding_talk_2")) {
	//	command("say stop");
		return;
	}
	if (me->query_temp("is_unconcious")) {
	//	command("say ok wait");
		call_out("event2",2,me,0);
		return;
	}
	tell_object(me,YEL"
��������ʱ�����֣����˷���Ȼ�ɵ��������ϣ������������Χ��ʦ��������ޡ�
���˷绺�������ۣ�΢΢Ц����Ϊʦ������������ȿ����� 

���˷������ĺ����뷢��Ȼ��þ��ף������Դ�Ǹ��Ц������λʩ����ƶ����Ϊ
��ǳ��ֻ�ܽ������еĲ����ұ���ü�Ĵ����ɱ�����ʮ��ƽ������������ʮ��֮
�����ǡ��� "NOR+HIR"

���˷������죬���ڵ��������㻹�޷����ֵõ����Ʋ����ҵ�������ҩ������
��������ʧ�������Ѷ������������� "NOR+HIW"

���˷糤��̾��һ������\n\n"NOR);
	me->delete_temp("maze/ding_talk_2");
	REWARD_D->riddle_set(me,"�ٴ���Ǯ",1);
//	me->set("maze/�һ���ô",1);
	return;
}

int cure(){
	object me = this_player();
	if (!REWARD_D->riddle_check(me,"�ٴ���Ǯ")) {
		message_vision(CYN"���˷�˵��ʩ���ö˶˵ģ�ҪЩʲô��ҩ��\n"NOR,me);
		return 1;
	}
	message_vision(CYN"
���˷��Ц�������廹��ϵ���ˣ��������Ϊ�����������������Ƶ���ҩ��Ȼֻ��
���У���˵Ϊ"NOR+HIR"�����Ĳݡ������ݸλ����������Ҷ�������޼�ľ���͡��߾�֦����"NOR+CYN"
 
���˷��૵������������շ����Ѻͽ�Ǯ�����Ϲ��Ǳ�Ϊ�飬�ڽ�Ǯ������������ 
�����ˡ����������ѵ�̫ƽ�˼�ʮ�꣬�ѵ���Ҫ��ʼ����Ϳ̿��Ѫ��������ô�� \n\n\n"NOR,me);
	REWARD_D->riddle_set(me,"�ٴ���Ǯ",2);
	return 1;
}

int leave() {
		if (this_player()->query("class")!="taoist") return 0;
		message_vision(CYN"$N���������������Ų��⴫���������˿ɲ�Ҫ��ڡ�\n"NOR, this_object(),this_player());
		return 1;
}



int	accept_object( object who, object what) {
	
	mapping data;
	
	if (what->query("name")=="մ����Ѫ�����") {
		if ( REWARD_D->riddle_check(who,"��̽��Ǯ")!=3
			|| what->query("lu_spear")!=2 ) {
			message_vision(CYN"
���˷�ü�ؽ�������Ŀһ�Բ�����������\n"NOR,who);
			return 0;
		}
		message_vision(CYN"
���˷�Ŀ�־���֮ɫ���������"NOR+HIR" 


���˷��÷�����סմ����Ѫ����ꪣ������˰��Σ�������ɫʱ��ʱ�죬��
�����꣬�������дʣ�����һ�ڣ�����ڿ�����ֱֱ�������֮����ɲ
��֮�䣬��������ڶ���ȼ�� 


���˷���Ȼ��ϥ���������ϣ����˲����ϵĺ�����������ƶ��������ζ���
�������������ʮ���죬���ɷٻ�Ѫ��֮�������ҡ���"NOR+HIW"
 
 
���˷��Ц�������ϲ������ѵ���Ҫ����һ���ƽ�ô�������Ұ������ҡ����� 
������˫Ŀ��ɲʱ��·���ȥ�˼�ʮ���һ�������� 


		\n"NOR,who);
		
		if (!REWARD_D->check_m_success(who,"��̽��Ǯ"))
		{
			REWARD_D->riddle_done(who, "��̽��Ǯ",100, 1);
		
			data = ([
				"name":		"�ƽ�������̽��Ǯ",
				"target":	who,
				"att_1":	"kar",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);
		}
		
		who->set("maze/�����",time());
		return 1;
	}
	
	if (what->query("name")=="�Ͻ�" && what->query("guo_sword")) {
		message_vision(CYN"
���˷羪�ȵذ���һ�����⡢��Ī�����������������������ڣ���������������
�����������Ѿ���������\n\n"NOR,who);
		if (who->query("maze/����������")) {
			message_vision(CYN"
���˷�����˽����ۣ������д棬ֻ���ҵ�ұ�����ˣ���ɵ���ݼ����\n"NOR,who);
		}	
		else
			message_vision(CYN"
ʩ���Ӻδ��õ���һ�ѽ��ģ������Ǳ���̰���߿ֲ��ܵ�֮��\n"NOR,who);
		return 0;
	}

	return 0;
}
		
		
string *event1_msg=	({
	
	YEL"\n���˷�����������˫�ۣ���̾һ���������꽭��������������ʦ������������⣬��ʵ
����������Ȼ������������٣���Ԫ��ڤ�粻����λ��ʦ���Σ�ֻ�ý�����ں�ɽ�� 
��֮�С�Ȼ���������ɣ��������ڶ�������ʴ��������ҵ���ڰ���ǰ��⣬��ϧ��ʦ 
���ö�����Ϊ���㣬�Ұܶ��飬δ�ϵ����ս����ϲ����Ҿ�������������������������\n"NOR,
	
	GRN"\n���˷��Ȼ����������������ʦ���ý����˲���������������λ������ȥ�ڶ��ٵ���Ѫ 
�أ������֮���ӣ�������ճ��ز�֪���٣���ʱ����ǧ���ѵ�֮���� \n"NOR,
	
	YEL"\n���˷�����ԣ�д��һ�ŷ�����㡣 
���˷��Ц������һֽ��а����ɱ��㲻�ܶ�����ħ֮������\n"NOR,

	YEL"\n���˷���д����������������дǣ���ľ������һָ�����ȼ��ҡҷ�Ļ��棬ȴ���ɻң� 
���۳��ţ������ְ������������˷���Ȼ����������ζ���֮�֣���ֻ�轫�����Ͷ��
�ڶ��е���Ѫ�ء����ɽ����Ʋ����ҵ�Ѫ�ػٵ����� \n"NOR,

    	WHT"\n���˷�̾Ϣһ�������ײ�� \n"NOR,
    	
});

int cangsheng()	{
	
	object me;
	
	me = this_player();
	
	
	if (query("in_event_1"))
	{
		tell_object(me, "���˷���æ���Ե�Ƭ�̡�\n");
		return 1;	
	}
	
	if (REWARD_D->check_m_success(me,"�ǻ�Ѫ��")){
		message_vision(CYN"���˷�˵����Ѫ���ѻ٣������ҵ�Դͷ�Ͷ��ˡ�\n"NOR,me);
		return 1;
	}
	
	if (me->query_temp("maze/�����嶴Ѩ")) {
		message_vision(HIC"���˷�˵�����ְ�Σ�ڴ�һ�٣��㵱��ȥ���������ҵ�Ѫ�ء�\n"NOR,me);
		return 1;
	}
	
	if (!REWARD_D->check_m_success(me,"��̽��Ǯ"))
	{
		message_vision(CYN"���˷�������˵�������ң������ң�ʩ�����ǲ�Ҫ���ʴ���Ϊ�ã���\n"NOR,me);
		return 1;
	}
		
	event1( me, 0);
	return 1;
}

int event1(object me, int count)
{
	object paper, seed;
				
	if (environment(me)!= environment(this_object())) 	
	{
		delete("in_event_1");
		return 1;
	}
		
	set("in_event_1",1);
	
	tell_object(me,event1_msg[count]+"\n");
		
	if(++count==sizeof(event1_msg))
	{
		delete("in_event_1");
		REWARD_D->riddle_set(me,"�ǻ�Ѫ��",1);
		// Here we use temp mark to give ppl more seals if lost.
		me->set_temp("maze/�����嶴Ѩ",1);	
		paper = new(AREA_MAZE"npc/obj/cv-seal");
		if (paper) {
			paper->move(me);
			paper->set("paper_owner",me);
		}
		seed = new (AREA_MAZE"npc/obj/cv-seed");
		if (seed) seed->move(me);
		return 1;
	}
	else 
		call_out("event1",1,me,count);
	return 1;
}

string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	object me = this_player();
	
	if (me->query("quest/short") == "ȥ���˷紦�������յ��¶�")
	{
		if (me->query("quest/duration") == 421)	// ��С��
		{
				n=1+random(3);
				me->set("annie_quest/name","�ڶ������������");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"���ڶ����XXX"+WHT"����������"NOR);
				me->set("annie_quest/target","��������");
				
				me->set("quest/short", WHT"���ڶ����"+ n + WHT"����������"NOR);
				me->set("quest/location", "�ڶ�");
				me->set("quest/difficulty",n*30);	// ÿ��һ���Ͷ�30% reward
				me->set("quest/duration",900+n*60);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());
				arg= "�����ɽ���ĺڶ�����������������ȥ���������\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 422)	// ��С��
		{
				n=1+random(3);
				me->set("annie_quest/name","�ڶ����������");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"���ڶ����XXX"+WHT"��������"NOR);
				me->set("annie_quest/target","������");
				
				me->set("quest/short", WHT"���ڶ����"+ n + WHT"��������"NOR);
				me->set("quest/location", "�ڶ�");
				me->set("quest/difficulty",n*30);	// ÿ��һ���Ͷ�30% reward
				me->set("quest/duration",900+n*60);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());
				arg= "�����ɽ���ĺڶ������������ޣ���ȥ���������\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}

		return "�������ûʲô���飬�㲻��û�����ʦ���ݲ�ɡ�\n";	// error mark.
	}
	else
		return "action���˷�Ц��˵����������еúܣ������˶���";
	
	return " ";
}
