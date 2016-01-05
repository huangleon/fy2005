#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();
int ask_tie();
int letter();
int analyze();
int gate();

void create()
{

		set_name("���Ӻ�",({"an zihao","an"}));
    	set("long", "
̫ƽ����վ����ة�����Զ���˰�������ϡ�٣������վ���˵�����ߵĹټ�
��������ة���ǰ�ʮ�������յĸ�ĸ�١�\n");
		set("title", "̫ƽ����ة");
		set("nickname", "����ͨ");
		set("age",40);
	
		set("combat_exp", 8000000);
        set("gender","����");	
		set("reward_npc", 10);
		
		set("inquiry", ([
        	"Τ����" : 	(: show_me :),
           	"wei qiniang" : (: show_me :),
           	"tie hen" : 	(: ask_tie :),
           	"����" : 	(: ask_tie :),
   			"С��": 	(: letter :),
   			"���ն�":	(: letter :),
   			"����":		(: analyze :),
   			"��������":		(: analyze :),
   			"�ر�":		(: gate :)
   		]));
		
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n���Ӻ��ȵ������˷��ˣ���Ȼ��ɱ�ٲ����\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"���Ӻ�˵�������հ������Ӻ���ƽ���İ���������ӣ����ܵĺ�����\n",
    	}) );  
	

		auto_npc_setup("wang",300,180,0,"/obj/weapon/","fighter_w","yue-spear2a",2);
		set_skill("changquan",220);
		delete("perform_busy_u");
		set("perform_busy_d","legend/dodge/fall-steps/qiufengluoye");
		set_skill("dormancy",300);
		set_skill("six-sense",300);
		set("smartnpc_busy",1);
		
		setup();
		carry_object(__DIR__"obj/o_cloth")->wear();
		carry_object(__DIR__"obj/sspear")->wield();
}


int show_me()	{
	if (REWARD_D->riddle_check(this_player(),"�Ѫ����")>=5) {
		command("say ԭ��������������ģ�������������������ȸ������һ�����������ɡ�");
		call_out("event1",1,this_player(),0);
	}
	else {
		command("consider");
		command("say Τ�����ֽ�����Τ����ڽ����ϴ��������רɱ��Щ���׼���֮�ˡ�");
		command("say �����⼸�����������伣����˵�Ѿ������ˡ�");
	}
	return 1;
}


int ask_tie()  {
	
	object who;
	who=this_player();
	if (REWARD_D->riddle_check(who,"�Ѫ����")>=5)
		ccommand("say ���ޣ�Τ������Ҷ���׷��̫ƽ����ʧ���鱦�����䡣");
	else
		ccommand("say �����������������Ĵ�����֮�������顣");
	return 1;
}	

