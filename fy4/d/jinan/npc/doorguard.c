#include <ansi.h>

inherit NPC;
int give_guard();
void create()
{
        set_name("����", ({ "yinxian" }) );
        set("long","
һ�����»����Ĵ���������Ҳ���ղ������������Զ��ֶ������������为
����ϸ�����������,��͢������������ٻ���������
��ʽ��Ask yinxian about guard
���������ĵȼ����������֮��������ȼ�֮�;�����
���������Ļ������ܵȼ������������֮��������ȼ�֮�;�����
�������������⼼�ܵȼ�����Ĺ������ܵ����⼼�ܵȼ�������
�������������������¹�ʽ������
��������������������֮�������������������ٻ���
����֮������������������
����֮�����������������������������ɵ��ӣ�
����֮�����������������������������ɵ��ӣ�

\n");

        set("class","legend");
        set("attitude", "heroism");
        set("title", "��͢���� ��Ʒ��������");
        set("vendetta_mark","authority");
        set("reward_npc", 1);
	set("difficulty", 10);

        set("cor", 26);
        set("cps", 55);

        set("combat_exp", 5000000);

        set_skill("unarmed", 150+random(500));
        set_skill("blade", 100+random(500));
        set_skill("parry", 100+random(500));
        set_skill("dodge", 100+random(500));
        set_skill("move", 100+random(500));
        set_skill("shortsong-blade",150);
	set_skill("fall-steps",250);

	map_skill("parry","shortsong-blade");
	map_skill("blade","shortsong-blade");
	map_skill("dodge","fall-steps");
	map_skill("move","fall-steps");

        set_temp("apply/damage", 200+random(200));
        set_temp("apply/armor", 200);

        set("chat_chance", 1);
        set("chat_msg", ({
		"�����۾������Ź⣬��Ц�����������Ҷ�³������Ŵ�ѩ��ս�Ͻ���֮�ա�
�����������ȴ�����з�������ʵ�����뿪���á�����\n"
        }) );

	set("inquiry"	,	([
		"����"	: (:give_guard:),
		"guard" : (:give_guard:),
		"huwei" : (:give_guard:),
		"shiwei" : (:give_guard:),
		]) );
        setup();

        carry_object(__DIR__"obj/yafu")->wear();
    	carry_object(__DIR__"obj/peidao")->wield();
}

int give_guard()
{
	object me,shiwei;
	int extra,maximum,gcount,gcount1,i,j;
	
	me=this_player();
	
	if(me->query("class")!="official")
	{
		message_vision("���۶�$N˵����������ʲô��������ʲô�ʸ�Ҫ��������\n",me);
		return 1;
	}
	
	if (me->query_skill("strategy",1)<100
		|| me->query_skill("leadership",1)<100) {
		message_vision("����̾�˿������������˺��У���Դ�����ˡ�\n",me);
		message_vision("���۶�$N˵������Ǹ����������������Ĺٶ��ˣ���100������������֮������\n",me);
		return 1;
	}	
		
	extra=me->query_skill("strategy",1) + me->query_skill("leadership",1);
	
	maximum = 2;
	
	if (me->query_skill("leadership",1)>= 250)	maximum = 4;
	else if (me->query_skill("leadership",1)>= 175) maximum = 3;
//	ccommand("say "+ maximum + " is.\n");
	
	if (me->query("family/master_id")=="master yin")	maximum = 2;
			
    gcount=me->query_temp("guard_count");
	if(gcount>=maximum)
	{
		message_vision("���۶�$N˵��������͢�ĵ��ƣ��㲻����ָ���ٶ��ʿ�ˡ���\n",me);
		return 1;
	}

	if(me->query("family/master_id")!="master yue"&& me->query("timer/shiwei")+ 600>time()) {
		message_vision("���۶�$N˵�������������̫����ϧ��,�Ҷ�������ѵ����.��\n",me);
		message_vision("����˵������һ�������Ҫ������.��\n",me);
		return 1;
	}

	gcount1=maximum-gcount;
	me->set("timer/shiwei",time());
	
//	ccommand("say "+ gcount1 + " is.\n");
	
	for(i=0;i<gcount1;i++)
	{
		if(me->query("sen")<150) 
		{
			tell_object(me,"����񲻹����޷�ָ���ٶ��ʿ�ˡ�\n");
			break;
		}
		if (me->query("family/master_id")=="master yue") {
//			if (extra>48400) extra=48400;
			shiwei=new("/obj/npc/huwei");
			shiwei->invocation(me,extra);
			shiwei->move(environment());
			message_vision("���۶�$N˵�������úø���"+me->query("name")+"�����ɣ���Ч��͢����\n",shiwei);
		} else
		{
//			if (extra>40000) extra=40000;
			shiwei=new("/obj/npc/shiwei");
			shiwei->invocation(me,extra);
			shiwei->move(environment());
			j=8-(me->query_skill("leadership",1)-100)/20;
			if (j<1) j=1;
			shiwei->set("title", "��͢ "+chinese_number(j)+"Ʒ��������");
			message_vision("���۶�$N˵�������úø���"+me->query("name")+"�����ɣ�����ĺô�����\n",shiwei);
		}
		 		
		me->add_temp("guard_count",1);
		me->add("sen",-50);
	}
	return 1;
}
