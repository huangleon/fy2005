#include <ansi.h>
inherit NPC;
inherit INQUIRY_MSG;

void create()
{
        set_name("��ʦ", ({ "chef" }) );
        set("gender", "����" );
        set("age", 43);
        set("long", "һ���������Ĵ����\n");
        
        set("combat_exp", 1000000);
        
	set("attitude", "friendly");
        
        set_temp("apply/attack", 150);
	set_temp("apply/dodge",150);
  
  
  	set("inquiry", ([
        	"ԭ��" : "�ղ˵�ԭ�ϲ��������ϰ����������˰�æ�ء�",
        	"����": "֪���һ�Ҫ���æ��",
   			"��ɽ����": "֪���һ�Ҫ���æ��",
   			"ɳ���": "֪���һ�Ҫ���æ��",
   			"����": "֪���һ�Ҫ���æ��",
   	]));      
        set("chat_chance", 1);
        set("chat_msg", ({
			"�������䤱���æ���ղˣ���ζ���硣����\n",
			"���̾����˵��ԭ�ϲ�ȫ���ɸ���Ϊ����֮������\n",
        }) );
        setup();
		carry_object(__DIR__"obj/apron")->wear();
}


int accept_object(object me, object obj){
	int ok;
	string meal;
	object entry;
	
	if (REWARD_D->riddle_check(me,"ɽ�亣ζ")!=1 
		&& !REWARD_D->check_m_success(me,"ɽ�亣ζ")) {
		command("say ����ʲô��������ֻ�չ��ϰ�Ҫ�Ĳˡ�");
		return 0;
	}
	
	switch (obj->query("name"))	{
		case "��ɽ����":		tell_object(me,"���˵�����������ϺõĿ�ɽ���⣡\n");
								meal = __DIR__"obj/entry1";
								ok = 1; 
								break;
		case "����":			tell_object(me,"���˵�����Ƶ�����ģ�������֪���Ѿ����˶������ˣ������ˡ�\n");
								break;
		case YEL"����"NOR:		
								if (!obj->query("winter"))
								{
									tell_object(me,"���˵����������ô����СС��צ�������ܹ����ˡ�\n");
								} else {
									tell_object(me,"���˵�����������Ϻõ����ƣ�\n");
									meal = __DIR__"obj/entry3";
									ok = 2;
								}
								break;
		case "Сɽȸ��":		tell_object(me,"���˵���������ִ���Ӳ����Ѽ�ӵİɣ�\n");
								break;
		case "��������":		tell_object(me,"���˵��������ϸ���ۣ��Ϻõ����࣡\n");
								meal = __DIR__"obj/entry2";
								ok = 3;
								break;
		}
		
		if (!ok)	return 0;
		
		tell_object(me, YEL"�������ת����̨ǰæ���ˣ�һ�ٷ��Ĺ����˳������Ӹ��㡣
���˵����ȥ�����ϰ��������㣡\n"NOR); 
		
		entry= new(meal);
		if (!entry) {
			command("say OOPS, BUGS!");
			return 0;
		}
		
		entry->move(me);
		return 1;
		
}