int analyze(){
	object me, ob;
	string *hint, msg;
	int i, num1, num2;
	mapping info = ([ 							
						"��ɱ��": "��ɱ����Ȼ�ڵط���������С�����ֻ����������ү�����һ������ˣ�
����ү����һǧ���ƽ����������������Ϊ�˻��������ĵ�ϸ��\n",							

						"�ϻ׳�֮��": "�ϻ׳���ز�¶����Ȼ�ڴ˳��֣���Ȼ��̫ƽ�������鱦�йأ�
û�뵽ȴ������ү���������\n",

						"ʬ�������": "̷���ֵ�̰�ƶ��������������³��������Ǿ����뾹������СС
��̫ƽ����֣�������������Ի��������ĸ��ֻ��治�١�\n",

						"��ʯ������": "�����޵ĺ�ʯ��ȻҲ����������֣�Ī�ǣ���̫ƽ����������аħ��֣�\n",
						
						"����ͷ":	"����ͷ������������ˣ����մ������ƺ�ûʲô����֮����\n",
							
						"�����������": "��������Ȼ���죬��ֻ��Щ���ϵĹ��򣬲�����Ļ��֮�ˡ�
���Ҿ�Ȼ�а���ͨ������¥���⵹������֮�£�Ī�ǣ������������˲�ǲ��
ר�ż���Ѫū�ġ���ô���Ѫū�ְ���ʲô��ɫ�أ�\n",

						"���ƹ�": "�����ƹ�����ľ�˵��Ѫū�͸����������˵��һ���Ļ������
�������ϣ��־�˵������Ҳû����Ѫū��ȴ�Ѿ��õ����������㡣������
��Ȼ��û���ɵ���ȥ��а�š�а�ţ����������ƹ����ҿ�ûʲô���⡣\n",

						"��Ц": "��Ц���ˣ�ԭ����Ϊ��׷��̫ƽ����һ������ô��������������ү��
�����ֶ��˸�������ɫ��������������Ī���Ѫ���ġ�\n",

						"Ѫū����": "��Ѫū�ѵ������Ѫ���ĵ�ū�ţ���ô��Ѫ���ĵĴ�˵�ѵ���Ҫ��
�������\n",	
						
						"����":	"�˴��д�ʧ�ܣ���ı֮��һ��������ģ���������Ȼ�����Ѿ����˴̿�
ɱ�㣬˵�����ǵĵ����Ѿ������˹ؼ����������ײ���̫Զ�ˡ�\n",
							
					]);
						
	me= this_player();
	ob = this_object();
	
	
	if (REWARD_D->riddle_check(me,"�Ѫ����")>=7) {
		tell_object(me,CYN"���Ӻ�˵����������ɽׯ��Ӧ�þ����������Ĺؼ����������뷨Ǳ��̽��������\n"NOR);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"�Ѫ����")!=6) {
		command("doubt");
		return 1;
	}
	
	num1 = sizeof (info);
	num2 = sizeof (me->query("marks/parrot"));
		
	tell_object(me,WHT"���Ӻ�˵���ã��Ǿ������ǿ�������������Щ������"+ num2 +"/" + num1 +"��\n\n"NOR);
	
	hint = keys(info);
	
	msg = "";
	
	for (i=0;i<sizeof(info);i++) {
		if ( me->query("marks/parrot/"+hint[i]))
			msg += CYN+ info[hint[i]] + "\n"NOR;
	}
	
	tell_object(me,msg);	
	
	if (num2 < num1/2) 
		msg = "���Ӻ�˵����̫ƽ�������úܶ࣬�����ϸ�Ķ�Ӵ�̽���ǡ�\n";
	else if (num2 < num1)
		msg = "���Ӻ����ͷ˵�������ⰸ���������ʣ������ƺ�����һ��ʲô��\n";
	else
		msg = "���Ӻ���������û�뵽ССһ��̫ƽ�򣬾�Ȼ��������ô�����ǵ����
��������һ���ǿ϶��ģ��⿴��ǧ˿���ƵĹ�ϵ����ǣ��̫ƽ�������鱦�ϡ�
˭�ǵ����ģ�˭�Ƕᱦ�ģ�˭���ǻ������أ�

���Ӻ�˵����������һ���Ѫ���ģ����²����糣Ц��˵��ֻ��һ�����۷�����
�����Ĵ������е����ޣ���ô�ֻ���Ե�޹ʵ���ȥ��

���Ӻ�˵����ǰ�������һ������������үɱ���ϻ׳棬��һ�������������
�����ˣ�������������ɽ�ۻ���������ȥǱ��������ׯ�У�̽һ̽���ϸ��
���з紵�ݶ�������"YEL"�ر�"NOR"���������ƽϡ�\n";

	tell_object(me,msg);
	
	if (num2>=num1)
		REWARD_D->riddle_set(me,"�Ѫ����",7);	
	
	return 1;
		
}		

int gate(){
	object me= this_player();
	
	if (REWARD_D->riddle_check(me,"�Ѫ����")>=7) {
		tell_object(me,CYN"���Ӻ�������������ȥ���ƺ�Ҳû��ʲô���ߡ�\n"NOR);
		return 1;
	}
	
	command("hehe");
	return 1;	
}

string *event1_msg=	({
	
	GRN"\n  ���Ӻ���������Բ�˰��̫ƽ����Ψһ�����̵ĵط����ط���Ȼ��С�����Ǹ�
������������֣�ɽ����˵�����ͻ�����������������ĵط������ࡣ�������ϴ�
���飬����һ��ֻ�а�ʮ�����˼ҡ���\n"NOR,
	
	GRN"  ����߻ʵ�Զ������վ��Ψһ�ټҵ���������Ҳ��������ĸ�ĸ�١������Ӻ�Ц
Ц˵������������Ҳֻ������ү�����µ�ʱ�򡣡���ү���䣬������䣬��"+HIG"����ɽ"NOR+GRN"��
��ط���һ�������ġ���\n"NOR,
	
	GRN"  �����û��"+HIG"�����"NOR+GRN"����Ҳ����Ͱ���һ��Ҳ����������û����֪������������ʲ
ô��Ҳû��֪������������ֻ֪��������ǰ��������������ׯ԰����\n"NOR,

	GRN"  ��һɽ�ݲ��ö�����"+HIG"�����"NOR+GRN"��"+HIG"����ү"NOR+GRN"һֱ������������������Ϊֹ���ƺ�˭��û
��ռ�Ϸ硣��\n"NOR,

    	GRN"  ������ǰ����ͷ������һЩ�������ʱ������������������һ��̫ƽ����ʧ�Ե�
�鱦������Щ�鱦����Դ����ᵽ���С����Χ��Τ��������ڴ����鰵�ã�����
һ������ֱ������ǰ������ס����ɣ������������ǰ��������һ���鱦���ڴ�
�����֣������������������Э����ԭ�򡣡�\n"NOR,
    	
});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) 
		|| this_object()->is_fighting()) 	return;
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		tell_object(me,GRN"  ��������ү��������⣬�����ϻ���"+HIG"�ϻ׳棬̷���ֵܣ������裬����ͷ�����ƹ�"NOR+GRN"
����ֵ��һ�顣ǰ���վ����Ĵ�����֮һ�Ķ���"+HIG"��Ц"NOR+GRN"ҲͻȻ������������ĺ���
��������С�ġ����пգ�Ҳ��ȥ����¥תת��˵�������ܼ���"+HIG"Ѫū"NOR+GRN"���

����С�Ľ���������Щ���ﶼһһ���壬��������������һ����"YEL"����������\n\n"NOR);
		if (REWARD_D->riddle_check(me,"�Ѫ����")==5)
			REWARD_D->riddle_set(me,"�Ѫ����",6);
		command("addoil "+me->get_id());
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


int letter() {
	object room;
	object me;
	me = this_player();
	room = find_object(AREA_QUICKSAND"yizhan");
	if (room && room->query("route_clear")) {
		message_vision(CYN"
���Ӻ��Ǻ�һЦ˵����С����һ�������նӺ��ҵ���վ����������������
��͢ٺ»̫�٣���Ҳ�ǲ����ѣ�������������Ȼ�ǹ��̣�һ��ͯ�����ۡ���\n"NOR,this_object());
		return 1;
	}
	message_vision(CYN"
���Ӻ������˵����С�˵����նӺ��ҵ���վ������������������͢ٺ»̫
�٣���Ҳ�ǲ����ѡ������⼸���������ϳ���ǿ������˵��"+room->query("bandit_name")+"��������
�ɵģ��������˵�����������Ϊ����"+RANK_D->query_respect(me)+"�����ȥ�����ǽ���ͺ��ˡ���
\n"NOR,this_object());
	me->set_temp("quicksand/route_bandit",room->query("bandit_name"));
	return 1;
}